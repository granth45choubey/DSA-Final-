class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int power = 0;
        int nopower = arr[0];
        int res = arr[0];

        for(int i =1; i<n; i++){
            int v1 = arr[i];
            int v2 = nopower + arr[i];
            int v3 = nopower;
            int v4 = power + arr[i];

            res = max(res,max(max(v1,v2),max(v3,v4)));

            power = max(v3,v4);
            nopower = max(v1,v2);
        }
        return res;
    }
};