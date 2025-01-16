class Solution {
public: 

     bool solve(int i , int j, vector<vector<char>>& board, string &s, string &word){
          int n= board.size(); 
          int m = board[0].size(); 
          if(i<0 || i>=n || j<0 || j>=m || board[i][j] == '$'){
            return false; 
          }
           s.push_back(board[i][j]); 
          if(s.size() == word.size()){
           bool isMatch = (s == word);
            s.pop_back(); 
            return isMatch;
          }
          char temp = board[i][j];
         
          
          board[i][j] = '$'; 
            bool found = solve(i + 1, j, board, s, word) ||
                     solve(i - 1, j, board, s, word) ||
                     solve(i, j + 1, board, s, word) ||
                     solve(i, j - 1, board, s, word);
           s.pop_back(); 
            board[i][j]=temp; 
           return found;  
     }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); 
        int m = board[0].size(); 
         string ans=""; 
         for(int i =0; i<n;i++){
            for(int j =0; j<m; j++){
                if(solve(i,j,board,ans, word)){
                    return true; 
                }
            }
         }
         return false; 
    }
};