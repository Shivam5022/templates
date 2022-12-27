// iterative segment tree with only point update
struct SGT {
  std::vector<int> seg; // O based
  int n;
  SGT() {};
  void clear(){
    n = 0;
    seg.clear();
  }
  void build (vector<int> val) {
    n = (int) val.size();
    seg.resize(2 * n + 1);
    for(int i = n; i < 2 * n; ++i) {
      seg[i] = val[i - n];
    }
    for(int i = n - 1; i > 0; --i) seg[i] = (seg[i << 1] + seg[(i << 1) | 1]);  //1
  }
  void update (int p, int v) {
    p += n; seg[p] += v;  // for ADDING to point, seg[p] += v & for SETTING, seg[p] = v.
    for(int i = p; i > 1; i >>= 1) seg[i >> 1] = (seg[i] + seg[i ^ 1]);  //2
  }
  int query (int l, int r) {
    int ans = 0;  // set this to identity
    l = max(0, l);
    r = min(n - 1, r);
    for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans = (ans + seg[l++]);  //3
      if (r & 1) ans = (ans + seg[--r]);  //4
    }
    return ans;
  }
};