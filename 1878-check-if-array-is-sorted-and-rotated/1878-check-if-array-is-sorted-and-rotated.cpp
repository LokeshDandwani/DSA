class Solution {
public:
    bool check(vector<int>& nums) {
        int peak=0; 
        int n = nums.size(); 
       for(int i =0; i<nums.size(); i++){
        if(nums[i]>nums[(i+1)%n]){
            peak++; 
        }
       }
       if(peak>1){return false; }
       return true; 
    }
};