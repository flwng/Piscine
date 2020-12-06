#include "ft_free.h"

int		free_matrix(int **matrix, int len)
{
	int i;

	i = -1;
	if (matrix)
	{
		while (++i < len)
			if (matrix[i])
				free(matrix[i]);
		free(matrix);
	}
	return (0);
}