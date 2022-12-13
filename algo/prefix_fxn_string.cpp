/* 
       - src : https://cp-algorithms.com/string/prefix-function.html
       - pi[i] = longest proper prefix of s[0....i] which is also a suffix of this substring.
       - for kmp we use (s + '#' + t)
*/
// made as lambda

auto prefix_function = [&] (string s) {  // works in O(N)
    int n = (int) s.size();
    vector<int> pi(n , 0);
    for(int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while(j > 0 and s[i] != s[j]) {
            j = pi[j - 1];
        }
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
};
   