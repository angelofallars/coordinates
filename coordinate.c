#include <stdio.h>

#define clear() printf("\033[H\033[J")

typedef struct point {
	int x;
	int y;
}
point;

void plot_point(point dot);

int main(int argc, char* argv[])
{
	// Get x y coordinates and plot a point accordingly

	point dot;
	char key;

	printf("Enter x coordinate: ");
	scanf("%i", &dot.x);
	printf("Enter y coordinate: ");
	scanf("%i", &dot.y);
	
	// Plot the point	
	plot_point(dot);

	// Go into RAW mode to avoid having to press enter
	system ("/bin/stty raw");

	// Ask the user for WASD controls to control the dot
	do 
	{
		key = getchar();
		putchar(key);

		switch(key)
		{
			case 'w' :
				dot.y--;
				break;
			case 'a' :
				dot.x--;
				break;
			case 's' :
				dot.y++;
				break;
			case 'd' :
				dot.x++;
				break;
			default :
				break;
		}		

		plot_point(dot);
	}
	while (key != '.');

	printf("\n");
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

