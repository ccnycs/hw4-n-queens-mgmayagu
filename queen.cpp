//Given an integer n, return all distinct solutions to the n-queens puzzle. 
//Each solution contains a distinct board configuration of the n-queens' placement , 
//where "Q" and '.' both indicate a queen and an empty space respectivwly .

/*
1- Initialize a stack where we can keep track of our decisions.
2- Place the first queen, pushing its position onto the stack and setting filled to 0.
3- Repeat these steps
    -if there are no conflicts with the queens...
        Increase filled by 1. If filled is noow N, then the algorith is done.
        Otherwise, move to the next row and place a queen in the first column

    -else if there is a conflict and there is room to shift the current queen rightward...
        Move the current queen rightward, adjusting the record on top of the stack to indicate the new position.
    
    -else if there is a conflict and there is NO room to shift the current queen rightward...
        Backtrack! Keep popping the stack, and reducing filled by 1, until you reach a row where the queen can be shifted rightward. 
        Shift this queen right.

*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool solveNQueen(vector<vector<string> > board, stack< vector < vector <string> > > &s, int row, int column, int n);
//precondition: 2-D vector, n - has to be positive positive size, isSafe funtion to return whether a the position is valid
//postcondition: uses recursion and the print function to print all the possible solutions to the nxn queen's problem 

bool isSafe(vector< vector<string> > board, int row, int col);
//Precondition: a 2D vector of stirng , positive rows and positive col
//Postcondition:true if the position of queen is valid, false other wise

void print(stack < vector < vector <string> > > s);
//Precondition: stack of the 2D vecor 
//Poscondition: prints the solution for nxn queen 

int main() {
    cout << "What are the dimension of the board: " << endl;
    int n;
    cin >> n;
    vector<vector<string> > board( n, vector<string>(n,"."));
    stack <vector<vector<string> > > s; //stack of all the soltions
    solveNQueen(board,s,0,0,n);
    print(s);
}

bool solveNQueen(vector<vector<string> > board, stack< vector < vector <string> > > &s, int row, int column, int n) {
    if (row == n){
        s.push(board);
        return false;
    }
   //recursive case 
   for (int column = 0; column < n; column++) {
       //check if i,j is safe
        if(isSafe(board, row, column)) {
            //place the queen
            board[row][column] = "Q";
            if (solveNQueen(board, s, row + 1, column, n))
                return true;
            board[row][column] = "_";
        }
    }
    return false;
}

bool isSafe(vector< vector<string> > board, int row, int col) {
    int i,j;
    for (i = 0; i < row; i++) 
        if (board[i][col] == "Q") 
      return false;
    
    for (i = row, j = col; (i >= 0) && (j >= 0); i--, j--) //stop when its less than the dimension
        if (board[i][j] == "Q")
            return false;

    for (i = row, j = col; (j < board.size()) && (i >= 0); i--, j++)
        if (board[i][j] == "Q")
            return false;
    return true;
}

void print(stack < vector < vector <string> > > s) {
    while(!s.empty()){
        vector < vector <string> > board = s.top();
        for (int row = 0; row < board.size(); row++) {
            for (int column = 0; column<board.size(); column++) {
                if (board[row][column] == "Q")
                    cout << "Q ";
                else 
                  cout << "_ ";
            }
            cout << endl;
        }
        s.pop();
        cout << endl;
    }   
}