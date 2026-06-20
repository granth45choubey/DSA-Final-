class Solution {
public:

    bool fun(vector<int> &position,int n,int m,int mid){
        int ball = 1;
        int pos = position[0];

        for(int i=1;i<n;i++){
            int force = position[i] - pos;
            if(force < mid) continue;
            else{
                ball++;
                pos = position[i];
            }
        }
        if(ball >= m) return true;
        else return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int low = 1;
        int high = position[n-1] - position[0];
        int res = -1;

        while(low<=high){
            int mid = (low + high)/2;
            bool accomodated = fun(position,n,m,mid);

            if(accomodated == true){
                res = mid;
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }
        return res;
    }
};