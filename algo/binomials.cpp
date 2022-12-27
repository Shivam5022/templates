//////////////////////////////////////////////////////////////////////////
#define NCR
int fact[N],invfact[N];

void init() {
   int p = mod;   //should be prime
   fact[0] = 1;
   int i;
   for(i = 1 ; i < N ; i++){
      fact[i] = i * fact[i-1] % p;
   }
   i--;
   invfact[i] = bpow(fact[i] , p - 2);
   for(i-- ; i >= 0 ; i--){
      invfact[i] = invfact[i+1] * (i+1) % p;
   }
}

//if m is prime, inverse of b under mod m is bpow(b, m-2, m);

int ncr(int n , int r) {   
   if(r > n || n < 0 || r < 0)return 0;
   return fact[n] * invfact[r] % mod * invfact[n-r] % mod;
} 


///////////////////////////////////////////////////////////////////////////

struct Binomials {
  int N, mod;
  std::vector<int> fact, invfact;
  Binomials (int n) : N(n) {
    fact.resize(N + 5);
    invfact.resize(N + 5);
    mod = 1E9 + 7;
    int p = mod;   //should be prime
    fact[0] = 1;
    int i;
    for(i = 1 ; i < N ; i++){
      fact[i] = i * fact[i-1] % p;
    }
    i--;
    invfact[i] = bpow(fact[i] , p - 2);
    for(i-- ; i >= 0 ; i--){
      invfact[i] = invfact[i+1] * (i+1) % p;
    }
  }
  int ncr(int n , int r) {   
    if(r > n || n < 0 || r < 0)return 0;
    return fact[n] * invfact[r] % mod * invfact[n-r] % mod;
  }
};

/////////////////////////////////////////////////////////////////////////////
