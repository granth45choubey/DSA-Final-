class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int point1 = m-1;
        int point2 = n-1;
        int k = m+n-1;
       
       while(point1 >= 0 && point2 >= 0){
          if(nums1[point1] > nums2[point2]){
           nums1[k] = nums1[point1];
           point1--;
        }
         else{
            nums1[k] = nums2[point2];
            point2--;
         }
         k--;
       }
       while(point2>=0){
        nums1[k] = nums2[point2];
        point2--;
        k--;
       }
    }
};