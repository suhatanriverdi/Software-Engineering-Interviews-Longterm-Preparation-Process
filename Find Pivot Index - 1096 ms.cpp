// Question Link ---> https://leetcode.com/problems/find-pivot-index/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
		for(int i=0; i<nums.size(); i++) {
			if(isPivot(leftSum(i, nums), rightSum(i, nums))) {
				return i;
			}
		}    
        return -1;
    }
    
    int leftSum(int index, vector<int>& nums) {
    	int sum = 0;
		for(int i=0; i<index; i++) {
			sum += nums[i];
		}   
		return sum; 
	}
	
	int rightSum(int index,vector<int>& nums) {
		int sum = 0;
		for(int i=index+1; i<nums.size(); i++) {
			sum += nums[i];
		}   
		return sum;   
	}
	
	bool isPivot(int left, int right) {
		cout << "Left :" << left << " Right: " << right << endl;
		if(left == right) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main(void) {
	vector<int> A = {1, 7, 3, 6, 5, 6};
	Solution obj;
	cout <<	obj.pivotIndex(A);
	return 0;
}
