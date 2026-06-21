class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> pq;
        int n = nums.size();

        for(int i =0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int j =k;j<n;j++){
            if(nums[j] <= pq.top()) continue;
            else{
                pq.pop();
                pq.push(nums[j]);
            }
        }
        return pq.top();
    }
};