//     This program generates memory game. User chooses 2 labels, and program
//     shows what numbers are hidden there. The process ends only when user
//     finds all the matching cards.
//
//****************************************************************************************************

#include <iostream>

const int ROWS = 4;
const int COLS = 4;

void showLabels(const int[][COLS]);
void readLabels(int& , int& );
void findIndexByLabel(const int [][COLS], const int , int & , int &);
void showResult(const int [][COLS], const int , const int , const int , const int );
void changeLabels(int [][COLS], int [][COLS], const int , const int , const int , const int );
bool checkGameEnded(const int [][COLS]);

using namespace std;

//****************************************************************************************************

int main()
{
	int cards[ROWS][COLS] = {
		{8, 6, 12, 8},
		{10, 0, 6, 10},
		{4, 14, 2, 12},
		{2, 14, 4, 0}
	};

	int labels[ROWS][COLS] = {
		{0, 1, 2 ,3},
		{4, 5, 6, 7},
		{8, 9, 10, 11},
		{12, 13, 14, 15}
	};

	
	int firstLabel = 0,
	    secondLabel = 0,	
	    firstCardRaw = 0,
	    firstCardColumn = 0,
	    secondCardRaw = 0,
	    secondCardColumn = 0;


	while (!checkGameEnded(cards))
	{
		showLabels(labels);
		readLabels(firstLabel, secondLabel);
		findIndexByLabel(labels, firstLabel, firstCardRaw, firstCardColumn);
		findIndexByLabel(labels, secondLabel, secondCardRaw, secondCardColumn);
		showResult(cards, firstCardRaw, firstCardColumn, 
			secondCardRaw, secondCardColumn);
		changeLabels(labels,cards, firstCardRaw, firstCardColumn, 
			secondCardRaw, secondCardColumn);
	}

	return 0;
}

//****************************************************************************************************

void showLabels(const int labels[][COLS])
{
	cout << "The following numbers show the label of each card.\n"
		<< "The value of each card is hidden under the label.\n"
		<< "Please Pick two cards.\n";
	cout << endl;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << labels[i][j] << "\t";
		}
		cout << "\n" << endl;
	}
}

//****************************************************************************************************

void readLabels(int & first, int & second)
{
	cin >> first;
	cin >> second;
	cout << endl;
}

//****************************************************************************************************

void findIndexByLabel(const int labels[][COLS], const int label, 
	int & raw, int & column)
{

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (labels[i][j] == label)
			{
				raw = i;
				column = j;
				break;
			}
		}
	}
}

//****************************************************************************************************

void showResult(const int cards[][COLS], const int firstCardRaw, 
	const int firstCardColumn, const int secondCardRaw, 
	const int secondCardColumn)
{
	cout << "please see the value of each card you picked.\n";

	if (cards[firstCardRaw][firstCardColumn] == 
		cards[secondCardRaw][secondCardColumn])
	{
		cout << "It's a match.\n";
	}
	else
	{
		cout << "It's not a match.\n";
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if ((i == firstCardRaw && j == firstCardColumn) ||
				(i == secondCardRaw && j == secondCardColumn))
			{
				cout << cards[i][j] << "\t";
			}
			else
			{
				cout << "*" << "\t";
			}
		}

		cout << endl;
	}
}

//****************************************************************************************************

void changeLabels(int labels[][COLS], int cards[][COLS], 
	const int firstCardRaw, const int firstCardColumn, 
	const int secondCardRaw, const int secondCardColumn)
{

	if (cards[firstCardRaw][firstCardColumn] == 
		cards[secondCardRaw][secondCardColumn])
	{
		labels[firstCardRaw][firstCardColumn] = -1;
		labels[secondCardRaw][secondCardColumn] = -1;
	}
}

//****************************************************************************************************

bool checkGameEnded(const int labels[][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (labels[i][j] != -1)
			{
				return false;
			}
		}		
	}

	cout << "You found all the matches.\n";
	return true;
}

//****************************************************************************************************
/*

The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.

0       1       2       3

4       5       6       7

8       9       10      11

12      13      14      15

0 3

please see the value of each card you picked.
It's a match.
8       *       *       8
*       *       *       *
*       *       *       *
*       *       *       *
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.

-1      1       2       -1

4       5       6       7

8       9       10      11

12      13      14      15

1 2

please see the value of each card you picked.
It's not a match.
*       6       12      *
*       *       *       *
*       *       *       *
*       *       *       *
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.

-1      1       2       -1

4       5       6       7

8       9       10      11

12      13      14      15

5 15

please see the value of each card you picked.
It's a match.
*       *       *       *
*       0       *       *
*       *       *       *
*       *       *       0
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.

-1      1       2       -1

4       -1      6       7

8       9       10      11

12      13      14      -1

4 7

please see the value of each card you picked.
It's a match.
*       *       *       *
10      *       *       10
*       *       *       *
*       *       *       *
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.

-1      1       2       -1

-1      -1      6       -1

8       9       10      11

12      13      14      -1

2 11

please see the value of each card you picked.
It's a match.
*       *       12      *
*       *       *       *
*       *       *       12
*       *       *       *
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.

-1      1       -1      -1

-1      -1      6       -1

8       9       10      -1

12      13      14      -1

10 12

please see the value of each card you picked.
It's a match.
*       *       *       *
*       *       *       *
*       *       2       *
2       *       *       *
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.

-1      1       -1      -1

-1      -1      6       -1

8       9       -1      -1

-1      13      14      -1

1 6

please see the value of each card you picked.
It's a match.
*       6       *       *
*       *       6       *
*       *       *       *
*       *       *       *
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.

-1      -1      -1      -1

-1      -1      -1      -1

8       9       -1      -1

-1      13      14      -1

8 13

please see the value of each card you picked.
It's not a match.
*       *       *       *
*       *       *       *
4       *       *       *
*       14      *       *
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.

-1      -1      -1      -1

-1      -1      -1      -1

8       9       -1      -1

-1      13      14      -1

8 14

please see the value of each card you picked.
It's a match.
*       *       *       *
*       *       *       *
4       *       *       *
*       *       4       *
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.

-1      -1      -1      -1

-1      -1      -1      -1

-1      9       -1      -1

-1      13      -1      -1

9 13

please see the value of each card you picked.
It's a match.
*       *       *       *
*       *       *       *
*       14      *       *
*       14      *       *
The following numbers show the label of each card.
The value of each card is hidden under the label.
Please Pick two cards.

-1      -1      -1      -1

-1      -1      -1      -1

-1      -1      -1      -1

-1      -1      -1      -1

You found all the matches.

*/
