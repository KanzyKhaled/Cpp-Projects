#include <iostream>

using namespace std;

/*
Assigning values to the grid
The grid will look like this:
  0,0 | 0,1 | 0,2
  1,0 | 1,1 | 1,2
  2,0 | 2,1 | 2,2
*/

const int N = 3;
char grid[N][N];

//---------"print function"------------------------------------------
void printLines()
{
    cout << "   ";
    for(int i = 0; i < N; i++)
    {
        cout << " ---";
    }
    cout << endl;
}

void print_grid()
{
    cout << "Player 1: X  vs  Player 2: O" << endl;
    printLines();
    for(int i = 0; i < N; i++)
    {
        cout << " " ;
        for(int j = 0; j < N; j++)
        {
            cout << " |  ";
            cout << grid[i][j];
        }
        cout << " | "  << endl;
        printLines();
    }

}

//-----------"check win function"--------------------------------
bool check_win(){
    //---"Rows"---
    for (int i=0; i<N; i++){
        int j = 0;
        if(grid[i][j] == grid[i][j + 1] && grid[i][j] == grid[i][j + 2] && grid[i][j] != '.')
        {
            return true;
        }
    }

    //---"Columns"---
     for (int j=0; j<N; j++)
    {
        int i = 0;
        if(grid[i][j] == grid[i + 1][j] && grid[i][j] == grid[i+ 2][j] && grid[i][j] != '.')
        {
            return true;
        }
    }
    //---"Diagonals"---
     if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2] && grid[0][0] != '.')
     {
         return true;
     }

     if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0] && grid[0][2] != '.')
     {
         return true;
     }


     return false;
}
//-----------"check tie function"---------------------------------
bool check_tie()
{
    int c = 0;
    for (int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(grid[i][j] != '.'){
                c++;
            }
        }
    }
    if(c == N * N){
        return true;
    }
    else{
        return false;
    }
}

//---------"check empty Function"--------------------------------

bool check_empty(int i,int j)
{
    if (grid[i][j] == '.'){
        return true;
    }
    else{
        return false;
    }

}
//----------"check valid position function"-----------------------

bool check_valid_position(int i,int j)
{
    if(0 <= i < N && 0 <= j < N){
        return true;
    }
    else{
        return false;
    }

}

//----------"set cell function"-----------------------------------

void set_cell(int i,int  j, char mark)
{
    grid[i][j] = mark;
}

//----------"grid clear function"---------------------------------

void grid_clear()
{
    for(int i = 0;i<N; i++){
        for (int j = 0 ; j< N;j++){
            grid[i][j] = '.';
        }
    }
}

//----------"play game function"---------------------------------
void play_game()
{
    cout << "Tic-Tac-Toe Game!" << endl;
    cout << "Welcome..." << endl;
    cout << "============================" << endl;

    int player = 0;
    char mark;
    while(true){
            //"print grid"
            print_grid();
            //"set mark value based on the player"
            if(player == 0)
            {
                mark = 'X';
            }
            else{
                mark = 'O';
            }
            //"takes input from the user to fill in the grid
            cout << "Player ";
            cout << mark << endl;

            int i, j;
            cin >> i >> j ;
            while(!check_valid_position(i, j) || !check_empty(i, j))
            {
                cout << "Enter a valid row index and a valid column index: ";
                cin >> i >> j ;
            }
            //"Set the input position with the mark"
            set_cell(i,j, mark);
            //"Check if the state of the grid has a win state"
            if (check_win())
            {
                //"print the grid"
                print_grid();
                cout << "Congrats, Player ";
                cout << mark;
                cout << " is won!" << endl;
                break;
            }
            //"Check if the state of the grid has a Tie state"
            if (check_tie())
            {
                //"print the grid"
                print_grid();
                cout << "Woah! That is a tie";
                break;
            }
            //"Player number changes after each turn"
            player = 1 - player;
    }

}

//----------"Main function"---------------------------------------
int main()
{
    //------"grid array"------------
    for(int i = 0;i<N;i++){
        for (int j = 0;j<N;j++){
            grid[i][j] = '.';
        }
    }
    //------" begin of the game"------------
   while(true)
   {


        grid_clear();
        play_game();
        char c;
        cout << "Play Again [Y/N]";
        cin >> c ;
        if(c == 'n' || c == 'N')
        {
            break;
        }

    }
}
