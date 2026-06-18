class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int idx = -1;
        int ans = -1;

        while(low <= high){
            int mid = (high + low)/2;
            if(nums[mid] > nums[n-1]){
                low = mid + 1;
            }
            else{
                idx = mid;
                high = mid - 1;
            }
        }
        if(idx != 0 && target >= nums[0] && target <= nums[idx-1]){
            int low = 0;
            int high = idx -1;

            while(low <= high){
                int mid = (high + low)/2;
                if(nums[mid] == target){
                    ans = mid;
                    break;
                }
                else if(nums[mid] < target){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            }
        }
        else{
            int low = idx;
            int high = n -1;

            while(low <= high){
                int mid = (high + low)/2;
                if(nums[mid] == target){
                    ans = mid;
                    break;
                }
                else if(nums[mid] < target){
                    low = mid +1;
                }
                else{
                    high = mid -1;
                }
            }

        }
        return ans;
    }
};