/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:47:16 by saad              #+#    #+#             */
/*   Updated: 2024/02/12 16:33:23 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

t_stack	*process_arg(t_stack *stack, char *arg, t_dup *duplicates[HASH_SIZE])
{
	char	**split;
	int		i;
	int		err;
	int		nbr;

	split = ft_split(arg, ' ');
	if (!split)
		return (clear_stack(&stack), NULL);
	i = 0;
	while (split[i])
	{
		if (!ft_strncmp(split[i], "", 1))
			return (clear_stack(&stack), free_args(split), NULL);
		err = 0;
		nbr = ft_atoerr(split[i], &err);
		if (err)
			return (clear_stack(&stack), free_args(split), NULL);
		if (is_duplicate(duplicates, nbr) || !add_to_hash(duplicates, nbr))
			return (clear_stack(&stack), free_args(split), NULL);
		if (!add_to_stack(&stack, nbr))
			return (clear_stack(&stack), free_args(split), NULL);
		i++;
	}
	free_args(split);
	return (stack);
}

t_stack	*parse_args(int size, char **args)
{
	t_dup	*duplicates[HASH_SIZE];
	t_stack	*stack;
	int		i;

	if (!args || !*args || size <= 0)
		return (NULL);
	ft_bzero(duplicates, sizeof(duplicates));
	i = 0;
	stack = NULL;
	while (i < size)
	{
		stack = process_arg(stack, args[i], duplicates);
		if (!stack)
			return (clear_hash(duplicates), NULL);
		i++;
	}
	clear_hash(duplicates);
	return (stack);
}
