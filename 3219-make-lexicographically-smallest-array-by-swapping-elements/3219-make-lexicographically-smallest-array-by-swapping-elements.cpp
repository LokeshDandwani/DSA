class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n= nums.size(); 
        vector<int> temp = nums; 
        sort(begin(temp), end(temp)); 
        int gno = 0; 
        unordered_map<int,int> noToGroup; 
        unordered_map<int, list<int>> gToList; 
        noToGroup[temp[0]]= gno; 
        gToList[gno].push_back(temp[0]); 

        for(int i=1; i<n; i++){
            if(abs(temp[i]-temp[i-1]) > limit){
                gno++; 
            }
            noToGroup[temp[i]]= gno; 
            gToList[gno].push_back(temp[i]);
            
        } 
        vector<int> ans(n); 
        for(int i=0; i<n; i++){
            
            int num = nums[i]; 
            int group = noToGroup[num]; 

            int numtopush = *(gToList[group].begin()); 
            ans[i]= numtopush; 
            gToList[group].pop_front(); 
            
        } 
        return ans;

    }
};

