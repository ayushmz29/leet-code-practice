class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        //defining the fast and slow pointers
        int fast = nums[0];
        int slow = nums[0];
        
        //create the cycle, create first coincide
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);
        
        
        //move the fast ptr to the first element after coincide
        fast = nums[0];
        
        //check for 2nd coincide, move both by 1 step
        while(fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        };
        
        //return the slow ptr or fast ptr (ans = coincided node)
        
        return fast;
    }
};