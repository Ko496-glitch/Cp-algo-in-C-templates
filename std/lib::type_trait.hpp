#include<new>
#include<type_traits>
#include<utility>

namespace lib{
template<typename T,typename U, typename = void>
struct is_eq_comparable: std::false_type{};

template<typename T, typename U>
struct is_eq_comparable<T,U, std::void_t<decltype(declval<T>() == declval<U>())>>: std::true_type {};

template<typename T,typename U>
inline constexpr  bool is_eq_comparable_v = is_eq_comparable<T,U>::value;



struct nullopt_t{
  explicit  constexpr  nullopt_t(int){}
};

inline constexpr nullopt_t null_opt{0};


template<typename T>
class optional;


template<typename T>
struct is_optional: std::false_type{};


template<typename U>
struct is_optional<optional<U>>: std::true_type{};


template<typename T>
inline constexpr bool is_optional_v = is_optional<T>::value;



#if 0
 Predicate traits 
#endif
  template<typename T1, typename T2>
    class is_same_t{
      public:
        static constexpr bool value = false;
    };
  
  template<typename T>
    class is_same_t<T,T>{
      public:
        static constexpr bool value = true;
    };

  template<typename T1,typename T2, typename ...T3>
    class is_same_all{
      public:
        static constexpr bool value = is_same_t<T1,T2>::value && is_same_t<T2,Rest...>::value;
    };  

    template<typename T>
    using IsSame = typename is_same_t<T>::type;
    
    template<typename T1, typename T2,typename... T3>
    using IsSmallAll = typename is_same_all<T1,T2,T3>::type;

#if 0
  Transformation traits
#endif

    template<typename T>

    template<typename T&>
      struct remove_reference{
        using type = T;
      };

    template<typename T&&>
      struct remove_reference{
        using type = T;
      };
     //add reference  
    template<typename T>
      struct add_lreference{
        using type = T&;
      };
    
    template<typename T>
      struct add_rreference{
        using type = T&&;
      };
    
    
    template<typename T>
    using LvalueRef = typename add_lreference<T>::type;
    template<typename T>
    using RvalueRef = typename add_rreference<T>::type;



}


