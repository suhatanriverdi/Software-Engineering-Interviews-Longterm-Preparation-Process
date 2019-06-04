// Question Link ---> https://leetcode.com/problems/design-hashmap/
package main;

import java.util.HashMap;
import java.util.ArrayList;

class main {
	public static void main(String []args) {
		MyHashMap hashMap = new MyHashMap();
		hashMap.put(1, 1);
		hashMap.put(2, 2);
		System.out.println(hashMap.get(1));
		System.out.println(hashMap.get(3));
		hashMap.put(2, 1);
		System.out.println(hashMap.get(2));
		hashMap.remove(2);
		System.out.println(hashMap.get(2));
	}
}

class MyHashMap {
	ArrayList<keyItemPair<Integer, Integer>> pairVector = new ArrayList<keyItemPair<Integer, Integer>>();
    /** Initialize your data structure here. */
    public MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
		for(int i=0; i<pairVector.size(); i++) {
			if(pairVector.get(i).key == key) {
				pairVector.get(i).value = value;
			}
		}
		keyItemPair<Integer, Integer> node = new keyItemPair<Integer, Integer>(key, value);
        pairVector.add(node);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
		for(int i=0; i<pairVector.size(); i++) {
			if(pairVector.get(i).key == key) {
				return pairVector.get(i).value;
			}
		}
		return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        for(int i=0; i<pairVector.size(); i++) {
			if(pairVector.get(i).key == key) {
				pairVector.get(i).value = -1;
			}
		}
    }
	
	class keyItemPair<K, V> {
		K key;
		V value;
		keyItemPair<K, V> next;
		public keyItemPair(K key, V value){
			this.key = key;
			this.value = value; 
		}
	}
}