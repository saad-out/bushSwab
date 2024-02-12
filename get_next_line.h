/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:57:46 by soutchak          #+#    #+#             */
/*   Updated: 2024/02/11 23:51:07 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_line {
	char			*block;
	size_t			size;
	struct s_line	*next;
}	t_line;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif /* BUFFER_SIZE */

# ifndef INVALID_FD
#  define INVALID_FD -1
# endif /* INVALID_FD */

char	*get_next_line(int fd);
void	ft_lstclear_line(t_line **line);
char	*ft_strlcpy_line(char *dest, char *src, size_t dsize);
void	ft_lst_add_back(t_line **line, t_line *node);
t_line	*ft_free_line(t_line **line);
t_line	*ft_adjust_and_free_node(t_line **line, t_line *node, size_t i);

#endif /* GET_NEXT_LINE_H */
