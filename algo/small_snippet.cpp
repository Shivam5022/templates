#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <utility>
#include <functional>
#include <ctime>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

#ifdef LOCAL
#define DEBUG
#include "debug/debug_2.h"
#else
#define dbg(x...)
#endif

#define int     long long
#define all(x)  x.begin(), x.end()
#define sz(x)   static_cast<int>((x).size())
 
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

void solve (int tid) {
   
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  cin >> tt;
  for (int i = 1; i <= tt; i++) {
      solve(i);
  }
  return 0;
}
