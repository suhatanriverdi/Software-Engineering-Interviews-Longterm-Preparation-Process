//Question Link ---> https://leetcode.com/problems/max-consecutive-ones/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCon = 0;
        if(nums.size() == 0) {
            return 0;
        }
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 1) {
                maxCon = max(consecutive(i, nums), maxCon);
            }
        }
        return maxCon;
    }
    
    int consecutive(int x, vector<int>& nums) { // Recursive 972ms
        if(nums[x] == 1) {
            return 1 + consecutive(x+1, nums);
        }
        return 0;
    }
};

int main(void) {
	vector<int> grid = {1,1,0,1,1,1};
	Solution obj;
	cout << "Max area of island is: " << obj.findMaxConsecutiveOnes(grid);
	return 0;
}
