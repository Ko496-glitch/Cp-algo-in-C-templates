#pragma once
#include<new>
#include<utility>
#include<type_traits>
#include "lib::packet.hpp"
#include "lib::egress_buffer.hpp"

namespace lib{
  template<typename T, std::size_t N,typename Capacity_ = N ,typename Container = std::array(N,Capacity_)>
  class ingress_buffer{
  
  std::size_t tail_;
  std::size_t head_;
  std::size_t size_;
  
  Contaier storage_;
  
  T* ptr() noexcept{
    return reinterpret_cast<T>(storage_);
  }

  const T* ptr() const noexcept {
    return  reinterpret_cast<T>(this->storage_);
  }


    public:
  constexpr   ingress_buffer()noexcept : tail_(0), head_(0), size_(0){}
  
  void clear(){
    if(this->size_ != 0){
      ptr().~T();
    }
  }
  ~ingress_buffer(){
    this->clear();
  }
  
    constexpr std::size_t size()const noexcept{return t
     his->size_;}

    constexpr std::size_t capacity() const noexcept{return this->Capacity_;}
    constexpr bool empty() const noexcept{return this->size_ == 0;}             
    constexpr bool full() const noexcept{return this->size_ == this->Capacity_;}   

  bool push(T&& values){
    if(this->size_ == Capacity_){
      return false;
    }  
    storage_[tail_] = std::move(value);
    this->tail_ = (this->tail_ + 1)%this->Capacity_; 
    ++this->size_;
    return true;
  }

  void dscp_check(const ingress_port& port, package& ppt){
    if(!port.trust_dscp){
      ppt.meta.internal_dscp = port.default_dscp;
      return;
    }else{
      std::uint8_t top3 = (ppt.pkt.external_dscp >>5)&0b111;
      ppt.meta.internal_dscp =  top3;
    }
  
  } 

  };
}
