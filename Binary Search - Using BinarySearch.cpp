//Question Link ---> https://leetcode.com/problems/binary-search/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(left <= right) {
            mid = (left+right)/2;
            if(nums[mid] < target) {
                left = mid+1;
            }
            else if(nums[mid] > target) {
                right = mid-1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
};
