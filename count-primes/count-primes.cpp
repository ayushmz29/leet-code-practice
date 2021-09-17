class Solution {
public:
    int countPrimes(int n) {
        //corner cases
        if(n < 2){
            return 0; 
        }
        
        int ans = 0;
        vector<bool> sieve (n + 1, true);
        
        for(int i = 2; i * i <= n; i++){
            if(sieve[i] == true){
                for(int j = i * i; j <= n; j += i){
                    sieve[j] = false;
                }
            }
        }
        
        //check for primes(true values)
        for(int i = 1; i < n; i++){
            if(sieve[i] == true){
                ans++;
            }
        }
        return ans - 1;
    }
};