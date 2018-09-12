//QUESTION Link ---> http://codeforces.com/problemset/problem/118/A
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
		
		char n[1000]; // Char Array
		cin >> n; // Input string
		char *c = n; // Char Array's Pointer

		//Remove vowels manually
		for(int i=0; n[i]!='\0'; i++) {
			if(n[i]!='y' && n[i]!='Y' && n[i]!='a' && n[i]!='e' && n[i]!='i' && n[i]!='o' && n[i]!='u' && n[i]!='A' && n[i]!='E' && n[i]!='I' && n[i]!='O' && n[i]!='U'){
				*c++ = n[i]; // assigns n[i] onto itself by c pointer and updates c pointer. Tricky :D 				
			}	
		}
		
		*c = '\0'; // Put null termination character to end of where c points to,
		//It marks the end of the string for the computer to know where string ends.
		// Before Loop: ['G', 'e', 'n']  ---> After Loop: ['G', 'n', '\0']

		//Converting UPPER to lower
		for(int i=0; n[i]!='\0'; i++) {
			if( n[i] >= 'A' && n[i] <= 'Z' ) { // Using ASCII Table Values
				n[i] += 32;	// For exp: 'B' -> 66, 'b' -> 98 and 98-66 = 32, that's why we add 32
			}
		}
		
		string cstr;
		string s;
		//Inserting Dots
		for (int i = 0; n[i] != '\0'; i++) {
			s.append("."); 
			stringstream convert;
			convert << n[i]; //
			convert >> cstr; //
			s.append(cstr);
    	}
	
	cout << s;
	return 0;
}
