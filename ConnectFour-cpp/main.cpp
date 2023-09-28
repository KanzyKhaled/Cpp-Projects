#include <iostream>

using namespace std;
const int N = 6;
const int M = 7;
char grid[N][M];
int height;
int width;

//This function prints the grid of Connect Four Game as the game progresses
void print_grid() {
    cout << "Player 1 : X  vs Player 2 : O"<< endl;
	cout << "--";
	for (int i = 0; i < M; cout << "---", i++);
	cout << "--\n";
	for (int i = 0; i < N; i++) {
		cout << "|  ";
		for (int j = 0; j < M; j++)
			cout << grid[i][j] << "  ";
		cout << "|\n";
		cout << "--";
		for (int i = 0; i < M; cout << "---", i++);
		cout << "--\n";
	}


}


//This function checks if the game has a win state or not
bool check_win() {
	height =  N;
	width = M;
//columns
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height - 3; y++) {
			if (grid[x][y] == grid[x][y + 1] && grid[x][y] == grid[x][y + 2] && grid[x][y] == grid[x][y + 3] && grid[x][y] != '.') {
				return true;
			}
		}
	}
//rows
	for (int x = 0; x < height; x++) {
		for (int y = 0; y < width - 3; y++) {
			if (grid[x][y] == grid[x + 1][y] && grid[x][y] == grid[x + 2][y] && grid[x][y] == grid[x + 3][y] && grid[x][y] != '.') {
				return true;
			}
		}
	}
//digonal
	for (int x = 0; x < width - 3; x++) {
		for (int y = 3; y < height; y++) {
			if (grid[x][y] == grid[x + 1][y - 1] && grid[x][y] == grid[x + 2][y - 2] && grid[x][y] == grid[x + 3][y - 3] && grid[x][y] != '.'){
				return true;

			}
		}
	}

	for (int x = 0; x < width - 3; x++) {
		for (int y = 0; y < height-3; y++) {
			if (grid[x][y] == grid[x + 1][y + 1] && grid[x][y] == grid[x + 2][y + 2] && grid[x][y] == grid[x + 3][y + 3] && grid[x][y] != '.') {
				return true;

			}
		}
	}
	return false;
}

// check tie

bool check_tie()
{
    int c = 0;
    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(grid[i][j] != '.'){
                c++;
            }
        }
    }
    if(c == N * M){
        return true;
    }
    else{
        return false;
    }
}


// check empty
bool check_empty(int i)
{
    if (grid[0][i] == '.'){
        return true;
    }
    else{
        return false;
    }

}

// valid column

bool check_valid_column(int i)
{
    if(-1 < i < M ){
        return true;
    }
    else{
        return false;
    }

}

// set cell
void set_cell(int i , char mark){
    int c = N-1;
	for (int x = 0; x < N; x++) {
		for (int j = 0; j < M; j++) {
			if (grid[c][i] != '.') {
				c--;
			}
			else {
				grid[c][i] = mark;
				break;
			}
		} break;
	}
}

// grid clear
void grid_clear(){
 	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			grid[i][j] = '.';
		}
	}
}

//play game
void play_game(){
	cout << "Connect Four Game!\n";
	cout << "Welcome...\n";
	cout << "============================\n";
	int player = 0;
	char mark;
	while (true)
    {
        //print grid
        print_grid();
        // set mark value based on player
        if(player == 0)
        {
            mark = 'X';
        }
        else{
            mark = 'O';
        }
        // take input from the user
        cout << "Player "<< mark << endl;
        int i;
        cin >> i;
        while(!check_valid_column(i) || !check_empty(i))
        {
                cout << "Enter a valid column index: ";
                cin >> i;
        }
        print_grid();
        //set the input
        set_cell(i, mark);

        if (check_win())
        {
            //"print the grid"
            print_grid();
            cout << "Congrats, Player " << mark << " is won!" << endl;
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
// Main function

int main(){

    for(int i = 0;i<N;i++){
        for (int j = 0;j<M;j++){
            grid[i][j] = '.';
        }
    }
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
return 0;
}
