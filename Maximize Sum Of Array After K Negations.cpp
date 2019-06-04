// Question Link ---> https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
    	priority_queue<int, vector<int>, greater<int>> pq;
    	int sum = 0;
        sort(A.begin(), A.end());
        for(auto num:A) cout << num << " "; cout << endl;
        for(int i=0; i<A.size(); i++) {
        	if(A[i]>=0) { // If full Positive 0,1,2...
        		if(K%2 == 0) {
        			return makeSum(A);
				}
				else {
					A[0] = A[0]*(-1);
					return makeSum(A);
				}
			}
			else { // Mixed -1,0,3...
				for(int n : A) {
        			pq.push(n);
				}
				while(K) {
					print_queue(pq);
					int temp = pq.top();
					pq.pop();
					pq.push(-temp);
					K--;
				}
				return sumPQ(pq);
			}
	        sum += A[i];
		}
//		for(auto num:A) cout << num << " ";
        return sum;
    }
    
    template<typename T>
    void print_queue(T pq) {
    	cout << "Queue printing ";
    	while(!pq.empty()) {
			cout << pq.top() << " ";
			pq.pop();    		
		}
		cout << endl;
	}
	
	template<typename T>
    int sumPQ(T pq) {
    	int sum = 0;
    	while(!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
		return sum;
	}
    
    int makeSum(vector<int> &nums) {
    	int sum = 0;
    	for(auto i:nums) {
    		sum += i;
		}
		return sum;
	}
};

int main(void) {
	vector<int> nums = {3,-1,0,2};
	Solution obj;
	cout << endl << "Result is " << obj.largestSumAfterKNegations(nums, 3);
	return 0;
}
