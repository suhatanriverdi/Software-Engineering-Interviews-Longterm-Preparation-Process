// Question Link ---> https://leetcode.com/problems/available-captures-for-rook
package main;
class main {
    public static void main(String []args) {
		char [][]board = new char[][]{
		{'.','.','.','.','.','.','.','.'},
		{'.','.','.','p','.','.','.','.'},
		{'.','.','.','R','.','.','.','p'},
		{'.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.'},
		{'.','.','.','p','.','.','.','.'},
		{'.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.'}}; 
		Solution obj = new Solution();
		System.out.println(obj.numRookCaptures(board));
	}
}

class Solution {
    public int numRookCaptures(char[][] board) {
		for(int row=0; row<board.length; row++) {
			for(int col=0; col<board[row].length; col++) {
				if(board[row][col] == 'R') {
					int x = row;
					int y = col;
					System.out.println("Rook Found! " + x + " " + y);
					return walker(x, y, board);
				}
			}
		}
		return 0;
    }
	int walker(int x, int y, char[][] board) {
		int directions[][] = new int[][]{{0, 1}, {0, -1}, {-1, 0}, {+1, 0}}; // right left up down
		int numCaptures = 0;
		for(int i=0; i<4; i++) {
			int newX = x + directions[i][0];
			int newY = y + directions[i][1];
			while(newX >= 0 && newX < board.length && newY >= 0 && newY < board.length) {
				System.out.println(newX + " " + newY);
				if(board[newX][newY] == 'B') {
					break;
				}
				if(board[newX][newY] == 'p') {
					System.out.println("Pawn!" + newX + " " + newY);
					numCaptures++;
					break;
				}
				newX += directions[i][0];
				newY += directions[i][1];
			}
		}
		return numCaptures;
	}
}