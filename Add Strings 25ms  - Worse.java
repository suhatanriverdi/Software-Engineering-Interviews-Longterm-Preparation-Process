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
	public String addStrings(String num1, String num2) {
		int r1 = num1.length();
		int r2 = num2.length();
        int big = (r1 > r2) ? r1 : r2;
		ArrayList nums = new ArrayList();
		int carry = 0;
        int i = 0;
		while(r1>0 || r2>0) {
			int n1 = (r1 > 0) ? (num1.charAt(r1-1) - '0') : 0;
			int n2 = (r2 > 0) ?	(num2.charAt(r2-1) - '0') : 0;
			int sum = (n1 + n2 + carry) % 10;
			carry = (n1 + n2 + carry) / 10;
			r1 -= 1;
			r2 -= 1;
			nums.add(sum);
		}
        String result = "";
		if(carry > 0) {
			nums.add(carry);
		}
		for(int j = nums.size() - 1; j >= 0; j--) {
			result += nums.get(j);
		}
		return result;
	}
}