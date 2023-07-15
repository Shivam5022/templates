#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<typename T>
using O_S = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
template<typename T>
using O_MS = tree<T,  null_type,  less_equal<T>,  rb_tree_tag,  tree_order_statistics_node_update>;

template<typename T>
struct ordered_multiset {
  O_MS<T> s;
  void insert (T x) {
    s.insert(x);
  }
  bool exist (T x) {
    if((s.upper_bound(x)) == s.end()) {
      return 0;
    }
    return ((*s.upper_bound(x)) == x);
  }
  void erase (T x) {
    if (exist(x)) {
      s.erase(s.upper_bound(x));
    }
  }
  int firstIdx (T x) {
    if(!exist(x)) {
        return -1;
    }
    return (s.order_of_key(x));
  }
  T value (int idx) { 
    return (*s.find_by_order(idx));
  }
  int lastIdx (T x) { 
    if(!exist(x)){
        return -1;
    }
    if(value((int)s.size() - 1) == x){
        return (int)(s.size()) - 1;
    }
    return firstIdx(*s.lower_bound(x)) - 1;
  }
  int count(T x) { 
    if(!exist(x)) {
      return 0;
    }
    return lastIdx(x) - firstIdx(x) + 1;
  }
  int size () {
    return (int) s.size();
  }
  void clear() {
    s.clear();
  } 
  void print() {
    for (auto z: s) {
      cout << z << ' ';
    }
    cout << '\n';
  }
};

template<typename T>
struct ordered_set {
  O_S<T> s;
  void insert (T x) {
    s.insert(x);
  }
  bool exist (T x) {
    int f = s.order_of_key(x);
    if(f == (int) s.size()) {
      return 0;
    }
    return (value(f) == x);
  }
  void erase (T x) {
    if (exist(x)) {
      s.erase(x);
    }
  }
  T value (int idx) { 
    return (*s.find_by_order(idx));
  }
  int less (T x) { // how many elements strictly less than 'x'
    int f = s.order_of_key(x);
    return f;
  }
  int size () {
    return (int) s.size();
  }
  void clear() {
    s.clear();
  } 
  void print() {
    for (auto z: s) {
      cout << z << ' ';
    }
    cout << '\n';
  }
};

// use as 'ordered_set<int> s' inside main.