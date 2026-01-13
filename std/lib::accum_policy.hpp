#include<new>
#include<string> 
#include"lib::accum.hpp"


class SumPolicy{
  public:
    template<typename T1,typename T2>
    static void sum(const&T1 total, const&T2 value){
      total += value;
    }    
};

class MulPolicy{
  public:
    template<typename T1,typename T2>
      static void mul(const&T1 total, const& T2 value){
        total *= value;
      }
  };

class DivPolicy{
  public:
    template<typename T1,typename T2>
      static void div(const&T1 total,const&T2 value){
        if constexpr(value != 0){total /= value;}
      }
  };

class ExpPolicy{
  public:
    template<typename T1,typename T2>
      static void exp(const&T1 total, const&T2 value){
        total %= value;
      }
  };
