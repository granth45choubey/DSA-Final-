class Solution {
public:

    void dfs(vector<vector<char>> &board, int row, int col)
    {
        int n = board.size();
        int m = board[0].size();

        board[row][col] = '#';

        int delRow[4] = {-1,1,0,0};
        int delCol[4] = {0,0,-1,1};

        for(int i = 0; i < 4; i++)
        {
            int newRow = row + delRow[i];
            int newCol = col + delCol[i];

            if(newRow >= 0 &&
               newRow < n &&
               newCol >= 0 &&
               newCol < m &&
               board[newRow][newCol] == 'O')
            {
                dfs(board, newRow, newCol);
            }
        }
    }

    void solve(vector<vector<char>>& board)
    {
        int n = board.size();
        int m = board[0].size();

        // First Row
        for(int j = 0; j < m; j++)
        {
            if(board[0][j] == 'O')
            {
                dfs(board, 0, j);
            }
        }

        // Last Row
        for(int j = 0; j < m; j++)
        {
            if(board[n-1][j] == 'O')
            {
                dfs(board, n-1, j);
            }
        }

        // First Column
        for(int i = 0; i < n; i++)
        {
            if(board[i][0] == 'O')
            {
                dfs(board, i, 0);
            }
        }

        // Last Column
        for(int i = 0; i < n; i++)
        {
            if(board[i][m-1] == 'O')
            {
                dfs(board, i, m-1);
            }
        }

        // Final Traversal
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};