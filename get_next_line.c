/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:01:51 by soutchak          #+#    #+#             */
/*   Updated: 2023/11/17 22:07:22 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_add_to_line(t_line **line, char *buffer, int bytes)
{
	t_line	*new_node;
	char	*s;

	if (!buffer || !bytes)
		return (1);
	new_node = (t_line *)malloc(sizeof(t_line));
	if (!new_node)
		return (0);
	s = (char *)malloc(sizeof(char) * (bytes + 1));
	if (!s)
		return (free(new_node), 0);
	s = ft_strlcpy(s, buffer, bytes + 1);
	new_node->block = s;
	new_node->size = (size_t)bytes;
	new_node->next = NULL;
	ft_lst_add_back(line, new_node);
	return (1);
}

size_t	ft_get_line_size(t_line *line, int eof)
{
	size_t	len;
	size_t	i;
	t_line	*tmp;

	tmp = line;
	len = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->block[i])
		{
			if (tmp->block[i] == '\n')
				return (len + 1);
			len++;
			i++;
		}
		tmp = tmp->next;
	}
	if (eof)
		return (len);
	return (0);
}

static char	*ft_copy_line(char *ret_line, t_line *line, size_t size)
{
	size_t	i;
	size_t	j;
	t_line	*tmp;

	if (!ret_line || !line)
		return (NULL);
	i = 0;
	tmp = line;
	while (tmp && i < size)
	{
		j = 0;
		while (tmp->block[j])
		{
			ret_line[i++] = tmp->block[j];
			if (tmp->block[j++] == '\n')
				break ;
		}
		tmp = tmp->next;
	}
	ret_line[i] = '\0';
	return (ret_line);
}

static char	*ft_get_one_line(t_line **line, int eof)
{
	char	*ret_line;
	size_t	size;

	if (!line || !*line || !(*(line))->block)
		return (NULL);
	size = ft_get_line_size(*line, eof);
	if (!size)
		return (NULL);
	ret_line = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret_line)
		return (NULL);
	ret_line = ft_copy_line(ret_line, *line, size);
	*line = ft_free_line(line);
	return (ret_line);
}

char	*get_next_line(int fd)
{
	static t_line	*line;
	char			*buffer;
	char			*ret_line;
	int				bytes;

	if (fd < 0 || BUFFER_SIZE > (size_t)-1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buffer)
		return (ft_lstclear(&line), NULL);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1 || !ft_add_to_line(&line, buffer, bytes))
			return (ft_lstclear(&line), free(buffer), NULL);
		ret_line = ft_get_one_line(&line, (bytes == 0));
		if (ret_line)
			return (free(buffer), ret_line);
	}
	return (ft_lstclear(&line), free(buffer), NULL);
}
