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
		int directions[][] = new int[][]{{x, y+1}, {x, y-1}, {x-1, y}, {x+1, y}}; // right left up down
		int numCaptures = 0;
		
		// Right
		int newX = directions[0][0];
		int newY = directions[0][1];
		while(newY < board.length) { 
			if(board[newX][newY] == 'B') {
				break;
			}
			if(board[newX][newY] == 'p') {
				System.out.println("Pawn!" + newX + " " + newY);
				numCaptures++;
				break;
			}
			newY++;
		}
		
		// Left
		newX = directions[1][0];
		newY = directions[1][1];
		while(newY >= 0) { 
			if(board[newX][newY] == 'B') {
				break;
			}
			if(board[newX][newY] == 'p') {
				System.out.println("Pawn!" + newX + " " + newY);
				numCaptures++;
				break;
			}
			newY--;
		}
		
		// Up
		newX = directions[2][0];
		newY = directions[2][1];
		while(newX >= 0) { 
			if(board[newX][newY] == 'B') {
				break;
			}
			if(board[newX][newY] == 'p') {
				System.out.println("Pawn!" + newX + " " + newY);
				numCaptures++;
				break;
			}
			newX--;
		}
		
		// Down
		newX = directions[3][0];
		newY = directions[3][1];
		while(newX < board.length) { 
			if(board[newX][newY] == 'B') {
				break;
			}
			if(board[newX][newY] == 'p') {
				System.out.println("Pawn!" + newX + " " + newY);
				numCaptures++;
				break;
			}
			newX++;
		}
		return numCaptures;
	}
}