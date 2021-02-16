//Testing Breadth First Search on 3-Ary Trees
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class TreeNode {
	public:
		int val;
		TreeNode *right;
		TreeNode *middle;
		TreeNode *left;
		TreeNode(const int &data) :val(data), right(NULL), left(NULL), middle(NULL) {};
};

vector<vector<int>> bfs(TreeNode *root) {
	if (root == NULL) {
		cout << "Tree does not have any Node!" << endl;
		return vector<vector<int>>();
	}
	vector<vector<int>> all;
	int data;
	vector<int> level;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i<size; i++) {
			TreeNode *temp = q.front();
			q.pop();
			cout << " -> " << temp->val << " ";
			level.push_back(temp->val);
			if(temp->left) {
				q.push(temp->left);
			}
			if(temp->middle) {
				q.push(temp->middle);
			}
			if(temp->right) {
				q.push(temp->right);
			}
		}
		all.push_back(level);
		level.clear();
	}
	cout << "\n\n";
	return all;
}

int main(void) {
	TreeNode *n;
	n = new TreeNode(1);
	
	n->left = new TreeNode(2);
	n->middle = new TreeNode(3);
	n->right = new TreeNode(4);

	n->left->left = new TreeNode(21);
	n->left->middle = new TreeNode(22);
	n->left->right = new TreeNode(23);
	
	n->middle->left = new TreeNode(31);
	n->middle->middle = new TreeNode(32);
	n->middle->right = new TreeNode(33);

	n->right->left = new TreeNode(41);
	n->right->middle = new TreeNode(42);
	n->right->right = new TreeNode(43);
	
	vector<vector<int>> vec;
	vec = bfs(n);
	for(int i = 0; i < vec.size(); i++) {
	    for (int j = 0; j < vec[i].size(); j++) {
	        cout << vec[i][j] << " ";
	    }
	    cout << "\n";
	}
	return 0;
}
