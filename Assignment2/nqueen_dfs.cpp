#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
   // Check left side of this row
   for (int i = 0; i < col; i++) {
       if (board[row][i]) {
           return false;
       }
   }

   // Check upper diagonal on left side
   int i = row;
   int j = col;
   while (i >= 0 && j >= 0) {
       if (board[i][j]) {
           return false;
       }
       i--;
       j--;
   }

   // Check lower diagonal on left side
   i = row;
   j = col;
   while (j >= 0 && i < n) {
       if (board[i][j]) {
           return false;
       }
       i++;
       j--;
   }

   return true;
}


bool solveNQueensDFS(vector<vector<int> >& board, int col, int n) {
   if (col == n) {
       // Print the board
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < n; j++) {
               cout << (board[i][j] ? 'Q' : '.') << " ";
           }
           cout << endl;
       }
       cout << endl;
       return true;
   }

   bool res = false;
   for (int i = 0; i < n; i++) {
       if (isSafe(board, i, col, n)) {
           board[i][col] = 1;
           res = solveNQueensDFS(board, col + 1, n) || res;
           board[i][col] = 0; // Backtrack
       }
   }

   return res;
}

bool solveNQueens(int n) {
   vector<vector<int> > board(n, vector<int>(n, 0));
   if (!solveNQueensDFS(board, 0, n)) {
       cout << "Solution does not exist for n = " << n << endl;
       return false;
   }
   return true;
}

int main() {
   int n;
   cout << "Enter the value of n for the N-Queens problem: ";
   cin >> n;
   solveNQueens(n);
   return 0;
}
