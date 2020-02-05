#include<iostream>
#include<fstream>
using namespace std;

#define MAX_DIM 200 //Max dimention is 200 x 200
bool done = false; //boolean to check if the maze is solved
char board[MAX_DIM][MAX_DIM]; //two dimensional array which holds the maze

/**
*
*printMaze - print current maze
*@param - two dimentional array which holds maze, size of rows, size of colums
*
**/

void printMaze(char theMaze[MAX_DIM][MAX_DIM], int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)//specify the row
	{
		for (j = 0; j < cols; j++)//specify the colum
		{
			cout << theMaze[i][j];//print out the speficied character
		}
		cout << endl;//generate a new line when change a row
	}


}


/**
*
*solve - solve the maze using recursion
*@param - two dimentional array which holds maze, current row's position, current colum's position,
*size of rows, size of colums, row's end point, colum's end point
**/
void solve(char maze[MAX_DIM][MAX_DIM], int r, int c, int rows, int cols, int endr, int endc) {
	
	if (r == endr && c == endc) { //if you reache the ending position
		printMaze(maze, rows, cols); //print the solution
		done = true; //the maze is solved!
	}
	else { //if the maze is still in progress...
		if (r > 0 && maze[r - 1][c] == '+') // try the spot to the north if the spot is open
		{
			maze[r - 1][c] = '*'; //show that this path is a part of the solution
			solve(maze, r - 1, c, rows, cols, endr, endc); //examine next spot using recursion
			maze[r - 1][c] = 'B'; // show that this spot is already visited
		}
		if (c < cols && maze[r][c + 1] == '+') // try the spot to the east if the spot is open
		{
			maze[r][c + 1] = '*';//show that this path is a part of the solution
			solve(maze, r, c + 1, rows, cols, endr, endc);//examine next spot using recursion
			maze[r][c + 1] = 'B';// show that this spot is already visited
		}
		if (maze[r + 1][c] == '+') // try the spot to the south if the spot is open
		{
			maze[r + 1][c] = '*';//show that this path is a part of the solution
			solve(maze, r + 1, c, rows, cols, endr, endc);//examine next spot using recursion
			maze[r + 1][c] = 'B';// show that this spot is already visited
		}
		if (c > 0 && maze[r][c - 1] == '+') // try the spot to the west if the spot is open
		{
			maze[r][c - 1] = '*';//show that this path is a part of the solution
			solve(maze, r, c - 1, rows, cols, endr, endc);//examine next spot using recursion
			maze[r][c - 1] = 'B';// show that this spot is already visited
		}
		
	}
}



int main() {

	//go to properties, select debugging, change working directory "Desktop"
	string filename;

	cout << "Please enter the name of an input file: ";//ask the user to enter the name of an input file
	cin >> filename;//readn the input file

	ifstream fileReader(filename);

	if (!fileReader)
	{
		cerr << "Invalid input file? " << filename << endl;//showed when the input file is invalid
		return 1;
	}

	int rows, colums, startR, startC, endR, endC;//size of rows, colums, and start and end positions


	while (fileReader)//read the data
	{

		fileReader >> rows >> colums >> startR >> startC >> endR >> endC;//read each data from the input file

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < colums; ++j) {
				fileReader >> board[i][j];//read the data into the two dimensional array 
			}
		}
	}



	printMaze(board, rows, colums);//print the original maze

	cout << endl << endl << endl;//generate some space

	
	board[startR][startC] = '*';//show the start position
	solve(board, startR, startC, rows, colums, endR, endC);//solve the maze!

	if (!done)//is the solver could not solve the maze
		cout << "NO SOLUTION FOUND" << endl << endl;


	return 0;




}
