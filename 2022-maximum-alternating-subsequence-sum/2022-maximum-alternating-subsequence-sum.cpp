class Solution {
public: 
    long long dp[100001][2]; 
    long long solve(int i, vector<int> &nums, bool taken){

            if(i== nums.size()){
                return 0; 
            }


            if(dp[i][taken]!= -1){
                return dp[i][taken];
            }

        long long take =0; 
        if(taken == false){
             take = nums[i]+solve(i+1,nums, !taken); 
        }else{
            take = -nums[i]+solve(i+1, nums, !taken);
        }
           
     
            
        

        long long nottake = solve(i+1, nums,taken); 
        return dp[i][taken] = max(take,nottake); 
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(dp, -1, sizeof(dp)); 
        int n = nums.size(); 
        bool taken =false; 
        return solve(0, nums,taken); 
    }
};