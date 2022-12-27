// if you are not typedefing int to long long
// then convert these functions to long long
// even when numbers are in int range.

const int32_t mod = 1E9 + 7;
// const int32_t mod = 998244353;

int bpow(int n , int x) {
  int res = 1;
  n = n % mod;
  while(x > 0) {
    if(x % 2 == 1) res = (res * n) % mod;
    n = (n * n) % mod;
    x /= 2;
  }
  return res; 
}

int modinverse (int a) {
  int m = mod, y = 0, x = 1;
  while (a > 1) {
    int q = a / m;
    int t = m;
    m = a % m;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += mod;
  return x;
}

int add(int a , int b) { a = a % mod; b = b % mod; return (a + b) % mod; } 
int sub(int a , int b) { a = a % mod; b = b % mod; return (a - b + mod) % mod; } 
int mul(int a , int b) { a = a % mod; b = b % mod; return ((a * b) % mod + mod) % mod; } 
int xdiv(int a , int b) { return mul(a, modinverse(b));}
