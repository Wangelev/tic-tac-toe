// Tic-tac-toe
// Human vs Computer

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Global Constants
const char X = 'X';
const char O = 'O';
const char TIE = 'T';
const char NO_ONE = 'N';
const char EMPTY = ' ';

// Fumction Prototypes
void instructions();
char askYesNo(string question);
int askNumber(string question, int low, int high);
char humanPiece();
char opponent(char piece);
void displayBoard(const vector <char>& board);
char winner(const vector <char>& board);
bool isLegal(const vector <char>& board, int move);
int humanMove(const vector <char>& board, char human);
int computerMove(const vector <char> board, char computer);
void announceWinner(char winner, char human, char computer);
char togglePlayer(char current);

// Main
int main(){

    int move;
    const int NUM_SQUARES = 9;
    vector <char> board(NUM_SQUARES, EMPTY);

    instructions();
    char human = humanPiece();
    char computer = opponent(human);
    char current = X;
    displayBoard(board);

    while (winner(board) == NO_ONE)
    {
        if(current == human){
            move = humanMove(board, human);
            board[move] = human;
        }
        else{
            move = computerMove(board, computer);
            board[move] = computer;
        }
        displayBoard(board);
        current = togglePlayer(current);
    }

    announceWinner(winner(board), human, computer);

    return 0;
}
void instructions(){
    cout << "Welcome \n\n";
    cout << "Make your move by entering a number 0-8 which corresponds to a board position as below \n\n";

    cout << "    0 | 1 | 2 \n";
    cout << "    _________ \n";
    cout << "    3 | 4 | 5 \n";
    cout << "    _________ \n";
    cout << "    6 | 7 | 8 \n\n";
}

char askYesNo(string question){
    char response;
    do
    {
        cout << question << "(y/n):" << endl;
        cin >> response;

    } while (response != 'y' && response != 'n');

    return response;
}

int askNumber(string question, int low, int high){
    int number;
    do
    {
        cout << question << "( " << low << " - "  << high << " ):";
        cin >> number;
    } while (number < low || number > high);

    return number;
}

char humanPiece(){
    char go_first = askYesNo("Do you wish to go first?");
    if (go_first == 'y'){
        cout << "Go ahead \n";
        return X;
    }
    else{
        cout << "I will start \n";
        return O;
    }
}

char opponent(char piece){
    if (piece == X){
        return O;
    }
    else{
        return X;
    }
}

void displayBoard(const vector <char>& board){
    cout << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "________ \n";
    cout << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "________ \n";
    cout << board[6] << " | " << board[7] << " | " << board[8] << "\n";
    cout << "\n\n";
}

char winner(const vector <char>& board){
    // possible winning rows
    const int WINNING_ROWS[8][3] = {{0, 1, 2},
                                    {3, 4, 5},
                                    {6, 7, 8},
                                    {0, 3, 6},
                                    {1, 4, 7},
                                    {2, 5, 8},
                                    {0, 4, 8},
                                    {2, 4, 6}};
                                    
const int TOTAL_ROWS = 8;
for (int rows = 0; rows < TOTAL_ROWS; rows++)
{
    if ((board[WINNING_ROWS[rows][0]] != EMPTY) && 
        (board[WINNING_ROWS[rows][0]]) == board[WINNING_ROWS[rows][1]] &&
        (board[WINNING_ROWS[rows][1]]) == board[WINNING_ROWS[rows][2]])
    {
        return board[WINNING_ROWS[rows][0]];
    }
    
}
if (count(board.begin(), board.end(), EMPTY) == 0)
{
    return TIE;
}
return NO_ONE;
}

inline bool isLegal(const vector <char>& board, int move){
    return (board[move] == EMPTY);

}

int humanMove(const vector <char>& board, char human){
    int move = askNumber("Where will you move?",0, (board.size()-1));
    while (!isLegal(board, move))
    {
         cout << "\nOccupied square. Pick another.";
         move = askNumber("Where will you move?", 0, (board.size()-1));
    }
    cout << "Valid move.";

    return move;
}

int computerMove( vector <char> board, char computer){
    unsigned int move = 0;
    bool found = false;

    while (!found && move < board.size())
    {
        if (isLegal(board, move))
        {
            board[move] = computer;
            found = winner(board) == computer;
            board[move] = EMPTY;
        }
        if (!found){
            ++move;
        }

        if (!found)
        {
        move = 0;
        unsigned int i = 0;
        const int BEST_MOVES[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
        //pick best open square
        while (!found && i < board.size())
        {
        move = BEST_MOVES[i];
        if (isLegal(board, move))
        {
        found = true;
        }
        ++i;
        }
        }
        
    }
   return move; 
}

void announceWinner(char winner, char computer, char human){
    if (winner == computer)
    {
        cout << "computer wins\n";
    }
    else if (winner == human)
    {
        cout << "Human wins\n";
    }
    else{
        cout << "Its a tie";
    }
}

char togglePlayer(char current) {
    return current = (current == X) ? O : X;
}