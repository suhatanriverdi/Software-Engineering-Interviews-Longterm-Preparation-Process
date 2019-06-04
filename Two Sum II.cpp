//Question Link ---> https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size()-1;
        while(start < end) {
            if(numbers[start] + numbers[end] == target) {
                return {start+1, end+1};
            }
            
            if(numbers[start] + numbers[end] > target) {
                end--;
            }
            
            else {
                start++;
            }
        }
    }
};

