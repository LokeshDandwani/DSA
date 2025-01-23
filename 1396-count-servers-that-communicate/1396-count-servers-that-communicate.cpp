class Solution {
public:  

    int fact(double num){
        if(num==0 || num==1){
            return 0; 
        }
        return ceil(num*(num-1)/2.0) ; 
    }
    int countServers(vector<vector<int>>& grid) {
       int m = grid.size(); 
       int n = grid[0].size();

       vector<int> row(m,0); 
       vector<int> col(n,0); 

      for(int i =0; i<m; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == 1){
                row[i]++; 
                col[j]++; 
            }
        }
      }
      int total = 0; 
      for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) {
                    total++; 
                }
            }
        }

      return total; 

    }
};