// Question Link ---> https://leetcode.com/problems/rotated-digits/

package main;

import java.util.Set;
import java.util.Arrays;
import java.util.HashSet;

class main {
    public static void main(String []args) {
        Solution obj = new Solution();
        System.out.println(obj.rotatedDigits(10));
    }
}

class Solution {
    public int rotatedDigits(int N) {
        Set<Integer> good = new HashSet<Integer>(Arrays.asList(2,5,6,9));
        Set<Integer> bad = new HashSet<Integer>(Arrays.asList(3,4,7)); // 0,1,8 has no effect!
        int cnt = 0;
        for(int i=1; i<=N; i++) { // 1 to N
            boolean isGoodNum = false;
            int currentNumber = i;
            System.out.println("Current Number: " + currentNumber);
            while(currentNumber > 0) { // For Each Digit
                int righMostDigit = currentNumber%10;
                System.out.print(righMostDigit + " ");
                if(bad.contains(righMostDigit)) {
                    isGoodNum = false;
                    break;
                } 
                else if(good.contains(righMostDigit)) {
                  isGoodNum = true;  
                }
                currentNumber = currentNumber/10;
            }
            if(isGoodNum) {
                cnt++;
            }
            System.out.println();
        }
        return cnt;
    }
}

