class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); 
        unordered_map<int,int> mpp; 
        mpp[0]=1; 
        int count=0; 
        int sum =0; 
        for(int i=0; i<n; i++){
            sum+= nums[i]; 
            
            if(mpp.find(sum-k) != mpp.end()){
                count+= mpp[sum-k]; 
            }
            mpp[sum]++; 
        }
        return count; 
    }
};