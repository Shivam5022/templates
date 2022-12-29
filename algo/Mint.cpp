// this one is from jiangly (Z struct)
// can be used with int = long long too

const int32_t mod = 1E9 + 7;

int norm(int x) {
  if (x < 0) {
    x += mod;
  }
  if (x >= mod) {
    x -= mod;
  }
  return x;
}
template<class T>
T power(T a, long long b) {
  T res = 1;
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
    res *= a;
    }
  }
  return res;
}
struct Z {
  int x;
  Z(int x = 0) : x(norm(x)) {}
  // Z(long long x) : x(norm(x % mod)) {}   // uncomment when there is no int = ll
  int val() const {
    return x;
  }
  Z operator-() const {
    return Z(norm(mod - x));
  }
  Z inv() const {
    assert(x != 0);
    return power(*this, mod - 2);
  }
  Z &operator*=(const Z &rhs) {
    x = (long long) x * rhs.x % mod;
    return *this;
  }
  Z &operator+=(const Z &rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  Z &operator-=(const Z &rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  Z &operator/=(const Z &rhs) {
    return *this *= rhs.inv();
  }
  friend Z operator*(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res *= rhs;
    return res;
  }
  friend Z operator+(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res += rhs;
    return res;
  }
  friend Z operator-(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res -= rhs;
    return res;
  }
  friend Z operator/(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res /= rhs;
    return res;
  }
  friend std::istream &operator>>(std::istream &is, Z &a) {
    long long v;
    is >> v;
    a = Z(v);
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os, const Z &a) {
    return os << a.val();
  }
};

/////////////////////////////////////////////////////////////////////////////////
// use 'long long' properly this time, don't define int as long long.
// when using Mint, try explicitly using long long for all variables.

const int mod = 1E9 + 7;
// const int mod = 998244353;
class Mint {
public:
  long long x;
  Mint(long long v = 0) {
    if(v < 0) v = v % mod + mod;
    if(v >= mod) v = v % mod;
    x = v;
  }
  Mint(int v) : Mint((long long)v) {}
  Mint pow(long long b) const {
    if(b < 0) return inv().pow(-b);
    Mint a = *this;
    Mint res = 1;
    while(b > 0) {
      if(b & 1) res *= a;
      a *= a;
      b >>= 1ll;
    }
    return res;
  }
  Mint inv() const { return pow(mod - 2); }

  explicit operator int() const { return x; }
  explicit operator long long() const { return x; }
  explicit operator bool() const { return x; }

  Mint& operator+= (const Mint& other) {
    x += other.x;
    if(x >= mod) x -= mod;
    return *this;
  }
  Mint& operator-= (const Mint& other) {
    x -= other.x;
    if(x < 0) x += mod;
    return *this;
  }
  Mint& operator*= (const Mint& other) {
    x *= other.x;
    x %= mod;
    return *this;
  }
  Mint& operator/= (const Mint& other) {
    return *this *= other.inv();
  }
  Mint& operator++() {
    return *this += 1;
  }
  Mint& operator--() {
    return *this -= 1;
  }
  // https://www.cs.odu.edu/~zeil/cs333/f13/Public/faq/faq-htmlsu23.html
  Mint operator++(int) {
    Mint before = *this;
    ++*this;
    return before;
  }
  Mint operator--(int) {
    Mint before = *this;
    --*this;
    return before;
  }
  Mint operator-() const {
    return x == 0 ? 0 : mod - x;
  }
  friend Mint operator+ (const Mint& a, const Mint& b) {
    return Mint(a) += b;
    // why not just a += b?
  }
  friend Mint operator- (const Mint& a, const Mint& b) { return Mint(a) -= b; }
  friend Mint operator* (const Mint& a, const Mint& b) { return Mint(a) *= b; }
  friend Mint operator/ (const Mint& a, const Mint& b) { return Mint(a) /= b; }

  friend bool operator== (const Mint& a, const Mint& b) { return a.x == b.x; }
  friend bool operator!= (const Mint& a, const Mint& b) { return a.x != b.x; }
  friend bool operator< (const Mint& a, const Mint& b) { return a.x < b.x; }
  friend bool operator> (const Mint& a, const Mint& b) { return a.x > b.x; }
  friend bool operator<= (const Mint& a, const Mint& b) { return a.x <= b.x; }
  friend bool operator>= (const Mint& a, const Mint& b) { return a.x >= b.x; }

  friend ostream& operator<<(ostream& os, const Mint& m) { return os << m.x; }
  friend istream& operator>>(istream& is, Mint& m) { return is >> m.x; }
};
