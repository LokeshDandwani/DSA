class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        bool hasFresh = false;
           queue<pair<pair<int,int>,int>> q; 
          for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0}); 
                }if (grid[i][j] == 1) {
                    hasFresh = true; 
                }
            }
          }
           if (!hasFresh) return 0;
          int days=0; 
          vector<vector<int>> dir = {
            {1,0},
            {0,1}, 
            {-1,0}, 
            {0,-1}
          }; 


          while(!q.empty()){
            auto node = q.front(); 
            int i = node.first.first; 
            int j = node.first.second; 
            int time = node.second; 
            days= max(days,time); 

                  q.pop(); 

                  for(auto d: dir){
                      int newi = i+ d[0]; 
                      int newj = j+ d[1]; 
                      if(newi<0 || newi>=n || newj<0|| newj>=m || grid[newi][newj]!=1)continue; 
                       grid[newi][newj]=2; 
                       q.push({{newi,newj}, time+1}); 
                  }
          }
          for(int i =0; i<n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == 1){
                    return -1; 
                }
            }
          }
          return days; 
          
          
    }
};