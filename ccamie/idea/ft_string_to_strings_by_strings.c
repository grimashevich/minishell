#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(char *string);
char	*ft_substr(char *string, size_t start, size_t length);
int		ft_strncmp(char *one, char *two, size_t length);

int	ft_strings_cmp(char **string, char **strings)
{
	while (*strings != NULL)
	{
		printf("%s\n", *string);
		if (ft_strncmp(*string, *strings, ft_strlen(*strings)) == 0)
		{
			*string += ft_strlen(*strings);
			return (0);
		}
		strings++;
	}
	return (-1);
}

static size_t	get_count(char *string, char **splitter)
{
	size_t	count;

	count = 0;
	while (*string != '\0')
	{
		if (ft_strings_cmp(&string, splitter) == 0)
		{
			count += 1;
		}
		else
		{
			string += 1;
		}
	}
	return (count);
}

static int	fill_in_strings(char **strings, char *string, char **splitter)
{
	int	i;

	i = 0;
	printf("----------------\n");
	while (string[i] != '\0')
	{
		if (ft_strings_cmp(&(string), splitter) == 0)
		{
			printf("hey\n");
			*strings = ft_substr(string, 0, i);
			if (*strings == NULL)
				return (-1);
			strings++;
			string += i;
			i = 0;
		}
		else
		{
			i += 1;
		}
	}
	*strings = NULL;
	return (0);
}

char	**ft_string_to_strings(char *string, char **splitter)
{
	size_t	count;
	char	**strings;

	if (string == NULL)
		return (NULL);
	if (splitter == NULL)
		return (NULL);
	count = get_count(string, splitter);
	printf("%zu\n", count);
	strings = (char **)malloc((count + 1) * sizeof(char *));
	if (strings == NULL)
		return (NULL);
	if (fill_in_strings(strings, string, splitter) == -1)
	{
		// ft_strings_remove_all(&strings);
		return (NULL);
	}
	return (strings);
}

int	main(void)
{
	char	*line = "echo 1 && echo 2 || echo 3";
	char	*splitter[5];
	char	**strings;

	splitter[0] = "&&";
	splitter[1] = "||";
	splitter[2] = "|";
	splitter[3] = ";";
	splitter[4] = NULL;
	strings = ft_string_to_strings(line, splitter);
	printf("%s\n", strings[0]);

}
