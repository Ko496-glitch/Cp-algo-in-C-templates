#pragma once
#include<new>
#include<utility>


//This  code is implementation of std::advance using tag dispatching and SFINAE.
//Author  - Kartik Ohlan
//C++17 (No concepts for SFINAE)

namespace lib{
  //input iterator = only goes forward
  template<typename Iterator,typename Distance>
    void advance_impl(Iterator it, Distance n , lib::input_interator_tag){
      while(n > 0){
        ++it;
        --n;
      }
    }
  // bidirectional_tag = goes both sides --/ ++
  template<typename Iterator,typename Distance>
    void advance_impl(Iterator it, Distance n, lib::bidirectional_tag){
      if(n>=0){
        while(n > 0) ++it;
      }else{
        while(n <0)--it;
      }
    }
  //  random_access iterator
  template<typename Iterator, typename Distance>
    void advance_impl(iterator it, Distance n, random_access_iterator_tag){
      it+=n;
    }

}
