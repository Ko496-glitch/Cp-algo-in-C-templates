#include<iostream>
#include<stdc++.h>
using ll = long long;
using 128bit = __int128_t;

ll mod_mul(128bit a, 128bit  b, 128bit mod){
  return (128bit)a*b%mod;
}

ll pow_mod(ll a , ll b , ll mod){
  ll ans = 1;
  while(b >0){
    if(a & 1){
        res = mod_mul(a , b, mod);
    }
    b /= 2;
    a = mod_mul(a ,a , mod);
  }
  return res;
}

bool miller_test(ll a , ll d , ll n){
  ll x = pow_mod(a , d ,n);

  if(x == 1 || x == n-1)return true;
  while(d != n-1){
    x = mod_mul(a ,a , n);
    d <<=1;
    if(x == 1)return false;
    if(x == n-1)return true;
  
  }
  return false;
}


bool isPrime(ll n, int k = 10){
  if(n < 2)return false;
  if(n <= 3)return true;
  if(n%2 == 0)return false;


  ll d = n-1;
  while((d&1)==0){
    d>>=1;
  }
  for(int i{0};i<k;i++){
    ll a = 2 + rand()%(n -4);
    if(!miller_test(a ,d ,n)){
      return false;
    }
  }
  return true;
}



int main(){ 
  int test;
  cin>> test;
  while(test--){

  }

  return 0;
}
