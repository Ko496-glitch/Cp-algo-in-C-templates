#include<new>
#include<utility>
#include<type_traits>
#include<functional>
#include "std::optional.hpp"
#include "lib::type_trait.hpp"
#include "forward.hpp"

//lib::type_trait.hpp test-----------------------------


// lib::is_eq_comparable_v tests;
static_assert(lib::is_eq_comparable_v<int,int>);
static_assert(!lib::is_eq_comparable_v<int, void>);
static_assert(lib::is_eq_comparable_v<int, bool>);
static_assert(!lib::is_eq_comparable_v<int,void*>);

//lib::nullopt_t tests
static_assert(!std::is_void_v<lib::nullopt_t>);
static_assert(!std::is_convertible_v<lib::nullopt_t,int>);
static_assert(std::is_constructible_v<lib::nullopt_t,int>);
static_assert(std::is_same_v<std::add_pointer_t<lib::nullopt_t>,lib::nullopt_t*>);
static_assert(std::is_literal_type_v<lib::nullopt_t>);


//::move tests


static_assert(is_lvalue_reference_v<::move<)


#if 0
std::optional
1) iterators
2) Monadic operations
3) Modifers :
#endif


int main(){




  int num = 10;
  vector<int>a{::forward(num),false};
  vector<int> b = ::move(a);
  std::cout << b.size() << a.size() << std::endl;
  return 0;
}
