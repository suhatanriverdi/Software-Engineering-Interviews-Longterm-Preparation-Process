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
        
        int i=0, count=0;
        while(i<nums.size()) { // 28ms SOLUTION
        	if(nums[i] == 1) {
    			count++;
        		i++;
        		maxCon = max(count, maxCon);
			}
        	
        	else if(nums[i] == 1 && nums[i+1] == 0) { // One is Alone
        		maxCon++;
        		i+=2;
			}
			
			else if(nums[i] == 0) {
				maxCon = max(count, maxCon);
				count=0;
        		i++;
			}
		}
        return maxCon;
    }
};

int main(void) {
	vector<int> grid = {1,1,0,1,1,1};
	Solution obj;
	cout << "Max area of island is: " << obj.findMaxConsecutiveOnes(grid);
	return 0;
}
