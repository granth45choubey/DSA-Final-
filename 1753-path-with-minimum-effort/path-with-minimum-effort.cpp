class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        effort[0][0] = 0;

        pq.push({0,{0,0}});

        int delRow[4] = {-1,1,0,0};
        int delCol[4] = {0,0,-1,1};

        while(!pq.empty())
        {
            pair<int,pair<int,int>> current = pq.top();
            pq.pop();

            int currentEffort = current.first;
            int row = current.second.first;
            int col = current.second.second;

            if(currentEffort > effort[row][col])
            {
                continue;
            }

            // Reached destination
            if(row == n-1 && col == m-1)
            {
                return currentEffort;
            }

            for(int i = 0; i < 4; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 &&
                   newRow < n &&
                   newCol >= 0 &&
                   newCol < m)
                {
                    int edgeEffort = abs(heights[row][col] - heights[newRow][newCol]);

                    int newEffort = max(currentEffort, edgeEffort);

                    if(newEffort < effort[newRow][newCol])
                    {
                        effort[newRow][newCol] = newEffort;

                        pq.push({newEffort,{newRow,newCol}});
                    }
                }
            }
        }

        return 0;
    }
};