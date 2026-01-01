#include<new>
#include<type_trait>
#include<vector>
#include<utility>
#include<cassert>
#include "lib::type_trait.hpp"

namespace lib{

  template<typename T,std::size_t capacity = 1026, typename buffer_policy, template Container = std::array<T,capacity>>
  class ring_buffer{
    private:
      std::size_t head_; // pointer index to index that will be removed
      std::size_t tail_; // pointer index to free slot
      std::size_t size_; // current size of the array we will use
      Container storage_; // default is set to std::array

    public:
      constexpr ring_buffer()noexcept : head_(0),tail_(0),size_(0){}
      constexpr std::size_t size()const noexcept();
      constexpr std::size_t capacity() const noexcept();
      constexpr bool empty() const noexcept();
      constexpr bool full() const noexcept();
      

      /* 0 <= size <= capacity
       * tail_ = (head + size_) % capacity;
  
       */
  };

}

