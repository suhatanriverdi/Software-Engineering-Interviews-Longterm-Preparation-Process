// Question Link ---> https://leetcode.com/problems/add-strings/submissions/

package main;

public class main{
	public static void main(String args[]) {
		Solution obj = new Solution();
		String s1 = "9333852702227987";
		String s2 = "85731737104263";
		System.out.println("Result is " + obj.addStrings(s1, s2));
	}
}

class Solution {
	// 0  1  2  3  4  5  6  7  8  9  -> ASCII CHARS
	// 48 49 50 51 52 53 54 55 56 57 -> VALUES
	public String addStrings(String num1, String num2) {
		StringBuilder result = new StringBuilder();
		int r1 = num1.length();
		int r2 = num2.length();
		int carry = 0;
		while(r1>0 || r2>0) {
			int n1 = (r1 > 0) ? (num1.charAt(r1-1) - '0') : 0;
			int n2 = (r2 > 0) ?	(num2.charAt(r2-1) - '0') : 0;
			int sum = (n1 + n2 + carry) % 10;
			carry = (n1 + n2 + carry) / 10;
			result.insert(0, sum);
			System.out.println("sum: " + sum + " carry: " + carry);
			r1 -= 1;
			r2 -= 1;
		}
		if(carry > 0) {
			result.insert(0, carry - '0');
		}
		return result.toString();
	}
}