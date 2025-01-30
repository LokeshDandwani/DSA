class Solution {
public:
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(n, -1);
        for (int node = 0; node < n; node++) {
            if (colors[node] == -1) {
                if (!isBipartiteDFS(adj, node, colors, 1))
                    return -1;
            }
        }

        vector<int> levels(n);
        for (int node = 0; node < n; node++) {
            levels[node] = getLongestDepth(adj, node, n);
            cout << levels[node] << " ";
        }
        
        int maxNumberOfGroups = 0;
        vector<bool> visited(n, false);
        for (int node = 0; node < n; node++) {
            if (!visited[node]) {
                maxNumberOfGroups += getNumberOfGroupsForComponent(
                    adj, node, levels, visited);
            }
        }

        return maxNumberOfGroups;
    }

private:
    bool isBipartiteDFS(vector<vector<int>> &adj, int curr, vector<int> &color, int currColor) {
        color[curr] = currColor;

        for (int neighbor : adj[curr]) {
            if (color[neighbor] == color[curr]) return false;

            if (color[neighbor] == -1) {  
                if (!isBipartiteDFS(adj, neighbor, color, 1 - currColor)) 
                    return false;
            }
        }

        return true;
    }

    int getLongestDepth(vector<vector<int>> &adj, int srcNode, int n) {
        queue<int> que;
        vector<bool> visited(n, false);

        que.push(srcNode);
        visited[srcNode] = true;
        int depth = 0; 

        while (!que.empty()) {
            int size = que.size(); 

            while(size--) {
                int currentNode = que.front();
                que.pop();

                for (int ngbr : adj[currentNode]) {
                    if (visited[ngbr]) 
                        continue;

                    visited[ngbr] = true;
                    que.push(ngbr);
                }
            }
            depth++;  
        }
        return depth;  
    }

    int getNumberOfGroupsForComponent(vector<vector<int>> &adj, int node,
                                      vector<int> &levels,
                                      vector<bool> &visited) {
        int maxNumberOfGroups = levels[node];
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (visited[neighbor]) continue;
            maxNumberOfGroups = max(maxNumberOfGroups,
                                    getNumberOfGroupsForComponent(
                                        adj, neighbor, levels, visited));
        }
        return maxNumberOfGroups;
    }
};
