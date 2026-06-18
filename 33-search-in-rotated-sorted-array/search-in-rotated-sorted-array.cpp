class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low <= high){
            int mid = (high + low)/2;

            if(nums[mid] > nums[n-1]){
                if(nums[mid] == target){
                    ans = mid;
                    break;
                }
                else if(nums[mid] < target){
                    low = mid + 1;
                }
                else{
                    if(target < nums[0]) low = mid + 1;
                    else high = mid -1;
                }
            }
            else{
                 if(nums[mid] == target){
                    ans = mid;
                    break;
                }
                else if(nums[mid] > target) high = mid -1;
                else{
                    if(target > nums[n-1]) high = mid -1;
                    else low = mid + 1;
                }
            }
        }
        return ans;
    }
};