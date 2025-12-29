#include<iostream>



template<typename t>
auto foo(t x){
  return x;
}
int main(){

  auto p = foo(10);
  std::cout << p << std::endl;
  return 0;
}
