#include <stdio.h>

int minval(int r, int c, int matrix[5][6])
{
	int min_val;

	min_val = matrix[r][c];
	if (min_val > matrix[r][c + 1])
		min_val = matrix[r][c];
	if (min_val > matrix[r + 1][c])
		min_val = matrix[r + 1][c];
	return (min_val);
}

int notzero(int r, int c, int matrix[5][6]) //con puntatore con malloc
{
	if (matrix[r][c] == 0)
		return (0);
	if (matrix[r + 1][c] == 0)
		return (0);
	if (matrix[r][c + 1] == 0)
		return (0);
	if (matrix[r + 1][c + 1] == 0)
		return (0);
	return (1);
}


int main()
{
	int matrix[5][6]={{1, 0, 1, 0, 1, 0},
					{1, 0, 1, 1, 1, 1},
					{0, 1, 1, 1, 1, 1},
					{0, 0, 1, 1, 1, 1},
					{1, 1, 1, 1, 1, 1}};
	int r;
	int c;
	int i;
	int j;
	int min_val;

	min_val = 0;
	r = 0;
	while (r < 5 - 1)
	{
		c = 0;
		while (c < 6 - 1)
		{
			if (notzero(r, c, matrix))
			{
				min_val = minval(r, c, matrix);
				matrix[r + 1][c + 1] = min_val + 1;
			}
			c++;
		}
		r++;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 6)
		{
			printf("%d ", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}