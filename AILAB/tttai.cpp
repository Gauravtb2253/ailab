#include <bits/stdc++.h>
using namespace std;

void printBoard(vector<char> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (i % 3 == 0)
        {
            cout << endl;
        }
        cout << board[i] << " ";
    }
    cout << endl;
}

bool isBoardFull(vector<char> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i] == '*')
        {
            return false;
        }
    }
    return true;
}

bool checkWin(vector<char> board, int player)
{
    char c;
    if (player == 1)
    {
        c = 'X';
    }
    else
    {
        c = 'O';
    }
    for (int i = 0; i < 3; i++)
    {
        if ((board[i * 3] == c && board[i * 3 + 1] == c && board[i * 3 + 2] == c) || (board[i] == c && board[i + 3] == c && board[i + 6]==c))
        {
            return true;
        }
    }
    if ((board[0] == c && board[4] == c && board[8] == c) || (board[2] == c && board[4] == c && board[6] == c))
    {
        return true;
    }
    return false;
}

int evaluateBoard(vector<char> board)
{
    if (checkWin(board, 2))
    {
        return 1;
    }
    else if (checkWin(board, 1))
    {
        return -1;
    }
    else if(isBoardFull(board))
    {
        return 0;
    }
    return INT_MAX;
}

int minimax(vector<char> board, int depth, bool isMaximising)
{
    int score = evaluateBoard(board);
    if (score != INT_MAX)
    {
        return score;
    }
    if (isMaximising)
    {
        int maxScore = INT_MIN;
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i] == '*')
            {
                board[i] = 'O';
                maxScore = max(maxScore, minimax(board, depth + 1, !isMaximising));
                board[i] = '*';
            }
        }
        return maxScore;
    }
    else
    {
        int minScore = INT_MAX;
        for (int i = 0; i < board.size(); i++)
        {
            if (board[i] == '*')
            {
                board[i] = 'X';
                minScore = min(minScore, minimax(board, depth + 1, !isMaximising));
                board[i] = '*';
            }
        }
        return minScore;
    }
}

void makeAImove(vector<char> &board)
{
    int bestScore = INT_MIN;
    int moveIndex = -1;
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i] == '*')
        {
            board[i] = 'O';
            int score = minimax(board, 0, false);
            board[i] = '*';
            if (bestScore < score)
            {
                bestScore = score;
                moveIndex = i;
            }
        }
    }
    board[moveIndex] = 'O';
}

void playGame()
{
    vector<char> board(9, '*');
    int currentPlayer = 1;
    while (1)
    {
        if (currentPlayer == 1)
        {
            int move;
            cout << "Enter your move:[1-9]" << endl;
            cin >> move;
            move = move - 1;
            if (move >= 0 && move <= 8 && board[move] == '*')
            {
                board[move] = 'X';
                printBoard(board);
            }
            else
            {
                cout << "Enter again Invalid move:" << endl;
                continue;
            }
        }
        else if (currentPlayer == 2)
        {
            cout << "Computer Move:";
            makeAImove(board);
            printBoard(board);
        }

        if (checkWin(board, currentPlayer))
        {
            if (currentPlayer == 1)
            {
                cout << "Player X wins!!!" << endl;
            }
            else
            {
                cout << "Player O wins!!!" << endl;
            }
            return;
        }
        else if (isBoardFull(board))
        {
            cout << "Its a draw!!!" << endl;
            return;
        }

        currentPlayer = 3 - currentPlayer;
    }
}

int main()
{
    playGame();
    return 0;
}