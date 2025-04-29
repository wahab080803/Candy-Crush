#include<iostream>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include"my_pr.h"

using namespace std;

//Shapes of our Game
void printshapes(int a[][8])
{
	int x = 50, y = 50;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (a[i][j] == 1)
				myRectangle(x + 10, y + 10, x + 40, y + 40, 255, 128, 0, 255, 128, 0);//Square
			else if (a[i][j] == 2)
				myRectangle(x + 5, y + 10, x + 45, y + 40, 128, 255, 0, 128, 255, 0);//Rectangle 
			else if (a[i][j] == 3)
				myEllipse(x + 10, y + 10, x + 40, y + 40, 255, 255, 51, 255, 255, 51);//Circle
			else if (a[i][j] == 4)
				myEllipse(x + 2, y + 15, x + 48, y + 40, 0, 255, 255, 0, 255, 255);//Horizontal Oval
			else if (a[i][j] == 5)
				myEllipse(x + 13, y + 2, x + 37, y + 48, 255, 153, 204, 255, 153, 204);//Vertical Oval 
			else if (a[i][j] == 6)
				myEllipse(x + 13, y + 2, x + 37, y + 48, 255, 255, 255, 255, 255, 255);//White Vertical Oval
			else if (a[i][j] == 7)
				myRectangle(x + 5, y + 10, x + 45, y + 40, 0, 0, 255, 0, 0, 255);// Blue Rectangle

			x = x + 50;
		}
		x = 50;
		y = y + 50;
	}
}

//Grid And Background
void printBackground()
{
	myRectangle(0, 0, 1000, 490, 153, 51, 255, 153, 51, 255);//Background
}
void printBoard()
{
	myRectangle(50, 50, 450, 450, 255, 255, 255, 128, 128, 128);//Board
	int data[8][8];

	int y = 50;
	for (int j = 0; j < 4; j++)
	{
		int x = 50;
		for (int i = 0; i < 4; i++)
		{
			myRectangle(x, y, x + 50, y + 50, 255, 255, 255, 64, 64, 64);
			x = x + 100;
		}
		y = y + 100;
	}
	int a = 100;
	for (int j = 0; j < 4; j++)
	{
		int b = 100;
		for (int i = 0; i < 4; i++)
		{
			myRectangle(b, a, b + 50, a + 50, 255, 255, 255, 64, 64, 64);
			b = b + 100;
		}
		a = a + 100;
	}
}


//A function which will only tell if there are 5 combinations
bool Checksame5(int a[][8])
{
	bool b = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j] && a[i][j] == a[i + 3][j] && a[i][j] == a[i + 4][j] && i <= 3) //Columns
			{
				b = 1;
			}
			else if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && a[i][j] == a[i][j + 3] && a[i][j] == a[i][j + 4] && j <= 3) //Rows
			{
				b = 1;
			}
		}
	}
	return b;
}

//Checks 5 combinations and then Create Zero and a Shape 
bool same5(int a[][8])
{
	bool b = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j] && a[i][j] == a[i + 3][j] && a[i][j] == a[i + 4][j] && i <= 3) //Columns
			{
				a[i][j] = 7;//Place a 5 combo candy here
				a[i + 1][j] = 0;
				a[i + 2][j] = 0;
				a[i + 3][j] = 0;
				a[i + 4][j] = 0;
				b = 1;
			}
			else if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && a[i][j] == a[i][j + 3] && a[i][j] == a[i][j + 4] && j <= 3) //Rows
			{
				a[i][j] = 7;//Place a 5 combo candy here
				a[i][j + 1] = 0;
				a[i][j + 2] = 0;
				a[i][j + 3] = 0;
				a[i][j + 4] = 0;
				b = 1;
			}
		}
	}
	return b;
}

//A function which will only tell if there are 4 combinations
bool Checksame4(int a[][8])
{
	bool b = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j] && a[i][j] == a[i + 3][j] && i <= 4) //Columns
			{
				b = 1;
			}
			else if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && a[i][j] == a[i][j + 3] && j <= 4) //Rows
			{
				b = 1;
			}
		}
	}
	return b;
}


//Checks 4 combinations and then Create Zero and a Shape 
bool same4(int a[][8])
{
	bool b = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j] && a[i][j] == a[i + 3][j] && i <= 4) //Columns
			{
				a[i][j] = 6;//Place a 4 combo candy here
				a[i + 1][j] = 0;
				a[i + 2][j] = 0;
				a[i + 3][j] = 0;
				b = 1;
			}
			else if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && a[i][j] == a[i][j + 3] && j <= 4) //Rows
			{
				a[i][j] = 6;//Place a 4 combo candy here
				a[i][j + 1] = 0;
				a[i][j + 2] = 0;
				a[i][j + 3] = 0;
				b = 1;
			}
		}
	}
	return b;
}

