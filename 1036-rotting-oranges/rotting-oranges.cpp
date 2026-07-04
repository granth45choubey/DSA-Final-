class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue <pair<int,int>> q;

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2)
                q.push({i,j});
                else if(grid[i][j] == 1)
                fresh++;
            }
        }
        int delrow[4] = {-1,1,0,0};
        int delcol[4] = {0,0,-1,1};

        int minutes = 0;
        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                pair<int,int> current = q.front();
                q.pop();
                int row = current.first;
                int col = current.second;

                for(int j =0;j<4;j++){
                    int newrow = row + delrow[j];
                    int newcol = col + delcol[j];

                    if((newrow>=0 && newrow<n) && (newcol >= 0 && newcol < m) && grid[newrow][newcol] == 1){
                        grid[newrow][newcol] = 2;
                        fresh--;
                        q.push({newrow,newcol});
                    }
                }
            }
            if(!q.empty()) minutes++;
        }
    
            if(fresh > 0) return -1;
        return minutes;
    }
};