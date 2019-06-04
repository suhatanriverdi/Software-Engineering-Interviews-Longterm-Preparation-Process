// Question Link ---> https://leetcode.com/problems/move-zeroes/
// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// You must do this "IN-PLACE" without making a copy of the array.
// Minimize the total number of operations.
#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    void moveZeroes(vector<int>& nums) {
//    	int front = 0, back = nums.size()-1;
//    	while(front != nums.size()-1) {
//    		cout << "Front: " << front << " back: " << back << endl;
//    		if(!nums[front] && !nums[back]) {
//    			back--;
//			}
//			else if(nums[front] && nums[back]) {
//				front++;
//    			back--;
//			}
//			else if(!nums[front] && nums[back]) {
//				cout << "swap!" << endl;
//				swap(nums[front], nums[back]);
//				front++;
//    			back--;
//			}
//			else if(nums[front] && !nums[back]) {
//				front++;
//    			back--;				
//			}
//    		if(front == back) { // Conflict
//    			cout << "Conflict" << front << " back: " << back << endl;
//    			back = nums.size()-1;
//			}
//			if(front > back) {
//				break;
//			}
//		}
//    }
//};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	if(!nums.size() || nums.size() == 1 && !nums[0]) {
    		return;
		}
		int zeros = 0;
		int i = 0;
		for(;;) {
			cout << i << " size: " << nums.size() << " nums[i]: " << nums[i] <<endl;
			if(!nums[i]) {
				zeros++;
				nums.erase(nums.begin()+i);
			}
			else {
				i++;
			}
			if(i == nums.size()) {
				break;
			}
		}
		
		while(zeros) {
			nums.push_back(0);
			zeros--;
		}
    }
};

int main(void) {
//	vector<int> nums = {0,0,1};
//	vector<int> nums = {0};
	int a = 0;
	++a;
	vector<int> nums = {0,1,0,3,12,0};
	Solution obj;
	obj.moveZeroes(nums);
	// Print Result
	for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << " ";
	}
	return 0;
}
