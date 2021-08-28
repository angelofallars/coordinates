#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\033[H\033[J")

typedef struct point {
	int x;
	int y;
}
point;

typedef struct node {
	int x;
	int y;
	char* next;
}
node;

void plot_point(point dot);

int main(int argc, char* argv[])
{
	// Control a point in a box, moving it around
	point dot;
	char key;

	// Boundaries of the box
	int min_x = 0;
	int max_x = 20;
	int min_y = 0;
	int max_y = 10;

	// Place the point in the middle of the box 
	dot.x = (min_x + max_x) / 2;
	dot.y = (min_y + max_y) / 2;
	
	// Plot the point	
	plot_point(dot);

	// Go into RAW mode to avoid having to press enter
	system("/bin/stty raw");

	// Ask the user for WASD controls to control the dot
	do 
	{
		key = getchar();
		putchar(key);

		switch(key)
		{
			case 'w' :
				if (dot.y > min_y)
				{
					dot.y--;
				}
				break;

			case 'a' :
				if (dot.x > min_x)
				{
					dot.x--;
				}
				break;

			case 's' :
				if (dot.y < max_y)
				{
					dot.y++;
				}
				break;

			case 'd' :
				if (dot.x < max_x)
				{
					dot.x++;
				}
				break;

			default :
				break;
		}		

		plot_point(dot);
	}
	while (key != '.');

	clear();
	return 0;
}

void plot_point(point dot)
{
	/* Plot a point, moving right as x increases and
	                 moving down as y increases      */
	clear();

	for (int i = 0; i < dot.y; i++)
	{
		printf("\n");
	}

	for (int i = 0; i < dot.x; i++)
	{
		printf(" ");
	}

	printf("#");
	printf("\n");

	return;
}

