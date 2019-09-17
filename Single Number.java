// Question Link ---> https://leetcode.com/problems/single-number
package main;

import java.util.Set;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;

class main {
    public static void main(String []args) {
        Solution obj = new Solution();
        int []nums = {4,1,2,1,2};
        System.out.println(obj.singleNumber(nums));
    }
}

class Solution {
    public int singleNumber(int[] nums) {
        if(nums.length == 1) {
            return nums[0];
        }
        Set<Integer> set = new HashSet<Integer>();
        for(int i=0; i<nums.length; i++) {
            if(!set.contains(nums[i])) {
                set.add(nums[i]);
            }
            else {
                set.remove(nums[i]);
            }
        }
        Iterator<Integer> iterator = set.iterator();
        Integer singleOne = iterator.next();
        return singleOne;
    }
}

