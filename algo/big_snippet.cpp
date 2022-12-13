#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define DEBUG
#include "debug/debug_2.h"
#else
#define dbg(x...)
#endif

#define int                      long long
#define rep(i,a,b)               for(auto i=a ; i<b ; i++)
#define pb                       push_back
#define all(V)                   V.begin(),V.end()
#define rall(V)                  V.rbegin(),V.rend()
#define uniq(V)                  (V).erase(unique(all(V)),(V).end())
#define ub                       upper_bound
#define lb                       lower_bound
#define ff                       first
#define ss                       second
#define sz(V)                    (int)((V).size())
#define ppc                    __builtin_popcount
#define ppcll                  __builtin_popcountll
#define endl                     "\n"

typedef vector<int> vi ;
typedef pair<int,int> pii ;

double PI  =   acos(-1);
int dx[8]  =   { -1, 0, 0, 1, -1, -1, 1, 1 };
int dy[8]  =   { 0, 1, -1, 0, -1, 1, -1, 1 };

const int32_t mod = 1e9+7;
const long long inf = 1e18;

int add(int a , int b) { a = a % mod; b = b % mod; return (a + b) % mod; } 
int sub(int a , int b) { a = a % mod; b = b % mod; return (a - b + mod) % mod; } 
int mul(int a , int b) { a = a % mod; b = b % mod; return ((a * b) % mod + mod) % mod; } 
int bpow(int n , int x) {
     int res=1;
     while(x > 0){
        if(x % 2 == 1) res = (res * n) % mod;
        n = (n * n) % mod;
        x /= 2;
     }
     return res;
}

const int N = 2e5+5;

void HomeLANDER() {
   
    
}
         
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    

    int tcSs=1;
    cin>>tcSs;
    while(tcSs--){
       HomeLANDER();
    }
    return 0;
}