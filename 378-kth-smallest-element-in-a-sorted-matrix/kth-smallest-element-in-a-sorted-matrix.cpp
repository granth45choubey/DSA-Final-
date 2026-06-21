class Solution {
public:

    int fun(vector<vector<int>>& matrix, int n,int m,int mid){
        int row = n-1;
        int column = 0;
        int count = 0;

        while(row>=0 && column < m){
            if(matrix[row][column] <= mid){
                count = count + row + 1;
                column++;
            }
            else{
                row--;
            }
        }
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = matrix[0][0];
        int high = matrix[n-1][m-1];
        int ans = -1;
        
        while(low <= high){
            int mid =(low + high)/2;

            int count_result = fun(matrix,n,m,mid);
            if(count_result < k) low = mid + 1;
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};