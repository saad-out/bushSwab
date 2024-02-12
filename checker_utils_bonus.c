/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:11:37 by soutchak          #+#    #+#             */
/*   Updated: 2024/02/12 19:12:24 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "get_next_line.h"

int	invalid_instruction(char *ins)
{
	if (!ft_strcmp(ins, "sa") || !ft_strcmp(ins, "sb")
		|| !ft_strcmp(ins, "ss") || !ft_strcmp(ins, "pa")
		|| !ft_strcmp(ins, "pb") || !ft_strcmp(ins, "ra")
		|| !ft_strcmp(ins, "rb") || !ft_strcmp(ins, "rr")
		|| !ft_strcmp(ins, "rra") || !ft_strcmp(ins, "rrb")
		|| !ft_strcmp(ins, "rrr"))
		return (0);
	return (1);
}

char	*get_instruction(char *line)
{
	char	*ins;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	ins = malloc(i + 1);
	if (!ins)
		return (NULL);
	ft_strlcpy(ins, line, i + 1);
	if (invalid_instruction(ins))
	{
		free(ins);
		return (NULL);
	}
	return (ins);
}

int	add_instruction(t_list **instructions, char *line)
{
	t_list	*new;
	char	*ins;

	ins = get_instruction(line);
	if (!ins)
		return (0);
	new = ft_lstnew(ins);
	if (!new)
		return (free(ins), 0);
	ft_lstadd_back(instructions, new);
	return (1);
}
