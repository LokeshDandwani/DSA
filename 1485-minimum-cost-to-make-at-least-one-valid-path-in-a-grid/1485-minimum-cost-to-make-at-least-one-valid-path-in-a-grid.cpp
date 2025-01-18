class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        cost[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int currCost = curr[0];
            int i = curr[1];
            int j = curr[2];

            if (currCost > cost[i][j]) 
                continue;

            for (int dir = 0; dir < 4; ++dir) {
                int i_ = i + directions[dir][0];
                int j_ = j + directions[dir][1];

                if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                    int gridDirection = grid[i][j]; 
                    int directionCost = 0;        

                    int newCost = currCost + (dir != (gridDirection - 1) ? 1 : 0);;

                    if (newCost < cost[i_][j_]) {
                        cost[i_][j_] = newCost;
                        pq.push({newCost, i_, j_});
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};