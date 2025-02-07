// basic input and output
#include <iostream>
// mathematical operations
#include <cmath>
// string operations
#include <string>
// constant variable 
#define Dimension 3
// standard namespace 
using namespace std;
// defining the class Player
class Player
{
// private variables
private:
// name of the player
    string name;
// public variables 
public:
// constructor
    Player(string n)
    {
        name = n;
    }
// getter function to get the name of the player
    string Player_Name()
    {
        return this->name;
    }
};
// The game class
class Game
{
private:
// two Dimensional arrays are used as the game board
    char board_matrix[Dimension][Dimension];
// count variable
    int count;
// public variables
public:

// CreateBoard Function
    void CreateBoard()
    {
// for loop to iterate over rows
        for (int i = 0; i < Dimension; i++)
        {
// for loop to iterate over columns of the row
            for (int j = 0; j < Dimension; j++)
//initialize empty value
                board_matrix[i][j] = ' ';
        }
// calling the showBoard() function.
        showBoard();
    }
// showBoard() function
void showBoard()
{
        printf("\n\n");
// for loop to iterate over the rows
        for (int i = 0; i < Dimension; i++)
        {
// leave space using the tab character
            cout << "\t\t\t";
// iterate over the column of the row
            for (int j = 0; j < Dimension; j++)
                cout << " | " << board_matrix[i][j];
            cout << " |\n\t\t\t----------------" << endl;
        }
}
// PlayTurn function with player object as parameter

void PlayerTurn(Player &player)
{
// position of a cell given by the player
        int position;
// the row to which the position belongs
        int row;
// Get the name of player using PlayerName() function
        cout << "Turn of " << player.Player_Name() <<":"<<endl;
// Get the position
        cout << "Enter the position to be marked: ";
        cin >> position;
// compute the row using ceil() function
        row = ceil((float)position / Dimension);
// compute the column to which the position belongs
        int col = (position - 1) % Dimension;
// check condition to find if the position is empty
        if (board_matrix[row - 1][col] != ' ')
        {
            cout << "Position already marked. Please select another position" << endl;
// restart the function
            PlayerTurn(player);
        }
        else
        {
// mark the position as X if it was player 1 
// mark the position as Y if it was player 2
            player.Player_Name().compare("Player I") == 0 ? board_matrix[row - 1][col] = 'X' : board_matrix[row - 1][col] = 'O';
            cout << " Marked at position: " << position << endl;
// increment count
            count++;
        }
        showBoard();
}
// function MachineTurn
void MachineTurn()
{
// Random position generated by rand() function
        int random_position;
// computing a position between 1 and 9 for a 3X3 matrix
        cout << "Turn of Machine: " << endl;
        random_position = rand() % (Dimension * Dimension + 1);
// computing the row in which the position is present
        int row = ceil((float)random_position / Dimension);
// computing the column in which the position is present
        int col = (random_position - 1) % 3;
// Checking if the position is already marked by other symbols
        if (board_matrix[row - 1][col] != ' ')
        {
// call the function again to replay
            MachineTurn();
        }
        else
        {
            cout << " Marked at position: " << random_position << endl;
// marking the position with O
            board_matrix[row - 1][col] = 'O';
// incrementing the count
            count++;
        }
// calling the showBoard() function
        showBoard();
}
// function CheckWin()
string CheckWin()
    {
// variable used to check in the horizontal direction
        int r1 = 0, r2 = 0;
// variable used to check in the vertical direction
        int c1 = 0, c2 = 0;
// variable used to check in the diagonal direction
        int d1 = 0, d2 = 0;
// symbol X and O
        char x = 'X';
        char O = 'O';
// iterate over the rows
        for (int i = 0; i < Dimension; i++)
        {
// initialize horizontal and vertical variables to zero
            r1 = 0, r2 = 0;
            c1 = 0, c2 = 0;
// Increment for diagonal values on checking consecutive diagonal values.
            if (board_matrix[i][i] == x)
            {
                d1++;
            }
            else if (board_matrix[i][i] == O)
            {
                d2++;
            }
// iterate the columns
            for (int j = 0; j < Dimension; j++)
            {
// Increment for horizontal values on checking consecutive rows
                if (board_matrix[i][j] == x)
                {
                    r1++;
                }
                else if (board_matrix[i][j] == O)
                {
                    r2++;
                }
// Increment for vertical values on checking consecutive columns
                if (board_matrix[j][i] == x)
                {
                    c1++;
                }
                else if (board_matrix[j][i] == O)
                {
                    c2++;
                }
            }
// A player won by matching horizontally
            if (r1 == Dimension || r2 == Dimension)
            {
                return (r1 == Dimension) ? "Player I" : "Player 2";
            }
// A player won by matching vertically
            else if (c1 == Dimension || c2 == Dimension)
            {
                return (c1 == Dimension) ? "Player I" : "Player 2";
            }
// A player won by matching diagonally
            else if (d1 == Dimension || d2 == Dimension)
            {
                return (d1 == Dimension) ? "Player I" : "Player 2";
            }
        }
        if (count == Dimension * Dimension)
        {
            return "Draw";
        }
        return "";
    }
};
int main()
{
    // Creating an object for the Game class
    Game *game = new Game;
    int ch;
    // Initializing a 2D array for the gameboard
    game->CreateBoard();
    // Select the mode of the game
    cout << "Press 1 for single-player and 2 for a two-player game" << endl;
    cin >> ch;
    // String to store the result from CheckWin() function
    string fin = "";
    // flag that indicates if the next player can play
    bool flag = true;
    // switch case for 2 modes of the game
    switch (ch)
    {
        // Singleplayer
    case 1:
    {
        // Creating object for player 1
        Player player("Player I");
        // iterate until a winner or draw is reached
        while (flag)
        {
            // Player turn
            game->PlayerTurn(player);
            // Check if player 1 has won the game or draw
            fin = game->CheckWin();
            if (fin != "")
            {
                goto point;
            }
            // Machine turn
            game->MachineTurn();
            // Check if any player won the game
            fin = game->CheckWin();
            // Conditions to check which player won the game or Draw
        point:
            if (fin == "Player I")
            {
                cout << " Player 1 win";
// break the loop, as a result, is reached
                flag = false;
            }
            else if (fin == "Player 2")
            {
                cout << "Computer Wins";
                flag = false;
            }
            else if (fin == "Draw")
            {
                cout << "The game ended in a draw";
                flag = false;
            }
        }
    }
    case 2:
    {
        // Creating two player objects
        Player player("Player I");
        Player player2("Player 2");
        // iterate until a winner or draw is reached
        while (flag)
        {
            // player 1 turn
            game->PlayerTurn(player);
            // player 2 turn
            fin = game->CheckWin();
            if (fin != "")
            {
                goto point2;
            }
            game->PlayerTurn(player2);
            // Check if there is a winner or a draw in the match
            fin = game->CheckWin();
            // Conditions to check the winner or draw in the match
        point2:
            if (fin == "Player I")
            {
                cout << " Player 1 win";
                flag = false;
            }
            else if (fin == "Player 2")
            {
                cout << "Computer Wins";
                flag = false;
            }
            else if (fin == "Draw")
            {
                cout << "The game ended in a draw";
                flag = false;
            }
        }
    }
        // default case
    default:
    {
        exit(0);
    }
    }
    return 0;
}

