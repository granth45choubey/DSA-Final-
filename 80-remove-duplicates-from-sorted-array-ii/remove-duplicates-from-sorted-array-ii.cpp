class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;

        int low = 2;
        int high = 2;

        while(high < n){
            if(nums[high] != nums[low-2]){
                nums[low] = nums[high];
                low++;
                high++;
            }
            else high++;
        }
        return low;
    }
};