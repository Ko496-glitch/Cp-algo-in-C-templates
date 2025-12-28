#include<new>
#include<type_traits>
#include<utility>
#include<new>

std::namespace lib{
template<typename T,typename U, typename = void>
struct is_eq_comparable: std::false_type{};

template<typename T, typename U>
struct is_eq_comparable<T,U, std::void_t<decltype(declval<T>() == declval<U>())>>: std::true_type {};


template<typename T>
struct is_optional_v: std::false_type{};


template<typename U>
struct is_optional_v<optional<U>>: std::true_type{};

template<typename U>
inline constexpr bool is_optional_v = is_optional<T>::value;
}


