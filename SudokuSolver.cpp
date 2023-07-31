#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

const int n =9;

bool issafe(int board[n][n],int row,int col,int num)
{
	
	//check if num is already in the same row
	for(int i=0;i<n;i++)
	{
		if(board[row][i]==num)
		return false;
	//check if num is already in the same column	
		else if(board[i][col]==num)
		return false;
	}
	
	//check if num is already in the same box of 3X3
	int boxrow=row-row%3;
	int boxcol=col-col%3;
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i+boxrow][j+boxcol]==num)
			return false;
		}
	}
	return true;
}


void printboard(int board[n][n])
{
	system("cls");
	cout<<"\t\t\tWELCOME TO THE SUDOKU WORLD"<<endl;
	cout<<"\t\t\tFind the missing numbers(represented by zero)to solve the puzzle"<<endl;
	for(int row=0;row<n;row++)
	{
		for(int col=0;col<n;col++)
		{
			if(col==3||col==6)
			cout<<"|";
			cout<<board[row][col]<<" ";	
		}
		if(row==2||row==5)
		{
			cout<<endl;
			for(int i=0;i<n;i++)
			cout<<"___";
		}
		cout<<endl;
	}
}

bool solvesudoku(int board[n][n],int row,int col)
{
	
	//if cells are filled the puzzle is solved
	if(row==n-1 && col==n)
	return true;
	
	//move to the next row if the current column is n
	if(col==n)
	{
		row++;
		col=0;
	}
	
	//skip the cell that already has value 
	if(board[row][col]!=0)
	return (solvesudoku(board,row,col+1));
	
	//try filling the current cell with a number from 1 to 9
	for(int num=1;num<=9;num++)
	{
		if(issafe(board,row,col,num))
		{
			board[row][col]=num;
			
			if(solvesudoku(board,row,col+1))
			return true;
			
			board[row][col]=0;
		}
	}
	return false;
}

bool issolvedcompletely(int board[n][n]) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == 0) {
                return false;
            }
        }
    }
    return true;
}

/*bool issolvedcompletely(int board[n][n])
{
	for(int row=0;row<n;row++)
	{
		for(int col=0;col<n;col++)
		{
			if(board[row][col]==0)
			return false;
		}
	}
	return true;
}

/*void playgame(int board[n][n])
{
	int ch;
	int row,col,num;
	while(true)
	{
		printboard(board);
		cout<<endl<<endl;
		cout<<"Unable to solve? Enter -1 as row,col and num to view the solved sudoku."<<endl;
		cout<<"Enter row: ";
		cin>>row;
		cout<<"Enter column: ";
		cin>>col;
		cout<<"Enter number: ";
		cin>>num;
		
		
		if(row==-1 || col==-1 || num==-1)
		{
			solvesudoku(board,0,0);
			printboard(board);
			cout<<endl;
			cout<<"Better luck next time!!!"<<endl;
			return;
		}
		
		if(issolvedcompletely(board))
		break;
		row--;
		col--;
		if(!issafe(board,row,col,num))
		{
			cout<<"Invalid move. Try again."<<endl;
			continue;
		}
		board[row][col]=num;
	}
	
	//check if the user solved it correctly or not
	
	bool solved=true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(board[i][j]==0)
			{
				solved=false;
				break;
			}
		}
	}
	
	if(solved)
	{
		cout<<"Congratulations! You have solved the puzzle."<<endl;
		printboard(board);
	}
	else
	{
		cout<<"Puzzle not solved. Better luck next time."<<endl;
	}
}*/

void playgame(int board[n][n]) {
    int row, col, num;
    while (true) {
        printboard(board);
        cout << endl << endl;
        cout << "Unable to solve? Enter -1 as row, col, and num to view the solved sudoku." << endl;
        cout << "Enter row: ";
        cin >> row;
        cout << "Enter column: ";
        cin >> col;
        cout << "Enter number: ";
        cin >> num;

        if (row == -1 || col == -1 || num == -1) {
            solvesudoku(board, 0, 0);
            printboard(board);
            cout << endl;
            cout << "Better luck next time!!!" << endl;
            return;
        }

        if (issolvedcompletely(board))
            break;

        // Check if the entered row and column are within bounds
        if (row < 1 || row > n || col < 1 || col > n) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Adjust row and column to 0-based indexing
        row--;
        col--;

        if (!issafe(board, row, col, num)) {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row][col] = num;
    }

    // Check if the user solved it correctly or not
    if (issolvedcompletely(board)) {
        cout << "Congratulations! You have solved the puzzle." << endl;
        printboard(board);
    } else {
        cout << "Puzzle not solved. Better luck next time." << endl;
    }
}



int main()
{
	system("title Sudoku Game");
	int board[n][n]=
	{
		{3,0,6,5,0,8,4,0,0},
		{5,2,0,0,0,0,0,0,0},
		{0,8,7,0,0,0,0,3,1},
		{0,0,3,0,1,0,0,8,0},
		{9,0,0,8,6,3,0,0,5},
		{0,5,0,0,9,0,6,0,0},
		{1,3,0,0,0,0,2,5,0},
		{0,0,0,0,0,0,0,7,4},
		{0,0,5,2,0,6,3,0,0}
	};
	
	cout<<"\t\t\tWELCOME TO THE SUDOKU WORLD"<<endl;
	cout<<"\t\t\tFind the missing numbers(represented by zero)to solve the puzzle"<<endl;
	
	while(true)
	{
		int choice;
		cout<<endl<<endl;
		cout<<"\t\t[1] Solve the Sudoku"<<endl;
		cout<<"\t\t[2] Unable to solve? View the solved Sudoku"<<endl;
		cout<<"\t\t[3]Exit"<<endl;
		cout<<"\t\tEnter your choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				playgame(board);
				break;
				
			case 2:
				if(solvesudoku(board,0,0))
				{
					cout<<"Completely Solved Sudoku is: "<<endl;
					cout<<endl<<endl;
					for(int row=0;row<n;row++)
					{
						for(int col=0;col<n;col++)
						{
						if(col==3 ||col==6)
						cout<<"|";
						cout<<board[row][col]<<" ";
					}
					if(row==2 || row==5)
					{
						cout<<endl;
						for(int i=0;i<n;i++)
						cout<<"___";
					}
					cout<<endl;
				}
				cout<<endl;
				cout<<"Better luck next time!!!"<<endl;
		}
		else
		cout<<"No solution found"<<endl;
		break;
		case 3:
			exit(0);
		default:
			cout<<"Invalid choice"<<endl;
	}
	return 0;
}
}