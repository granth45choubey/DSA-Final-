class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      
        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        if(mp.size() == nums.size())
            return false;

        return true;
        
    }
};