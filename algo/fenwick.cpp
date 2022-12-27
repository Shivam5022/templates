// use this as a black box as of now. not studied it deeply.
/*
fenwickTree ft(n + 1);
for (int i = 0; i < n; i++) {
  ft.update(i, v[i]);         // to build over an array
}
*/
struct fenwickTree{
  vector<int> ft;
  int n;
  fenwickTree(int x){
    n = x;
    ft.assign(n + 1, 0);
  }
  void update(int i, int val){
    while(i <= n){
        ft[i] += val;
        i += i & (-i);
    }
  }
  int answerUtil(int i){
    int sum = 0;
    while(i >= 1){
      sum += ft[i];
      i -= i & (-i);
    }
    return sum;
  }
  int query(int l, int r){
    return answerUtil(r) - answerUtil(l - 1);
  }
};