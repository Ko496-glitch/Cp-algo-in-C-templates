#pragma once
#include<new>
#include<utility>
#include "lib::advance.hpp"



namespace lib{


  struct MyInputIter{
    using iterator_category = input_iterator_tag;
    using value_type = int;
    using difference_type = std::ptrdiff_t;
    using pointer = int*;
    using reference = int&; 
    int *ptr;
    MyInputerIter(int*p): ptr(p){}

    MyInputIter operator++(){
      ++ptr;
      return *this;
    }
  };

  struct Mybidirectional{

    using iterator_category = bidirectional_iterator_tag;
    using value_type = int;
    using difference_type = std::ptrdiff_t;
    using pointer = int*
    using reference = int&;
    
    int *ptr;
    MyBidirectional(int*p): ptr(p){}
    Mybirectional++(){
      ++ptr;
      return *this;
    }

    Mybidirectional--(){
      --ptr;
      return this;
    }

    
  };

  struct Myrandom_access{

    using iterator_category = random_access_tag;
    using value_type = int;
    using difference_type = std::ptrdiff_t;
    using pointer = int*;
    using reference = int&;
    
    int *ptr;
    Myrandom_access(int*p): ptr(p){}
    Myrandom_access++(){
      ++ptr;
      return *this;
    }

    Myrandom_access--(){
      --ptr;
      return this;
    }

    Myrandom_access+=(difference_type){
      ptr += difference_type;
      return *this;
    }

    Myrandom_access -=(difference_type){
      ptr-= difference_type;
      return *this;
    }
  };
}
