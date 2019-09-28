//QUESTION Link ---> https://leetcode.com/problems/maximum-subarray/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:
	    int maxSubArray(vector<int>& nums) {	
	        bool flag = true;	        
	        if (nums.size() == 1) { // If Array has only one item
	            return nums[0];
	        }
	
	        for (int i = 0; i < nums.size(); i++) {	
	            if (nums[i] >= 0) {
	                flag = false;
	                break;
	            }
	        }
	
	        if (flag == true) { // All Negative
	            int min = nums[0];
	            for (int i = 1; i < nums.size(); i++) {
	                if (nums[i] > min)
	                    min = nums[i];
	            }
	            return min;
	        }
	
	        else if (flag == false) {
	            int max_here = 0, max_sofar = 0;	
	            for (int i = 0; i < nums.size(); i++) {
	                max_here += nums[i];
	                if (max_here < 0) {
	                    max_here = 0;
					}
	                else if (max_sofar < max_here) {
	                    max_sofar = max_here;
					}
	            }
	            return max_sofar;
	        }
	    }
};

int main(void) {
    vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    Solution obj;
    cout << obj.maxSubArray(nums);
    return 0;
}
