/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:56:06 by saad              #+#    #+#             */
/*   Updated: 2024/02/07 17:13:17 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	clear_hash(t_dup *hash[HASH_SIZE])
{
	int		i;
	t_dup	*tmp;

	i = 0;
	while (i < HASH_SIZE)
	{
		tmp = hash[i];
		while (tmp)
		{
			hash[i] = tmp->next;
			free(tmp);
			tmp = hash[i];
		}
		i++;
	}
}

int	is_duplicate(t_dup *duplicates[HASH_SIZE], int nbr)
{
	t_dup	*tmp;

	tmp = duplicates[(int)ft_abs(nbr % HASH_SIZE)];
	while (tmp)
	{
		if (tmp->n == nbr)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	add_to_hash(t_dup **duplicates, int nbr)
{
	t_dup	*new;
	int		index;

	new = malloc(sizeof(t_dup));
	if (!new)
		return (0);
	new->n = nbr;
	index = (int)ft_abs(nbr % HASH_SIZE);
	new->next = duplicates[index];
	duplicates[index] = new;
	return (1);
}
