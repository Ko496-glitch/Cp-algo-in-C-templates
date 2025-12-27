#pragma once
#include<iostream>
#include<utility>
#include<new>
#include<type_traits>

template<typename T>
class optional{
  std::aligned_storage_t<sizeof(T), alignof(T)> storage;
    // storage here will be our array for current object slot space.
  bool engaged;// Flag for either we have a value or not;
  
  T *ptr()noexcept{
    return reinterpret_cast<T*>(storage);
  }

  const T* ptr()const noexcept{
    return reinterpret_cast<const T*>(storage);
  }
  
  public:
  
  void clear(){
    if(this->engaged){
      ptr()->~T();
      this->engaged = false;
    }
  }

  optional() noexcept : engaged(false){}//default constructor
  
  ~optional(){
    clear();   
  }


  // Copy Constructor --- ----------------------------------
  template<typename U = T, typename =  std::enable_if_t<std::is_copy_constructible_v<U>>>
  optional(const optional& other) noexcept : engaged(false){
    if(other.engaged){
      new (storage)T(*other.storage);
      this->engaged = true;
    }
  }

  //Move Constructor ----------------------------------------
  template<typename U = T, typename = std::enable_if_t<std::is_move_constructible_v<U>>>
  optional(optional&& other) noexcept : engaged(false){
    if(other.engaged){
      this->engaged = true;
      new(storage)T(std::move(*other.ptr()));
      other.engaged = false;
    }
  }


  // Copy operator= ------------------------------------------------------------------------
  optional operator=(const optional& other)noexcept{
    if(this == &other)return *this;


    if(this->engaged && other.engaged){
      *this->ptr() = *other.ptr();
    }

    else if(!this->engaged && other.engaged){
      new(&storage)T(*other.ptr());
    }

    else if(this->engaged && !other.engaged){
      clear();
    }

    else{
      return *this;
    }
  }
 
  //Move operator= --------------------------------------------------------------------------
  optional & operator=(optional&& other)noexcept(std::is_nothrow_move_constructible_v<T> && std::is_nothrow_move_assignable_v<T>){

    if(this == &other)return *this;
    
    if(this->engaged && other.engaged){
      *this->ptr() = std::move(*other.ptr());
      other.clear();
    }
    
    else if(this->engaged && !other.engaged){
      this->clear();
    }
    
    else if(!this->engaged && !other.engaged){
      return *this;
    }

    else{
      new(&storage)T(std::move(*other.ptr()));
      this->engaged = true;
      other.clear();
    }
    return *this;
  }




  // Observers -----------------------------------------
  bool has_value()const noexcept{
    return this->engaged;
  }

  explicit operator bool()const noexcept{
    return this->engaged;
  }
  
  T& operator*()noexcept {
    return *this->ptr();
  }
  
  const T& operator*() const noexcept {
    return *this->ptr();
  }

  T* operator->() noexcept {
    return this->ptr();
  }

  const T* operator->() const noexcept {
    return this->ptr();
  } 




   
};




