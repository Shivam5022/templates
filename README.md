## KEEP IN MIND

1. For Ordered Set, use :

   ```c++
   #include <ext/pb_ds/assoc_container.hpp>
   using namespace __gnu_pbds;
   #define fbo find_by_order
   #define ook order_of_key
    
   template<typename T>
   using ordered_set = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
   
   // used as ordered_set<int>  S; 
   // S.insert(123);
   ```

   

2.  For random number generator: (add these two lines on top, range is [a, b] ) 

```c++
std::mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
```

3. Priority Queue Initialisation :

   ```c++
   template<class T> using pq = priority_queue<T>;
   template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
   ```

   

4. For accurate square root use : (credits : errichto)

   ```c++
   long long x = sqrtl(a) + 2;
   while (x * x > a) x--;
   ```

   

5. Grid cell (i, j) is uniquely mapped to (i + j * n) OR (j + i * m). Print the values.

6. Never use endl, unless in interactive problems. Always make a habit  of using '\n' for new line.

7. Rather than clearing globals before each test case, you can also do:

   ```c++
   // GLOBAL DECLARATION WITHOUT SIZE
   vector<vector<int>> adj;
   vector<vector<int>> up; 
   vector<int> tin, tout;
   vector<int> depth;
   
   // INSIDE MAIN ASSIGN SIZE:
   adj = vector<vector<int>> (n + 5);
   up = vector<vector<int>> (n + 5, vector<int>(24));
   tin = vector<int> (n + 5);
   tout = vector<int> (n + 5);
   depth = vector<int> (n + 5);
   ```

8. Can find some other templates at :

   https://github.com/the-hyp0cr1t3/CC/tree/master/%E6%9C%AB%20Snippet

   