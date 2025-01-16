class Solution {
public :
      int solve(int i, int j, int currGold, vector<vector<int>> &grid){
int n = grid.size(); 
          int m = grid[0].size(); 
        if(i<0 || i>=n || j<0 || j>= m || grid[i][j] == 0){
            return currGold; 
        } 
        int temp = grid[i][j]; 
        grid[i][j]=0; 
        int op1 = solve(i+1,j,currGold+temp, grid);
        int op2 = solve(i-1,j,currGold+temp, grid);
        int op3 = solve(i,j+1,currGold+temp, grid);
        int op4 = solve(i,j-1,currGold+temp, grid);
        grid[i][j]= temp; 
        return max({op1,op2,op3,op4}); 

      }
    int getMaximumGold(vector<vector<int>>& grid) {
          int n = grid.size(); 
          int m = grid[0].size(); 
            int gold = 0; 
          for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
               if(grid[i][j] != 0) gold = max(gold, solve(i,j,0, grid)); 
            }
          }
          return gold; 
    }
};