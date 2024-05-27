// #include <iostream>
// #include <climits>
// #include <ctime>
// #include <vector>

// using namespace std;

// void printBoard(vector<char> &board)
// {
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             cout << board[i * 3 + j] << " ";
//         }
//         cout << endl;
//     }
//     cout << endl;
// }

// bool checkWin(vector<char> &board, char player)
// {
//     for (int i = 0; i < 3; i++)
//     {
//         if ((board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) ||
//             (board[i] == player && board[i + 3] == player && board[i + 6] == player))
//         {
//             return true;
//         }
//     }

//     if ((board[0] == player && board[4] == player && board[8] == player) ||
//         (board[2] == player && board[4] == player && board[6] == player))
//     {
//         return true;
//     }

//     return false;
// }

// bool isBoardFull(vector<char> &board)
// {
//     for (int i = 0; i < 9; i++)
//     {
//         if (board[i] == '*')
//             return false;
//     }
//     return true;
// }

// int evaluateBoard(vector<char> &board)
// {
//     if (checkWin(board, 'O'))
//     {
//         return 1;
//     }
//     else if (checkWin(board, 'X'))
//     {
//         return -1;
//     }
//     else if (isBoardFull(board))
//     {
//         return 0;
//     }
//     return INT_MAX;
// }

// int minimax(vector<char> &board, int depth, bool isMaximizing)
// {
//     int score = evaluateBoard(board);

//     if (score != INT_MAX)
//     {
//         return score;
//     }

//     if (isMaximizing)
//     {
//         int maxScore = INT_MIN;
//         for (int i = 0; i < 9; i++)
//         {
//             if (board[i] == '*')
//             {
//                 board[i] = 'O';
//                 maxScore = max(maxScore, minimax(board, depth + 1, !isMaximizing));
//                 board[i] = '*';
//             }
//         }
//         return maxScore;
//     }
//     else
//     {
//         int minScore = INT_MAX;
//         for (int i = 0; i < 9; i++)
//         {
//             if (board[i] == '*')
//             {
//                 board[i] = 'X';
//                 minScore = min(minScore, minimax(board, depth + 1, !isMaximizing));
//                 board[i] = '*';
//             }
//         }
//         return minScore;
//     }
// }

// void makeAIMove(vector<char> &board)
// {
//     int bestScore = INT_MIN;
//     int bestMove = -1;

//     for (int i = 0; i < 9; i++)
//     {
//         if (board[i] == '*')
//         {
//             board[i] = 'O';
//             int moveScore = minimax(board, 0, false);
//             board[i] = '*';

//             if (moveScore > bestScore)
//             {
//                 bestScore = moveScore;
//                 bestMove = i;
//             }
//         }
//     }

//     board[bestMove] = 'O';
// }

// void game()
// {
//     vector<char> board(9, '*');

//     int currentPlayer = 1;

//     while (true)
//     {
//         if (currentPlayer == 1)
//         {

//             int move;
//             cout << "Enter your move (1-9): "<<endl;
//             cin >> move;
//             cout << "Human move:" << endl;
//             int moveIndex = move - 1;

//             if (move < 1 || move > 9 || board[moveIndex] != '*')
//             {
//                 cout << "Invalid move! Try again.\n";
//                 continue;
//             }

//             board[moveIndex] = 'X';
//             printBoard(board);
//         }
//         else
//         {
//             cout << "Computer move:" << endl;
//             makeAIMove(board);
//             printBoard(board);
//         }

//         if (checkWin(board, (currentPlayer == 1) ? 'X' : 'O'))
//         {
//             printBoard(board);
//             cout << "Player " << currentPlayer << " wins!\n";
//             break;
//         }

//         if (isBoardFull(board))
//         {
//             printBoard(board);
//             cout << "Draw\n";
//             break;
//         }

//         currentPlayer = 3 - currentPlayer;
//     }
// }

// int main()
// {
//     game();
//     return 0;
// }

#include <iostream>
#include <climits>
#include <ctime>
#include <vector>

using namespace std;

void printBoard(vector<char> &board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i * 3 + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool checkWin(vector<char> &board, char player)
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) ||
            (board[i] == player && board[i + 3] == player && board[i + 6] == player))
        {
            return true;
        }
    }

    if ((board[0] == player && board[4] == player && board[8] == player) ||
        (board[2] == player && board[4] == player && board[6] == player))
    {
        return true;
    }

    return false;
}

bool isBoardFull(vector<char> &board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i] == '*')
            return false;
    }
    return true;
}

int evaluateBoard(vector<char> &board)
{
    if (checkWin(board, 'O'))
    {
        return 1;
    }
    else if (checkWin(board, 'X'))
    {
        return -1;
    }
    else if (isBoardFull(board))
    {
        return 0;
    }
    return INT_MAX;
}

int minimax(vector<char> &board, int depth, bool isMaximizing)
{
    int score = evaluateBoard(board);

    if (score != INT_MAX)
    {
        return score;
    }

    if (isMaximizing)
    {
        int maxScore = INT_MIN;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == '*')
            {
                board[i] = 'O';
                maxScore = max(maxScore, minimax(board, depth + 1, !isMaximizing));
                board[i] = '*';
            }
        }
        return maxScore;
    }
    else
    {
        int minScore = INT_MAX;
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == '*')
            {
                board[i] = 'X';
                minScore = min(minScore, minimax(board, depth + 1, !isMaximizing));
                board[i] = '*';
            }
        }
        return minScore;
    }
}

void makeAIMove(vector<char> &board)
{
    int bestScore = INT_MIN;
    int bestMove = -1;

    for (int i = 0; i < 9; i++)
    {
        if (board[i] == '*')
        {
            board[i] = 'O';
            int moveScore = minimax(board, 0, false);
            board[i] = '*';

            if (moveScore > bestScore)
            {
                bestScore = moveScore;
                bestMove = i;
            }
        }
    }

    board[bestMove] = 'O';
}

void Play_game()
{
    vector<char> board(9, '*');

    int currentPlayer = 1;

    while (true)
    {
        if (currentPlayer == 1)
        {

            int move;
            cout << "Enter your move (1-9): " << endl;
            cin >> move;
            cout << "Human move:" << endl;
            int moveIndex = move - 1;

            if (move < 1 || move > 9 || board[moveIndex] != '*')
            {
                cout << "Invalid move! Try again.\n";
                continue;
            }   

            board[moveIndex] = 'X';
            printBoard(board);
        }
        else
        {         
            cout << "Computer move:" << endl;
            makeAIMove(board);
            printBoard(board);
        }

        if (checkWin(board, (currentPlayer == 1) ? 'X' : 'O'))
        {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isBoardFull(board))
        {
            printBoard(board);
            cout << "Draw\n";
            break;
        }

        currentPlayer = 3 - currentPlayer;
    }
}

int main()
{
    Play_game();
    return 0;
}
