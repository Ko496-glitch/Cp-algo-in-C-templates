#include<iostream>
#include<utility>
#include<type_traits>
#include<cassert>

template<typename T>
constexpr T&& forward(std::remove_reference_t<T>& x)noexcept{
  return static_cast<T&&>(x);
}

template<typename T>
constexpr T&& forward(std::remove_reference_t<T>&&x)noexcept{
  static_assert(!std::is_lvalue_reference_v<T>,"lvalue reference to rvalue");
  return static_cast<T&&>(x);
}
