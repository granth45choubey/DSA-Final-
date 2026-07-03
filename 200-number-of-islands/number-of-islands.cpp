class Solution {
public:

void dfs(int row,int col,vector<vector<char>> &grid,vector<vector<int>> &visited){
    visited[row][col] = 1;

    int delrow[] = {-1,1,0,0};
    int delcol[] = {0,0,-1,1};

    for(int i=0;i<4;i++){
        int newrow = row + delrow[i];
        int newcol = col + delcol[i];

        if(newrow>=0 && newrow < grid.size() && newcol >= 0 && newcol < grid[0].size()
                && grid[newrow][newcol] == '1'
                && visited[newrow][newcol] == 0  ){
                    dfs(newrow,newcol,grid,visited);
                }
    }
}

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        int islands = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    islands++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return islands;
    }
};