class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0;
        int right = n-1;
        int k = n-1;

        while(left <= right){
            if(abs(nums[left]) > abs(nums[right])){
                res[k] = nums[left] * nums[left];
                left++;
            }
            else{
                res[k] = nums[right]*nums[right];
                right--;
            }
            k--;
        }
        return res;
    }
};