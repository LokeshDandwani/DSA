class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = nums[0]; 
        int sum = nums[0]; 
        int n = nums.size(); 
        
        for(int i =1; i<n; i++){
            if(nums[i]> nums[i-1]){
                sum+= nums[i]; 
                maxSum = max(sum, maxSum); 
            }else{
                sum = nums[i]; 
            }
        }
        return maxSum; 
    }
};