/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:53:20 by saad              #+#    #+#             */
/*   Updated: 2024/02/11 22:53:42 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->n > tmp->next->n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
