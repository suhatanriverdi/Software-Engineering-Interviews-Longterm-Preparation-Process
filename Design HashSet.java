// Question Link ---> https://leetcode.com/problems/design-hashset/
package main;

import java.util.Arrays;

class main {
	public static void main(String []args) {
		MyHashSet mySet = new MyHashSet();
		System.out.println(mySet.st[5]);
	}
}

class MyHashSet {
	int st[];
    /** Initialize your data structure here. */
    public MyHashSet() {
        st = new int[1000001];
		st[0] = -1;
    }
    
    public void add(int key) {
        st[key] = key;
    }
    
    public void remove(int key) {
        st[key] = -1;
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        if(st[key]==key) {
			return true;
		}
		return false;
    }
}

