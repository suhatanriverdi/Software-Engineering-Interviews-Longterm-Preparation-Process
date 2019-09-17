// Question Link ---> https://leetcode.com/problems/rotting-oranges/
package main;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

/*[2,1,1]
  [0,1,1]
  [1,0,1]
*/
public class main{
	public static void main(String args[]) {
		Solution obj = new Solution();
		// 2 -> Rotten Orange
		// 1 -> Fresh Orange
		// 0 -> Empty Cell
		int grid[][] = {
			{2, 1, 1},
			{0, 1, 1},
			{1, 0, 1}
		};
		System.out.println("Result is " + obj.orangesRotting(grid));
	}
}

class Solution {
	int minute = 0;
	boolean onceFilled = false;
	int[][] minutes;
    public int orangesRotting(int[][] grid) {
		minutes = new int[grid.length][grid[0].length];
		for(int[] row : minutes) {
			Arrays.fill(row, -1); 
		}
		for(int i=0; i<grid.length; i++) {
			for(int j=0; j<grid[0].length; j++) {
				if(grid[i][j] == 2) {
					minutes[i][j] = 0;
					bfs(grid, i, j);
					onceFilled = true;
				}
			}
		}
		if(isThereFreshLeft(grid, minutes)) {
			return -1;
		}
		findMax(grid, minutes);
		return minute;
    }
	
	public void bfs(int[][] grid, int x, int y) {
		System.out.println("_BFS_");
		boolean[][] isVisited = new boolean[grid.length][grid[0].length];
		for(boolean[] row : isVisited) {
            Arrays.fill(row, false); 
		}
		Pair pair = new Pair(x, y);
		Queue<Pair> q = new LinkedList();
		q.add(pair);
		while(!q.isEmpty()) {
			pair = q.peek();
			q.poll();
			Pair directions[] = new Pair[4];
			directions[0] = new Pair(pair.x-1, pair.y);
			directions[1] = new Pair(pair.x+1, pair.y);
			directions[2] = new Pair(pair.x, pair.y+1);
			directions[3] = new Pair(pair.x, pair.y-1);
			for(int i=0; i<4; i++) {
				int nx = directions[i].x; 
				int ny = directions[i].y;
				if(nx >= 0 && nx < grid.length && ny >= 0 && ny < grid[0].length && !isVisited[nx][ny] && grid[nx][ny] == 1) {
					System.out.println(grid[nx][ny]);
					Pair child = new Pair(nx, ny);
					isVisited[nx][ny] = true;
					q.add(child);
					if(onceFilled == true) {
						if(minutes[nx][ny] < 0 ) {
							minutes[nx][ny] = (1 + minutes[pair.x][pair.y]);
						}
						minutes[nx][ny] = Math.min((1 + minutes[pair.x][pair.y]), minutes[nx][ny]);
					} else {
						minutes[nx][ny] = (1 + minutes[pair.x][pair.y]);
					}
				}
			}
			printArray(minutes);
		}
	}
	
	void findMax(int[][] grid, int[][] minutes) {
		int max = 0;
		for(int i=0; i<grid.length; i++) {
			for(int j=0; j<grid[0].length; j++) {
				if(grid[i][j] == 1) {
					max = (Math.max(minutes[i][j], max));
				}
			}
		}
		minute = max;
	}
	
	boolean isThereFreshLeft(int[][] grid, int[][] minutes) {
		for(int i=0; i<grid.length; i++) {
			for(int j=0; j<grid[0].length; j++) {
				if(grid[i][j] == 1 && minutes[i][j] == -1) {
					return true;
				}
			}
		}
		return false;
	}
	
	void printArray(int[][] arr) {
		System.out.println();
		for(int i=0; i<arr.length; i++) {
			for(int j=0; j<arr[0].length; j++) {
				System.out.print(" " + arr[i][j]);
			}
			System.out.println();
		}
	}
}

class Pair { 
    int x; 
    int y; 
	Pair(int x, int y) { 
        this.x = x; 
        this.y = y; 
    } 
} 