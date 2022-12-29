struct SGT {   //segtree implementation by geothermal
  std::vector<int> seg; 
  int SZ;
  SGT() {};
  int combine (int a, int b) { return max(a, b); } // change to sum, max, min
  void build (vector<int> val) {
    SZ = (int) val.size();
    seg.resize(2 * SZ + 1); // put identity here
    for(int i = SZ; i < 2 * SZ; ++i) {
      seg[i] = val[i - SZ];
    }
    for(int i = SZ - 1; i > 0; --i) seg[i] = combine(seg[i << 1], seg[(i << 1) | 1]); 
  }
  void update (int p, int v) {
    p += SZ; seg[p] = v;  // for ADDING to point, seg[p] += v & for SETTING, seg[p] = v.
    for(int i = p; i > 1; i >>= 1) seg[i >> 1] = combine(seg[i], seg[i ^ 1]); 
  }
  int get (int idx) {
    return seg[idx + SZ];
  }
  int query (int l, int r) {
    int ans = 0;  // set this to identity
    if (l > r) return ans;
    l = max(0LL, l);
    r = min(SZ - 1, r);
    for(l += SZ, r += SZ + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans = combine(ans, seg[l++]); 
      if (r & 1) ans = combine(ans, seg[--r]);  
    }
    return ans;
  }
};