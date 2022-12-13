// use this one, when you want to print the actual sets. the head is the leader of the group, and 'next'
// gives the pointer to next element in this particular set.

//***********each element is identified by its LEADER (leader(element))
//only leader has correct value, don't use other values in the set ****************
//****LEADER CHANGES CONTINOUSLY , CALCULATE IT AGAIN AND AGAIN******

#define DISJOINT_SET_UNION
struct DSU {
    std::vector<int> parent , siz , aggr , last , next;
    DSU(int n){
     parent.resize(n + 1); siz.resize(n + 1); aggr.resize(n + 1);
     last.resize(n + 1); next.resize(n + 1);

     for(int i=0 ; i < n + 1 ; i++) {
         parent[i] = i; siz[i] = 1;
         next[i] = i; last[i] = i;
         aggr[i] = i;  // depends on situation
     }
    }
    int leader(int i){
      if(parent[parent[i]] != parent[i]) parent[i] = leader(parent[i]);
      return parent[i];
    }
    bool same(int x , int y) { return leader(x) == leader(y); }
    void merge(int a , int b){
      a = leader(a) , b = leader(b);
      if(a == b) return;
      if(siz[b] >= siz[a]) swap(a , b);
      //'a' is the larger set
      siz[a] += siz[b];
      parent[b] = a;
      aggr[a] = max(aggr[a],aggr[b]);  //for storing aggregates (here MAX) of the set

      int z = last[a];
      next[z] = b;
      last[a] = last[b];
      return;
    }
    int size(int x) { return siz[leader(x)]; }
};

