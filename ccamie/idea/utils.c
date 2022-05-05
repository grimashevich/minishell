#include "minishell.h"

int	ft_isspace(int character)
{
	return ((character >= 9 && character <= 13) || character == 32);
}

size_t	ft_strlen(char *string)
{
	size_t	i;

	i = 0;
	while (string[i] != '\0')
		i += 1;
	return (i);
}

size_t	ft_strlcpy(char *from, char *to, size_t lenght)
{
	size_t	tolenght;
	size_t	i;

	tolenght = ft_strlen(to);
	if (lenght == 0)
		return (tolenght);
	lenght -= 1;
	i = 0;
	while (i < lenght && from[i] != '\0')
	{
		to[i] = from[i];
		i += 1;
	}
	to[i] = '\0';
	return (tolenght);
}

int	ft_strcmp(char *one, char *two)
{
	size_t	i;

	i = 0;
	while (one[i] == two[i] && one[i] != '\0')
		i += 1;
	return ((unsigned char)one[i] - (unsigned char)two[i]);
}

int	ft_strncmp(char *one, char *two, size_t length)
{
	size_t	i;

	if (length == 0)
		return (0);
	length -= 1;
	i = 0;
	while (i < length && one[i] == two[i] && one[i] != '\0')
		i += 1;
	return ((unsigned char)one[i] - (unsigned char)two[i]);
}

char	*ft_substr(char *string, size_t start, size_t length)
{
	char	*new;
	size_t	i;

	i = ft_strlen(string);
	if (i < length)
		length = i - start;
	if (start >= i)
		length = 0;
	new = (char *)malloc(sizeof(char) * (length + 1));
	if (new == NULL)
		return (NULL);
	new[length] = '\0';
	ft_strlcpy(string + start, new, length + 1);
	return (new);
}
