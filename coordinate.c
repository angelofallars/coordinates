#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\033[H\033[J")

typedef struct node {
	int x;
	int y;
	char symbol;
	struct node *next;
}
node;

// Boundaries of the box
int max_x = 20;
int max_y = 10;

void render(char box[][max_y], node *dot);
void free_recursive(node *dot);

int main(int argc, char* argv[])
{
	// Control a point in a box, moving it around
	node *dot = malloc(sizeof(node));
	node *food = malloc(sizeof(node));
	node *food2 = malloc(sizeof(node));

	int score = 0;
	char key;

	// The display box
	char box[max_x][max_y];

	// Place the point in the middle of the box 
	dot->x = (max_x) / 2;
	dot->y = (max_y) / 2;
	dot->symbol = '$';
	dot->next = food;

	food->x = 3;
	food->y = 3;
	food->symbol = '!';
	food->next = food2;

	food2->x = 1;
	food2->y = 1;
	food2->symbol = '@';
	food2->next = NULL;

	render(box, dot);
	printf("Score: %i\n", score);
	printf("wasd to move! Press . to exit!\n");

	// Go into RAW mode to avoid having to press enter
	// system("/bin/stty raw");

	// Ask the user for WASD controls to control the dot
	do 
	{
		key = getchar();
		putchar(key);

		switch(key)
		{
			case 'w' :
				if (dot->y > 0)
				{
					dot->y--;
				}
				break;

			case 'a' :
				if (dot->x > 0)
				{
					dot->x--;
				}
				break;

			case 's' :
				if (dot->y < max_y - 1)
				{
					dot->y++;
				}
				break;

			case 'd' :
				if (dot->x < max_x - 1)
				{
					dot->x++;
				}
				break;

			default :
				break;
		}		

		render(box, dot);
		printf("Score: %i\n", score);
	}
	while (key != '.');

	free_recursive(dot);
	clear();
	return 0;
}

void render(char box[][max_y], node *dot)
{
	clear();

	/* Get a linked list chain, then display all of them*/
	node *n = dot;

	// Blank the box first
	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
		{
			box[j][i] = '.';
		}
	}

	// Iterate through the linked list and add them to the box
	do
	{
		box[n->x][n->y] = n->symbol;	
		n = n->next;
	}
	while (n != NULL);


	// Iterate through the entire box, rendering everything
	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
		{
			printf("%c", box[j][i]);
		}
		printf("\n");
	}
	return;
}

void free_recursive(node *dot)
{
	// Recursively free a linked list with just the head
	if (dot->next == NULL)
	{
		free(dot);
		return;
	}

	free_recursive(dot->next);
	free(dot);
	return;
}
