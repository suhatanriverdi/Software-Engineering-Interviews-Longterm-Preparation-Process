#include <iostream>
#include <vector>
/*
-1 bir önceki sayýya bak demek
pozitif bir sayý varsa bu yolu tutmuþuz demektir.
Sample ARRAY of VECTOR
vector<int> values[5] = {
    vector<int>(5),
    vector<int>(5),
    vector<int>(5),
    vector<int>(5),
    vector<int>(5),
};
*/
using namespace std;
vector<int> all[10000];

bool contains(long long int const n) {
	if(all[n].size() != 0) {
		cout << endl << "Found: " << all[n].at(0) << endl;
		all[n].push_back(-1);
		return true;
	}
	return false;
}

void savePaths(long long int &n) {
	int index = n;
	//all[n].push_back();
	while(n != 1) {	
		cout << n << " ";
		if(contains(n)) {
			break;
		}
		if(n%2 == 0) {
			n = (n/2);
			all[index].push_back(n);
			continue;
		}
		if(n%2 != 0) {
			n = ((3*n)+1);
			all[index].push_back(n);
		}
	}
	cout << "1 ";
}

int main(void) {
	long long int n;
//	savePaths(n);
//	n = 12;
//	savePaths(n);
	n = 23;
	savePaths(n);
	n = 67;
	savePaths(n);
	
		if(n%2 == 0) {
			n = (n/2);
			all[index].push_back(n);
			continue;
		}
		if(n%2 != 0) {
			n = ((3*n)+1);
			all[index].push_back(n);
		}
//	cout << endl << endl << endl;
//	cout << "12 ";
//	for(int i=0; i<all[12].size(); i++) {
//		cout << all[12].at(i) << " ";
//	}

	n = 5;
	int yol[20];
	//0 1 2 3  4 5 6 7 8 9 10 11 12 13 14 15 16
	//# # 1 10 2 16                          8  
	for(int i=0; i<10; i++) {
		if(yol[n] ) {
			
		}
	}

	
	cout << endl << endl << endl;
	cout << "23 ";
	for(int i=0; i<all[23].size(); i++) {
		cout << all[23].at(i) << " ";
	}

	cout << endl << endl << endl;
	cout << "67 ";
	for(int i=0; i<all[67].size(); i++) {
		cout << all[67].at(i) << " ";
	}

//	cout << "\n\n";
//	for(int j=0; j<10000; j++) {
//		for(int i=0; i<all[j].size(); i++) {
//			cout << all[j].at(i) << " ";
//		}
//	}
	return 0;
}

