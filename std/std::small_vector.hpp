#include<iostream>
#include<new>
#include<cassert>
#include<utility>
#include<type_traits>

template<typename T, std::size_t N>

class small_vector{
  private:
  std::size_t size_; // number of elements in vector.
  std::size_t capacity_; // max capacity which will decide the overflow. Cond -> size_ >= Capacity to keep it on stack;
  T* data_; // our data pointer which points  to memory of address.

  std::aligned_storage_t<sizeof(T), alignof(T)> inline_data[N]; 
  
  T* inline_buffer_()noexcept{
    return reinterpret_cast<T*>(inline_data);
  }  

  const T* inline_buffer_()const noexcept{
    return reinterpret_cast<const T*>(inline_data);
  }
  
  bool using_inline()const noexcept{
    return data_ == inline_buffer_();
  }

  void grow(){
    
    std::size_t new_capacity = capacity_*2;
    T* new_data_ = static_cast<T*>(::operator new(new_capacity *sizeof(T)));

    std::size_t i{0};
    
    try{
      for(;i<size_;++i){
        if constexpr(std::is_nothrow_move_constructible_v<T>){
          new(new_data_ +i) T(std::move(data_[i]));
        }else{
          new(new_data_ +i)T(data_[i]);
        }
      }
    }catch(...){
      for(std::size_t j{0};j<i;++j){
        new_data_[j].~T();
      }
      ::operator delete(new_data_);
      throw;
    }
    
   for(std::size_t i{0};i<size_;++i){
      data_[i].~T();
    }

    if(!using_inline()){
      ::operator delete(data_);
    }
    capacity_ = new_capacity;
    data_ = new_data_;

  }

  public:
  
  void clear(){ // func that our destructor will based on for cleaning.
    if constexpr(!std::is_trivially_destructible_v<T>){
      for(std::size_t i{0};i < size_;++i){
        data_[i].~T();
      }
    }
    size_ = 0;
  }

  small_vector():size_(0), capacity_(N),data_(inline_buffer_()){}
  
  ~small_vector(){ // calling the destrutor, this will work when we insert the placement new object in raw buffer.
    clear();
    if(!using_inline())::operator delete(data_);
  }
  void push_back(const T& value)noexcept(std::is_nothrow_copy_constructible_v<T>){
   
    if(size_ == capacity_){
      grow();
    }
    new(data_ + size_)T(value); 
    size_++;

    }

  void push_back(T&& value)noexcept(std::is_nothrow_move_constructible_v<T>){
    
    if(size_ == capacity_)grow();
    new(data_ + size_)T(std::move(value));
    size_++;
  }
  
  
  template<typename...Args>
  T& emplace_back(Args&&...Ts)noexcept(std::is_nothrow_constructible_v<T, Args&&...>){
    if(size_ == capacity_)grow();

    T*ptr =  new(data_+ size_)T(std::forward<Args>(Ts)...);
    ++size_;
    return *ptr;
  }
    

  // Accessors ---------------------------------------------------------------------------------------------------

  std::size_t size()const noexcept{
    return size_;
  }

  std::size_t capacity()const noexcept{
    return capacity_;
  }
  
  bool empty()const noexcept{
    return (size_ == 0);
  }   
  
  const T* data()const noexcept{
    return data_;
  }
  
  T* data()noexcept{
    return data_;
  }

  T& operator[](std::size_t index)noexcept{
    return data_[index];
  }
  
  const T& operator[](std::size_t index)const noexcept{
    return data_[index];
  }
  // Constructor (Copy and move) ------------------------------------------------------------

  small_vector(const small_vector& other):size_(0),capacity_(N), data_(inline_buffer_()){
    if(other.size_ > N){
      
      capacity_ = other.size_;
      data_ = static_cast<T*>(::operator new(sizeof(T)* capacity_));
    }
    std::size_t i{0};
    
    try{
      for(;i < other.size_;++i){
        new(data_+ i)T(other.data_[i]);
      }
      size_  = other.size_;
    }catch(...){
      for(std::size_t j{0}; j<i;++j){
        data_[j].~T();
      }
      if(data_ != inline_buffer_()){
        ::operator delete(data_);
        }
        throw;
      }
    }
    small_vector(small_vector&& other)noexcept:size_(other.size_),capacity_(other.capacity_),data_(other.data_){
      
      if(other.using_inline()){
        data_ = inline_buffer_();
        for(std::size_t i{0};i<size_;++i){
          new(data_ +i)T(std::move(other.data_[i]));
          other.data_[i].~T();
        }
      }
      other.size_ = 0;
      other.capacity_ = N;
      other.data_ = other.inline_buffer_();
    }

    small_vector& operator=(small_vector&&other)noexcept{
      if(this == &other)return *this;
        
      for(std::size_t i{0};i<size_;++i){
        data_[i].~T();
      }
      
      if(!using_inline()){
        ::operator delete(data_);
      }


      size_ = other.size_;
      capacity_ = other.capacity_;
      data_ = other.data_;

      if(other.using_inline()){
        data_ = inline_buffer_();
        for(std::size_t i{0};i< size_;++i){
          new(data_ +i)T(std::move(other.data_[i]));
          other.data_[i].~T();
        }
      }
      other.size_ = 0;
      other.capacity_ = N;
      other.data_ = inline_buffer_();
      return *this;
    }
  };
