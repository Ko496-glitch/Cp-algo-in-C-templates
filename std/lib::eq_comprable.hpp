#include<new>
#include<type_traits>
#include<utility>

std::namespace lib{
template<typename T,typename U, typename = void>
struct is_eq_comparable: std::false_type{};

template<typename T, typename U>
struct is_eq_comparable<T,U, std::void_t<decltype(declval<T>() == declval<U>())>>: std::true_type {};

}
