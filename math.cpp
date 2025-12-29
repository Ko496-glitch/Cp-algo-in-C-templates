#include<iostream>
#include"stdc++.h"
using namespace std;

using ll = long long;

#if 0
Sieve Implementation in Templates, later will optimize it to constexpr to save compile computation
#endif

template<typename t = ll,typename container = std::vector<bool>>

constexpr container sieve(t n){
  ll count = 0;
  container is_prime(n+1 ,true);
  if(n >= 0)is_prime[0] = false;count++;
  if(n>=1)is_prime[1] = false;count++;
  

  for(t i{2};i*i<=n;i++){
    if(is_prime[i]){
      for(t j{i*i};j<=n;j+=i){
        is_prime[j] = false;
        count++;
      }
    }
  }
  return is_prime;
}

template<typename T,typename container = std::vector<ll>
constexpr auto extract_prime(T N){
  container prime = sieve<N>;

  for(std::size_t i{0};i<prime.size();++i){
    
  }
  return {prime,cnt};
} 


#if 0
This will count the number of prime factors for a given num;
#endif

template<typename T>
constexpr ll numpf(T num){
    
  ll count = 0;
  auto num = sieve<T>
  for(T i{0};i<(ll)is_prime.size() && is_prime[i] * is_prime[i];++i){
    while(num % is_prime[i] == 0){
      num/= is_prime[i];
      count++;
    }
  }
  return count;  
}

template<typename T>
constexpr ll numDiv(T num){
  ll power = 1;
  std::vector<std::size_t> prime = sieve<T>(N);
  for(std::size_t i{0};i<prime.size();&& prime[i] * prime[i];++i){
    ll count = 0;
    while(){
      num/=prime[i];
      count++;
    }
    power *= (count +1);
  }
  return power;
}


template<typename T>
constexpr std::size_t sumDiv(T num){
  std::size_t ans = 1;

  std::vector<T>  p = sieve<T>(num);
  for(std::size_t i{0};i<p.size()&& p[i]*p[i];++i){
    std::size_t mul = 1;
    std::size_t total = 1;

    while(num % p[i]){
      mul*=p[i];
      total += mul;
    }
    ans *= total; 
  }
  return ans;
}





ll main(){
  long long n{};
  std::cout << "Please enter your n, Remeber we will traverse sqrt" << endl;
  cin >> n;
  using ll = decltype(n);
  auto p = sieve<ll>(n);

  for(ll i{2};i*i<=n;i++){
    if(p[i]){std::cout << i << std::endl;}
  }
  return 0;
}
