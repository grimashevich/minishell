#include "minishell.h"

static int	last_character(char *string)
{
	if (*string == '\0')
	{
		return (-1);
	}
	printf("\x1b[33mLast character:\x1b[0m %d\n", string[ft_strlen(string) - 1]);
	return (string[ft_strlen(string) - 1]);
}

void	remove_insignificant_spases(char **line)
{
	char	*temporary;
	int		start;
	int		lenght;

	if (!(ft_isspace(**line) == TRUE || ft_isspace(last_character(*line)) == TRUE))
		return ;
	temporary = *line;
	start = 0;
	while (ft_isspace(temporary[start]) == TRUE)
	{
		start += 1;
	}
	lenght = ft_strlen(temporary) - 1;
	while (ft_isspace(temporary[lenght]) == TRUE)
	{
		lenght -= 1;
	}
	lenght += 1;
	*line = ft_substr(temporary, start, lenght - start);
	if (*line == NULL)
	{
		perror(NULL);
		exit(1);
	}
	free(temporary);
	printf("\x1b[33mStart:\x1b[0m %d\n", start);
	printf("\x1b[33mLenght:\x1b[0m %d\n", lenght - start);
	printf("\x1b[33mRemove insignificant spases:\x1b[0m %s\n", *line);
}

void	remove_insignificant_brackets(char **line)
{
	char	*temporary;

	if (!(**line == '(' && last_character(*line) == ')'))
		return ;
	temporary = *line;
	*line = ft_substr(temporary, 1, ft_strlen(temporary) - 2);
	if (*line == NULL)
	{
		perror(NULL);
		exit(1);
	}
	free(temporary);
	printf("\x1b[33mRemove insignificant brackets:\x1b[0m %s\n", *line);
	remove_insignificant_spases(line);
}
