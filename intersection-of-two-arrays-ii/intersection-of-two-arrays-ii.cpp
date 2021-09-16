class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        //we need to create the hash-map for shorter array
        if(nums1.size() > nums2.size()) 
            return intersect(nums2, nums1);
        
        vector<int> ans;
        
        unordered_map<int,int> map1;
        
        for(int num : nums1){
            map1[num]++;
        }
            
        
        for(int num : nums2) {
            if(map1[num] > 0) {
                map1[num]--;
                ans.push_back(num);
            }
        }
        return ans;
        
    }
};