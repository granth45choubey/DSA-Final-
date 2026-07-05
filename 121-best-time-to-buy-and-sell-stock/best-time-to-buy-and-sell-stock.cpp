class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int low = 0;
        int high = 1;
        int ans = 0;
        
        while(high < n){
            if(prices[low] < prices[high]){
                int diff = prices[high] - prices[low];
                ans = max(ans,diff);
            }
            else low = high;

          high++;
        }
        
        return ans;
    }
};