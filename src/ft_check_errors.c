
#include "fillit.h"

int		ft_check_1piece(char *str_piece)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 == 4 && str_piece[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
