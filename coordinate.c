#include <stdio.h>

typedef struct point {
	int x;
	int y;
}
point;

int main(int argc, char* argv[])
{
	// Get x y coordinates and plot a point accordingly

	point dot;

	printf("Enter x coordinate: ");
	scanf("%i", &dot.x);
	printf("Enter y coordinate: ");
	scanf("%i", &dot.y);
	
	// Plot the point	
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
	return 0;
}
