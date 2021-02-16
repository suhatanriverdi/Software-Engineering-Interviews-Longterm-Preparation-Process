//Question Link ---> https://leetcode.com/problems/rotate-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
    	if(k > nums.size()) {
    		k = k-nums.size();
		}
		
		if(nums.size() == 1 || nums.size() == k) {
    		return;
		}
		
    	vector<int> temp(nums.size());
    	int lastIndex;
		for(int i=k, j=0; i< nums.size(); lastIndex = j, i++, j++) {
			temp[i] = nums[j];
		}
		
		for(int i=0, j=lastIndex+1; i<k; i++, j++) {
			temp[i] = nums[j];
		}
		nums = temp; 
    }
};

int main(void) {
	vector<int> nums = {1,2};
	int k = 2;
	Solution obj;
	obj.rotate(nums, k);
	for(int i=0; i< nums.size(); i++) {
		cout << nums[i] << " ";
	}
	return 0;
}
