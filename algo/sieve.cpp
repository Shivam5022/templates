// use this till N around 1E7
// O(n * log(log(n)))
// number of primes less than N are around (N / log(N))
// can be checked using primes.size()

#define SIEVE   
int is_prime[N];
vector<int> primes;
int spf[N];
void sieve() {
    for(int i = 1; i < N; i++) {
        spf[i] = i;
    }
    for(int i = 2; i < N; i++) {
        if (is_prime[i] == 0) {
            primes.push_back(i);
            for(auto j = 1ll * i * i ; j < N ; j += i){
                is_prime[j] = 1;
                if (spf[j] == j) spf[j] = i;
            }
        }
        is_prime[i] ^= 1;
    }
}
vector<int> factorise(int n){  // O(logN) , works till n ranging 1e7.
    vector<int> ans;
    while(n != 1){
        ans.push_back(spf[n]);
        n = n / spf[n];
    }
    return ans;     // ans vector is always sorted.
}

auto primeFactors = [&] (int n) {    //O (sqrtN)
    std::vector<int> factors;
    for (int i = 2; i * i <= n; i++) { 
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }
    if (n > 2) factors.push_back(n); // if n is a prime greater than 2  
    return factors;  
};