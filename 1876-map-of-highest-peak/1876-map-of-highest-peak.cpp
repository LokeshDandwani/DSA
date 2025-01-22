class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(); 
        int n = isWater[0].size(); 

        queue<pair<int, pair<int,int>>> q; 
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                if(isWater[i][j] == 1){
                    q.push({0,{i,j}}); 
                    isWater[i][j]=0; 
                    visited[i][j] = true;
                }
            }
        }

        vector<vector<int>> dir = {
          {1,0},
          {0,1},
          {-1,0},
          {0,-1}
        };


        while(!q.empty()){
            auto node = q.front(); 
            q.pop(); 
             int dist = node.first;
            
             int i= node.second.first; 
             int j= node.second.second; 
               
             for(auto d: dir){
                int newi = i+ d[0]; 
                int newj = j+d[1]; 

                if(newi < 0 || newi >= m || newj <0 || newj >=n || visited[newi][newj]   ){
                    continue; 
                }
               
                    isWater[newi][newj] = dist+1; 
                 visited[newi][newj] = true;
                    q.push({dist+1, {newi,newj}}); 
                
             }
        }
        return isWater; 
    }
};