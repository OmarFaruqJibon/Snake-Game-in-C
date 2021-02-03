#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define UP 0x48
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d\

#define height 20 //height of the border
#define width 20 //width of the border

//defining some global variables
int x, y, fruitX, fruitY, score = 0;
int gameOver, flag;
int tailX[100], tailY[100], count = 0;

void setup()
{
	gameOver = 0;
	x = width / 2;
	y = height / 2;

	//generating snake's food
level1:
	fruitX = rand() % 20;
	if (fruitX == 0)
		goto level1;
level2:
	fruitY = rand() % 20;
	if (fruitY == 0)
		goto level2;
}
//function for drawing borders and characters
void draw()
{
	int i, j, k;

	system("cls");
	printf("\t\t\tWELCOME TO SNAKE GAME\n\n");
	printf("\tPress key UP(W),DOWN(S),LEFT(A),RIGHT(D) For Movement.\n\n");
	for (i = 0; i < width; i++) {
		for (j = 0; j < height; j++) {
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
				printf("*");
			}
			else {
				if (i == x && j == y) {
					printf("0");
				}
				else if (i == fruitX && j == fruitY) {
					printf("F");
				}
				else {
					int c = 0;
					for (k = 0; k < count; k++) {
						if (i == tailX[k] && j == tailY[k]) {
							printf("o");
							c = 1;
						}
					}
					if (c == 0) {
						printf(" ");
					}
				}
			}
		}
		printf("\n");
	}
	printf("Score: %d\n", score);
}
//function for getting input from the keyboard
void input()
{
	if (_kbhit()) {
		switch (_getch())
		{
			if (_getch() == 0xe0 || _getch() == 0)
			{
		case UP:
			flag = 3;
			break;
		case DOWN:
			flag = 4;
			break;
		case RIGHT:
			flag = 2;
			break;
		case LEFT:
			flag = 1;
			break;
			}
			else {
		case 'a':
			flag = 1;
			break;
		case 'd':
			flag = 2;
			break;
		case 'w':
			flag = 3;
			break;
		case 's':
			flag = 4;
			break;
		case 'x':
			gameOver = 1;
			break;
			}
		}
	}
}

//main logic part of the game
void makeLogic()
{
	int i;
	int preX = tailX[0];
	int preY = tailY[0];
	int preX2, preY2;

	tailX[0] = x;
	tailY[0] = y;

	for (i = 1; i < count; i++) {
		preX2 = tailX[i];
		preY2 = tailY[i];
		tailX[i] = preX;
		tailY[i] = preY;
		preX = preX2;
		preY = preY2;
	}
	switch (flag)
	{
	case 1:
		y--;
		break;
	case 2:
		y++;
		break;
	case 3:
		x--;
		break;
	case 4:
		x++;
		break;
	default:
		break;
	}
	if (x<0 || x>width || y<0 || y>height) {
		gameOver = 1;
	}
	for (i = 0; i < count; i++) {
		if (x == tailX[i] && y == tailY[i]) {
			gameOver = 1;
		}
	}
	if (x == fruitX && y == fruitY) {

	level3:
		fruitX = rand() % 20;
		if (fruitX == 0)
			goto level3;
	level4:
		fruitY = rand() % 20;
		if (fruitY == 0)
			goto level4;
		score++;
		count++;
	}
}
int main()
{
	int m, n;
	char ch;
levelZero:
	setup();

	while (!gameOver) {
		draw();
		input();
		makeLogic();
	}
	for (m = 0; m < 1000; m++) {
		for (n = 0; n < 10000; n++) {
			//empty loop for controlling snake speed

		}
	}
	for (m = 0; m < 100; m++) {
		for (n = 0; n < 1000; n++) {
			//empty loop for controlling snake speed
		}
	}
	printf("\n\t GAME OVER \n");
	printf("\nPrint Y to Continue Again..");
	for (m = 0; m < 10; m++) {
		scanf("%c", &ch);
		if (ch == 'y' || ch == 'Y')
			goto levelZero;
	}

	printf("\n\n");
	return 0;
}
