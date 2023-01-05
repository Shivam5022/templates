// credits : demoraliser
// look where to declare b1, b2. declare inside main for same hashing among all structs (IMP)
// sample submission : https://codeforces.com/contest/271/submission/175524714

struct Hash {   
    int n;
    int b1, b2;
    vector<int> pb1, pb2;
    vector<int> pre_1, pre_2;
    int MOD1, MOD2;

    Hash(string s, int _mod1 = 101777101, int _mod2 = 999999929) {
        n = (int) s.size();
        std::mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        auto dist=uniform_int_distribution<int>(1000,5000);
        b1 = dist(rng);
        b2 = dist(rng);
        
        MOD1 = _mod1 , MOD2 = _mod2;
        pb1.assign(n + 1, 0); pb2.assign(n + 1, 0);
        pre_1.assign(n + 1, 0); pre_2.assign(n + 1, 0);  

        pb1[0] = pb2[0] = 1;
        for(int i = 1; i < n + 1; i++) {
            pb1[i] = pb1[i-1] * 1ll * b1 % MOD1;
            pb2[i] = pb2[i-1] * 1ll * b2 % MOD2;
        }
        
        for(int i = 1; i < n + 1; i++) {
            pre_1[i] = (pre_1[i - 1] + s[i - 1] * 1ll * pb1[i - 1]) % MOD1;
            pre_2[i] = (pre_2[i - 1] + s[i - 1] * 1ll * pb2[i - 1]) % MOD2;
        }
    }

    pair<int,int> code (int l, int r) {   // [l, r] included end
        int H1 = (pre_1[r + 1] + MOD1 - pre_1[l]) * 1ll * pb1[n - r] % MOD1;
        int H2 = (pre_2[r + 1] + MOD2 - pre_2[l]) * 1ll * pb2[n - r] % MOD2;
        return {H1, H2};
    }
};