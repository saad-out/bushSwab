/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:47:16 by saad              #+#    #+#             */
/*   Updated: 2024/02/07 17:21:45 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_stack	*parse_args(int size, char **args)
{
	t_dup	*duplicates[HASH_SIZE];
	t_stack	*stack;
	int		i;
	int		err;
	int		nbr;

	if (!args || !*args || size <= 0)
		return (NULL);
	ft_bzero(duplicates, sizeof(duplicates));
	i = 0;
	stack = NULL;
	while (i < size)
	{
		if (!ft_strncmp(args[i], "", 1))
			return (clear_stack(&stack), clear_hash(duplicates), NULL);
		err = 0;
		nbr = ft_atoerr(args[i], &err);
		if (err)
			return (clear_stack(&stack), clear_hash(duplicates), NULL);
		if (is_duplicate(duplicates, nbr) || !add_to_hash(duplicates, nbr))
			return (clear_stack(&stack), clear_hash(duplicates), NULL);
		if (!add_to_stack(&stack, nbr))
			return (clear_stack(&stack), clear_hash(duplicates), NULL);
		i++;
	}
	clear_hash(duplicates);
	return (stack);
}
