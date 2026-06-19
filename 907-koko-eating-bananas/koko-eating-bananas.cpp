class Solution {
public:
    long long int fun(vector<int> &piles,int n, int speed){
        long long int hours = 0;
        for(int i=0; i<n; i++){
             hours = hours + (piles[i]/speed);
            if(piles[i] % speed != 0) hours ++;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mx_a = INT_MIN;
        int res = -1;

        for(int i = 0;i<n; i++){
            mx_a = max(mx_a , piles[i]);
        }

        int low = 1;
        int high = mx_a;

        while(low <= high){
            int mid = (low + high)/2;

            long long int hourstaken = fun(piles, n, mid);

            if(hourstaken > h) low = mid + 1;
            else{
                res = mid;
                high = mid -1;
            }
        }
        return res;
    }
};