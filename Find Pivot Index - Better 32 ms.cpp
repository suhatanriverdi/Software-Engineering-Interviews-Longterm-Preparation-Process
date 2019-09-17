// Question Link ---> https://leetcode.com/problems/find-pivot-index/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
    	int right = 0, left = 0;
    	for(auto &n : nums) { right += n; };
		for(int i=0; i<nums.size(); i++) {
			cout << "sum: " << right << " left: " << left << endl;
			if(i>0) {
				left += nums[i-1];
			}
			right -= nums[i];
			if(left == right) {
				return i;
			}
		}    
        return -1;
    }
};

int main(void) {
	vector<int> A = {1, 7, 3, 6, 5, 6};
	Solution obj;
	cout <<	obj.pivotIndex(A);
	return 0;
}
