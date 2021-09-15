class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it->second > 1){
                ans = it->first;
            }
        }
        
        return ans;
    }
};