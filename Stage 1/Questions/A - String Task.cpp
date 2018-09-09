#include <iostream>
#include <algorithm> 
using namespace std;

int main(void) {
		
		string n;
		cin >> n;
		
		//Remove vowels
		n.erase(remove_if(n.begin(), n.end(), [](char c){ return c=='y' || c=='Y' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'; }), n.end());

		//UPPER to lower
		transform(n.begin(), n.end(), n.begin(), ::tolower);
		
		for (int i = 0; n[i] != '\0'; i++) {
            if (i % 2 == 0) {
                n.insert(i,".");       
            } 
    	}
	
	cout << n;
	
	return 0;
}
