class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        
        int point1 = 0;
        int point2 = 1;
        int unique = 1;
        while( point2 < nums.size() ){
        

            if ( nums[point2]== nums[point2 - 1]){
                point2 ++;
            }
            else {
                nums[point1 + 1] = nums[point2];
                point1 ++;
                point2 ++;
                unique = unique + 1;
            }
        }
        return unique;
        
    }
};