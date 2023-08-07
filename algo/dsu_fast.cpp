
#define DISJOINT_SET_UNION
struct DSU {
    std::vector<int> parent , siz;
    DSU(int n){
      parent.resize(n + 1); 
      siz.resize(n + 1);
      for(int i = 0; i < n + 1; i++) {
         parent[i] = i; 
         siz[i] = 1;
      }
    }
    int leader (int i) {
      if(parent[parent[i]] != parent[i]) {
         parent[i] = leader(parent[i]);
      }
      return parent[i];
    }
    bool same (int x, int y) { 
      return leader(x) == leader(y); 
    }
    bool merge (int a, int b) {
      a = leader(a), b = leader(b);
      if(a == b) return false;
      if(siz[b] >= siz[a]) swap(a, b);
      siz[a] += siz[b];
      parent[b] = a;
      return true;
    }
    int size(int x) { 
      return siz[leader(x)]; 
    }
};
