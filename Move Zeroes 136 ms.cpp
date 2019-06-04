// Question Link ---> https://leetcode.com/problems/move-zeroes/
// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// You must do this "IN-PLACE" without making a copy of the array.
// Minimize the total number of operations.
#include <iostream>
#include <vector>
using namespace std;

/* ANOTHER SOLUTION (CARRY ZEROS) But Leetcode Gives Runtime Error?
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		for(int i = 0; i<nums.size(); i++) {
			if(!nums[i]) {
				swapper(nums, i, nums[i]);
			}
		}        
    }
    
    void swapper(vector<int>& nums, int pos, int n) {
    	for(int i = pos; i<nums.size(); i++) {
    		swap(nums[i], nums[i+1]);
		}
	}
};
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		for(int i = 0; i<nums.size(); i++) {
			if(nums[i]) {
				swapper(nums, i);
			}
		}        
    }
    
    void swapper(vector<int> &nums, int pos) {
    	for(int i = pos; i>0; i--) {
    		if(!nums[i-1]) {	
	    		swap(nums[i], nums[i-1]);
			}
		}
	}
};

int main(void) {
	vector<int> nums = {0,1,0,3,12};
	Solution obj;
	obj.moveZeroes(nums);
	// Print Result
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	return 0;
}
