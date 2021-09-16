class Solution {
public:
    string longestPalindrome(string s) {
        
        //edge case:
        if(s.size() == 0) 
            return "";
        
        int n = s.size();
        
        // int table[n][n];
        
        // memset(table,-1,sizeof(table)); //Initializing table with -1
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; i++) 
            dp[i][i] = 1;  //Filling up the table
        
        int maxLen = 1;
        int start = 0; 
        
        for (int i = 0; i < n - 1; i++) { //checking for substring of length 2.
            if (s[i] == s[i + 1]) { 
                dp[i][i + 1] = 1; 
                start = i;  //Updating the start
                maxLen = 2; 
            } 
        }
        
        //Checking for length greater than 2 and k is length of substring 
        for(int k=3;k<=n;k++){ 
            for(int i = 0; i < n - k + 1; i++){
                
                int j = i + k - 1; //Initializing the end Index i.e j = i + k - 1
                
                if(dp[i+1][j-1] == 1 && s[i] == s[j]){ //Checking for the conditions 
                    dp[i][j] = 1;
                    
                    //Updating the maxLen
                    if (k > maxLen) { 
                        start = i;  //Updating the start
                        maxLen = k; 
                    } 
                }
            }
        }
        return s.substr(start, maxLen);
    }
};