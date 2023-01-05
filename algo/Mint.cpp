// credits: jiangly (Z struct)
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
struct Mint {
  int x;
  Mint(int x = 0) : x(norm(x)) {}
  // Mint(long long x) : x(norm(x % mod)) {}   // uncomment when there is no int = ll
  int val() const {
    return x;
  }
  Mint operator-() const {
    return Mint(norm(mod - x));
  }
  Mint inv() const {
    assert(x != 0);
    return power(*this, mod - 2);
  }
  Mint &operator*=(const Mint &rhs) {
    x = (long long) x * rhs.x % mod;
    return *this;
  }
  Mint &operator+=(const Mint &rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  Mint &operator-=(const Mint &rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  Mint &operator/=(const Mint &rhs) {
    return *this *= rhs.inv();
  }
  friend Mint operator*(const Mint &lhs, const Mint &rhs) {
    Mint res = lhs;
    res *= rhs;
    return res;
  }
  friend Mint operator+(const Mint &lhs, const Mint &rhs) {
    Mint res = lhs;
    res += rhs;
    return res;
  }
  friend Mint operator-(const Mint &lhs, const Mint &rhs) {
    Mint res = lhs;
    res -= rhs;
    return res;
  }
  friend Mint operator/(const Mint &lhs, const Mint &rhs) {
    Mint res = lhs;
    res /= rhs;
    return res;
  }
  friend std::istream &operator>>(std::istream &is, Mint &a) {
    long long v;
    is >> v;
    a = Mint(v);
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os, const Mint &a) {
    return os << a.val();
  }
};

std::vector<Mint> fact, invfact;
void Compute_facts (int N) {
  fact.resize(N + 5);
  invfact.resize(N + 5);
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = fact[i - 1] * i;
  }
  invfact[N] = fact[N].inv();
  for (int i = N; i > 0; i--) {
    invfact[i - 1] = invfact[i] * i;
  }
}

Mint ncr(int n, int r) {
  Mint ans = fact[n] * invfact[n - r] * invfact[r];
  return ans;
}

