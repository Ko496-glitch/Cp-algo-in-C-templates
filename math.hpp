#include<bitset>
#include<utility>
#include<new>
#include<type_traits>

using ll = long long;

template<std::size_t num>

constexpr auto sieve(){
  std::bitset<num+1>primes;
  primes.set();
  ll cnt{0};  
  if(num>=0){primes[0] = 0;cnt++;}
  if(num>=1){primes[1] = 0;cnt++;}

  for(std::size_t i{2};i*i<=num;++i){
    if(primes[i]){
      cnt++;
      for(size_t j = i*i;j<=num;j+=i){
        primes[j] = 0;
      }
    }
  }
  return std::pair{cnt, std::move(primes)};
}