//Check for 3
bool same(int a[][8])
{
	bool b = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == a[i + 1][j] && a[i][j] == a[i + 2][j] && i <= 5) //Columns
			{
				a[i][j] = 0;
				a[i + 1][j] = 0;
				a[i + 2][j] = 0;
				b = 1;
			}
			else if (a[i][j] == a[i][j + 1] && a[i][j] == a[i][j + 2] && j <= 5) //Rows
			{
				a[i][j] = 0;
				a[i][j + 1] = 0;
				a[i][j + 2] = 0;
				b = 1;
			}
		}
	}
	return b;
}


//Function for swapping
void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

//It will take zero from certain indexes and then take it to the very first row
void zero(int a[][8], int r, int c)
{
	while (r != 0)
	{
		swap(a[r][c], a[r - 1][c]);
		r--;

	}
}

//It will specify that we have to take zero from which certain indexes
void upper(int a[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (a[i][j] == 0)
			{
				zero(a, i, j);
			}
		}
	}
}


int main()
{
	cout << "These are the rules of game= ";
	cout << "\n 1. Only 10 swapping are allowed" << endl;
	cout << "\n 2. 1100 score is required to win" << endl;
	cout << "\n 3. On 3 matches you will get 100 points" << endl;
	cout << "\n 4. On 4 matches you will get 200 points" << endl;
	cout << "\n 5. On 5 matches you will get 300 points" << endl;
	cout << "\n\n\n Now you can play the game." << endl;
	int num;
	cout << "\n\n Enter any number to start= ";
	cin >> num;

	int data[8][8];


	printBackground();


	printBoard();
	//RandomShapes(int s, int m);
	srand(time(0));
	int m = 50, s = 50;   //m is x component value & s is y component value
	for (int j = 0; j < 8; j++)
	{
		m = 50;
		for (int i = 0; i < 8; i++)
		{
			data[i][j] = rand() % 5 + 1;
			if (data[i][j] == 1)
				myRectangle(m + 10, s + 10, m + 40, s + 40, 255, 128, 0, 255, 128, 0);//Square
			else if (data[i][j] == 2)
				myRectangle(m + 5, s + 10, m + 45, s + 40, 128, 255, 0, 128, 255, 0);//Rectangle 
			else if (data[i][j] == 3)
				myEllipse(m + 10, s + 10, m + 40, s + 40, 255, 255, 51, 255, 255, 51);//Circle
			else if (data[i][j] == 4)
				myEllipse(m + 2, s + 15, m + 48, s + 40, 0, 255, 255, 0, 255, 255);//Horizontal Oval
			else if (data[i][j] == 5)
				myEllipse(m + 13, s + 2, m + 37, s + 48, 255, 153, 204, 255, 153, 204);//Vertical Oval 


			m = m + 50;

		}
		s = s + 50;
	}

	//Movement of Cursor

	int x = 50;
	int z = 50;
	myRectangle2(x, z, x + 50, z + 50, 255, 0, 0);//Cursor function is in the other file and it is represented by myRectangle2
	int x_counter = 0;//How many times cursor move forward in direction of x
	int z_counter = 0;//How many times cursor move forward in direction of z
	int pos = 0;//Which key is pressed
	int limit = 10;//Only 10 swapping are allowed
	int score = 0;//Score which calculates to win
	while (limit != 0)
	{

		//To check whether their is any same candies at the start or not
		while (same(data))
		{

			srand(time(NULL));
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					upper(data);
				}
			}
			for (int i = 0; i < 8; i++)
			{
				m = 50;
				for (int j = 0; j < 8; j++)
				{
					if (data[i][j] == 0)
					{
						data[i][j] = rand() % 5 + 1;
						if (data[i][j] == 1)
						{
							myRectangle(m + 10, s + 10, m + 40, s + 40, 255, 128, 0, 255, 128, 0);//Square
							printBoard();
							printshapes(data);
						}
						else if (data[i][j] == 2)
						{
							myRectangle(m + 5, s + 10, m + 45, s + 40, 128, 255, 0, 128, 255, 0);//Rectangle 
							printBoard();
							printshapes(data);
						}
						else if (data[i][j] == 3)
						{
							myEllipse(m + 10, s + 10, m + 40, s + 40, 255, 255, 51, 255, 255, 51);//Circle
							printBoard();
							printshapes(data);
						}
						else if (data[i][j] == 4)
						{
							myEllipse(m + 2, s + 15, m + 48, s + 40, 0, 255, 255, 0, 255, 255);//Horizontal Oval
							printBoard();
							printshapes(data);
						}
						else if (data[i][j] == 5)
						{
							myEllipse(m + 13, s + 2, m + 37, s + 48, 255, 153, 204, 255, 153, 204);//Vertical Oval 
							printBoard();
							printshapes(data);
						}

						m = m + 50;
					}
					s = s + 50;
				}

			}
		}
		int  h = 0;//Loop for swap
		_getch();
		if (isCursorKeyPressed(pos))
		{
			//Left
			if (x > 50)//As for this x is started from 50
			{
				if (pos == 1)
				{
					myRectangle2(x, z, x + 50, z + 50, 255, 255, 255);
					myRectangle2(x - 50, z, x, z + 50, 255, 0, 0);
					x = x - 50;
					x_counter--;
				}
			}
			//Up
			if (z > 50)//As for this z is started from 50
			{
				if (pos == 2)
				{
					myRectangle2(x, z, x + 50, z + 50, 255, 255, 255);
					myRectangle2(x, z - 50, x + 50, z, 255, 0, 0);
					z = z - 50;
					z_counter--;
				}

			}
			//Right
			if (x < 400)//As for this x is ended at 400
			{
				if (pos == 3)
				{
					myRectangle2(x, z, x + 50, z + 50, 255, 255, 255);
					myRectangle2(x + 50, z, x + 100, z + 50, 255, 0, 0);
					x = x + 50;
					x_counter++;
				}
			}
			//Down
			if (z < 400)//As for this y is ended at 400
			{
				if (pos == 4)
				{
					myRectangle2(x, z, x + 50, z + 50, 255, 255, 255);
					myRectangle2(x, z + 50, x + 50, z + 100, 255, 0, 0);
					z = z + 50;
					z_counter++;
				}
			}
			int dis_x = 50 + x_counter * 50;
			int dis_z = 50 + z_counter * 50;
			//Basically this is added in help.h and when sapce is pressed it will work for swapping
			if (pos == 5)
			{
				while (h == 0)
				{
					_getch();
					if (isCursorKeyPressed(pos))
					{

						if (pos == 3)
						{
							swap(data[z_counter][x_counter], data[z_counter][x_counter + 1]);
							system("cls");
							printBackground();
							printBoard();
							printshapes(data);
							limit--;
						}
						else if (pos == 1)
						{
							swap(data[z_counter][x_counter], data[z_counter][x_counter - 1]);
							system("cls");
							printBackground();
							printBoard();
							printshapes(data);
							limit--;
						}
						else if (pos == 2)
						{
							swap(data[z_counter][x_counter], data[z_counter - 1][x_counter]);
							system("cls");
							printBackground();
							printBoard();
							printshapes(data);
							limit--;
						}
						else if (pos == 4)
						{
							swap(data[z_counter][x_counter], data[z_counter + 1][x_counter]);
							system("cls");
							printBackground();
							printBoard();
							printshapes(data);
							limit--;
						}
					}
					h = 1;//Loop terminator

				}
				//Match for 3 , 4 & 5
				srand(time(NULL));
				if (Checksame5(data) == true)
				{
					same5(data);
					score = score + 300;//If 5 candies match then score will increment by 300
				}
				else if (Checksame4(data) == true)
				{
					same4(data);
					score = score + 200;//If 4 candies match then score will increment by 200
				}
				else if (same(data))
					score = score + 100;//If 3 candies match then score will increment by 100

				for (int i = 0; i < 8; i++)
				{
					for (int j = 0; j < 8; j++)
					{
						upper(data);
					}
				}
				for (int i = 0; i < 8; i++)
				{
					m = 50;
					for (int j = 0; j < 8; j++)
					{
						if (data[i][j] == 0)
						{
							data[i][j] = rand() % 5 + 1;
							if (data[i][j] == 1)
							{
								myRectangle(m + 10, s + 10, m + 40, s + 40, 255, 128, 0, 255, 128, 0);//Square
								printBoard();
								printshapes(data);
							}
							else if (data[i][j] == 2)
							{
								myRectangle(m + 5, s + 10, m + 45, s + 40, 128, 255, 0, 128, 255, 0);//Rectangle 
								printBoard();
								printshapes(data);
							}
							else if (data[i][j] == 3)
							{
								myEllipse(m + 10, s + 10, m + 40, s + 40, 255, 255, 51, 255, 255, 51);//Circle
								printBoard();
								printshapes(data);
							}
							else if (data[i][j] == 4)
							{
								myEllipse(m + 2, s + 15, m + 48, s + 40, 0, 255, 255, 0, 255, 255);//Horizontal Oval
								printBoard();
								printshapes(data);
							}
							else if (data[i][j] == 5)
							{
								myEllipse(m + 13, s + 2, m + 37, s + 48, 255, 153, 204, 255, 153, 204);//Vertical Oval 
								printBoard();
								printshapes(data);

							}
							m = m + 50;
						}

						s = s + 50;
					}
				}

			}
		}
	}
	system("cls");
	if (score > 1000)
	{
		cout << score << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!You are the winner!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n\n\n\n\n\n\n\n\n" << endl;
	}
	else
	{
		cout << score << endl;
		cout << "\n\n\n\n\n\n\n\n\n\n\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!You are not the winner!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\n\n\n\n\n\n\n\n\n" << endl;
	}


	_getch();
	return 0;
}