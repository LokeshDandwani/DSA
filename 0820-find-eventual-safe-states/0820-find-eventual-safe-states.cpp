class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m= graph.size(); 
        vector<vector<int>> adj(m);

        for(int i=0; i<m;i++){
            for(auto &it: graph[i]){
                adj[it].push_back(i); 
            }
        }
        vector<int> inDegree(m,0); 
        
        for(int i=0; i<m;i++){
            for(auto &it: adj[i]){
                inDegree[it]++;  
            }
        }
         queue<int> q; 

        vector<int> safeNodes; 

        for(  int i=0 ; i<inDegree.size(); i++){
            if(inDegree[i]==0){
                q.push(i); 
            }
        }
        while(!q.empty()){
            int x = q.front(); 
            q.pop();
            safeNodes.push_back(x); 
            for(auto &it: adj[x]){
                inDegree[it]--; 
                if(inDegree[it]==0){
                    q.push(it); 
                }
            }
        }
    sort(begin(safeNodes), end(safeNodes));
        return safeNodes; 

        

    }
};