// use only for O(1) range max/min/gcd queries.
// use segtree for rest of queries O(logN).
// add gcd query function when needed.

struct SparseTable {
    vector<vector<int>> table_max;
    vector<vector<int>> table_min;
    SparseTable(vector<int>& arr) {
        int n = (int) arr.size();
        int N1 = n + 5;
        int N2 = (int) log2(N1) + 2;
        table_max.assign(N1, vector<int>(N2));
        table_min.assign(N1, vector<int>(N2));
        for (int i = 0; i < n; i++) {
            table_max[i][0] = arr[i];
            table_min[i][0] = arr[i];
        }
        for (int j = 1 ; j <= log2(n) ; j++) {
            for (int i = 0 ; i <= n - (1 << j) ; i++) {
                table_max[i][j] = max( table_max[i][j - 1] , table_max[i + (1 << (j - 1))][j - 1] );
                table_min[i][j] = min( table_min[i][j - 1] , table_min[i + (1 << (j - 1))][j - 1] );
            }
        }
    }
 
   int amax(int L, int R) {
      int j = (int)log2(R - L + 1);
      return max(table_max[L][j], table_max[R - (1 << j) + 1][j]);
   }
   int amin(int L, int R) {
      int j = (int)log2(R - L + 1);
      return min(table_min[L][j], table_min[R - (1 << j) + 1][j]);
   }
};