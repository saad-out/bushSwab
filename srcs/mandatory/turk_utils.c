/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:46:00 by soutchak          #+#    #+#             */
/*   Updated: 2024/02/12 18:47:32 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_stack	*get_target(t_stack *stack, t_stack *element)
{
	t_stack	*tmp;
	t_stack	*target;

	tmp = stack;
	target = NULL;
	while (tmp)
	{
		if (tmp->n > element->n)
		{
			if (!target)
				target = tmp;
			else if (tmp->n < target->n)
				target = tmp;
		}
		tmp = tmp->next;
	}
	if (!target)
		target = get_min(stack);
	return (target);
}

void	push_target_to_top(t_stack **stack, t_stack *target)
{
	size_t	size;
	int		i;

	size = assign_indexes(*stack);
	if ((size_t)target->index < size / 2)
	{
		i = 0;
		while (i++ < target->index)
			rotate(stack, STACK_A);
	}
	else
	{
		i = 0;
		while ((size_t)i++ < size - target->index)
			reverse_rotate(stack, STACK_A);
	}
}
