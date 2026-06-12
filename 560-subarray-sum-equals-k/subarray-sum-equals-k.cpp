class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int,int> f;
        int n = nums.size();
        int result = 0;
        int sum = 0;
        f[0] = 1;

        for(int i=0; i<n; i++){
            sum = sum + nums[i];
            int que = sum - k;
            int freq = f[que];
            result += freq;
            f[sum]++;
            
        }
        return result;
    }
};