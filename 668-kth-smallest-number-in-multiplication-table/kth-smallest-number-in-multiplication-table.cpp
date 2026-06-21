class Solution {
public:

    int fun(int m ,int n, int mid){
        int row = m;
        int col = 1;
        int count = 0;

        while(row >= 1 && col <= n){
            if(row*col <= mid){
                count = count + row;
                col ++;
            }
            else row--;
        }
        return count;
    }

    int findKthNumber(int m, int n, int k) {
        int low = 1;
        int high = m*n;
        int ans = -1;

        while(low <= high){
            int mid = (low + high)/2;

            int count_result = fun(m,n,mid);

            if(count_result < k) low = mid + 1;
            else{
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};