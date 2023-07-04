#define NCR
struct COMB {
  std::vector<long long> fact, invfact;
  int mod;
  void init(int N, int M) {
    mod = M;
    fact.assign(N + 5, 0);
    invfact.assign(N + 5, 0);
    int p = mod;   //should be prime
    fact[0] = 1;
    int i;
    for(i = 1 ; i < N ; i++){
      fact[i] = (1LL * i * fact[i-1]) % p;
    }
    i--;
    invfact[i] = bpow(fact[i] , p - 2);
    for(i-- ; i >= 0 ; i--){
      invfact[i] = (1LL * invfact[i+1] * (i+1)) % p;
    }
  }
  long long bpow(long long n , long long x) {
    long long res = 1;
    n = n % mod;
    while (x > 0) {
      if (x % 2 == 1) res = (res * n) % mod;
      n = (n * n) % mod;
      x /= 2;
    }
    return res; 
  }
  int ncr(int n , int r) {   
     if (r > n || n < 0 || r < 0) return 0;
     return fact[n] * invfact[r] % mod * invfact[n-r] % mod;
  }   
};
constexpr int mod = 1E9 + 7;
COMB q;
// q.init(N, mod); // inside main
