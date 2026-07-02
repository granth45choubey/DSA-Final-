class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;

        int low = 1;
        int high = 1;

        while(high < n){
            if(nums[high] != nums[low-1]){
                nums[low] = nums[high];
                low++;
                high++;
            }
            else high++;
        }
        return low;
        
    }
};