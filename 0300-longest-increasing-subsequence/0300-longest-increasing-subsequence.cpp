class Solution {
public: 
     int dp[2501][2502]; 
     int solve(int i , vector<int> &nums, int prev){
        if(i == nums.size()){
            return 0; 
        }
        if(dp[i][prev+1] != -1){
            return dp[i][prev+1];
        }

        int take =0; 
        if( prev==-1 ||   nums[i] > nums[prev]){
            take = 1+solve(i+1, nums, i);
        }

        int nottake = solve(i+1, nums, prev); 

        return dp[i][prev+1] = max(take, nottake); 

     }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp)); 
        int n = nums.size(); 
            int prev = -1; 
         return solve(0,nums,prev); 
    }
};