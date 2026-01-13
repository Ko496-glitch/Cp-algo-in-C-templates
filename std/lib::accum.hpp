#include<new>
#include<utility>
#include<cassert>
#include<string>


template<typename T>
struct AccumTrait;

template<>
struct AccumTrait<int>{
  using AccT = long long;
  static constexpr AccT zero(){ 
    return AccT{0};
  } 
};

template<>
struct AccumTrait<char>{
  using AccT = int;
  static constexpr AccT zero(){
    return AccT{0};
  }
};

template<>
struct AccumTrait<short>{
  using AccT = int;
  static constexpr AccT zero(){
    return AccT{0};
  }
};

template<>
struct AccumTrait<unsigned int>{
  using AccT = unsigned int;
  static constexpr AccT zero(){
    return AccT{0};
  }
};

template<>
struct AccumTrait<std::string>{ 
  using AccT = std::string;
  static AccT zero(){
    return AccT{""};
  }
};



