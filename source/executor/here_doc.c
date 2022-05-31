/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccamie <ccamie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 07:53:06 by ccamie            #+#    #+#             */
/*   Updated: 2022/05/31 08:17:48 by ccamie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	here_doc(char *stop_word)
{
	char	*buffer;
	int		read_len;
	int		stop_word_len;
	int		tmp_file_fd;

	stop_word_len = ft_strlen(stop_word);
	buffer = malloc(stop_word_len + 2);
	if (! buffer)
		exit(1);
	tmp_file_fd = open(HEREDOC_TMP_FILENAME, \
		O_WRONLY | O_CREAT | O_TRUNC, 0664);
	while (1)
	{
		read_len = read(0, buffer, stop_word_len + 2);
		if (read_len - 1 == stop_word_len
			&& ft_strncmp(buffer, stop_word, read_len - 1) == 0)
			break ;
		write(tmp_file_fd, buffer, read_len);
	}
	free(buffer);
	close(tmp_file_fd);
	tmp_file_fd = open(HEREDOC_TMP_FILENAME, O_RDONLY);
	return (tmp_file_fd);
}
