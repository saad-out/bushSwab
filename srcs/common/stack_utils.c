/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:44:23 by soutchak          #+#    #+#             */
/*   Updated: 2024/02/12 17:44:57 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

size_t	assign_indexes(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max;
	t_stack	*tmp;

	max = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->n > max->n)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;
	t_stack	*tmp;

	min = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->n < min->n)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	assign_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*max;

	tmp_a = stack_a;
	while (tmp_a)
	{
		max = NULL;
		tmp_b = stack_b;
		while (tmp_b)
		{
			if (tmp_b->n < tmp_a->n)
			{
				if (!max || tmp_b->n > max->n)
					max = tmp_b;
			}
			tmp_b = tmp_b->next;
		}
		if (max)
			tmp_a->target = max;
		else
			tmp_a->target = get_max(stack_b);
		tmp_a = tmp_a->next;
	}
}
