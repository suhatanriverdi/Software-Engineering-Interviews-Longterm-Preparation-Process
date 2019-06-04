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
};

int main(void) {
	vector<int> nums = {3,-1,0,2};
	Solution obj;
	cout << endl << "Result is " << obj.largestSumAfterKNegations(nums, 3);
	return 0;
}
