/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:48:05 by soutchak          #+#    #+#             */
/*   Updated: 2024/02/13 21:53:31 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	both_on_top(t_stack **stack_a, t_stack **stack_b, t_stack *element)
{
	int	min_cost;
	int	i;

	min_cost = min(element->index, element->target->index);
	i = 0;
	while (i < min_cost)
	{
		double_rotate(stack_a, stack_b, STACK_BOTH);
		i++;
	}
	while (i < element->index)
	{
		rotate(stack_a, STACK_A);
		i++;
	}
	while (i < element->target->index)
	{
		rotate(stack_b, STACK_B);
		i++;
	}
}

void	element_top_target_bottom(t_stack **sa, t_stack **sb, t_stack *elem)
{
	int		i;
	size_t	size_b;

	size_b = assign_indexes(*sb);
	i = 0;
	while (i < elem->index)
	{
		rotate(sa, STACK_A);
		i++;
	}
	i = 0;
	while ((size_t)i < size_b - elem->target->index)
	{
		reverse_rotate(sb, STACK_B);
		i++;
	}
}

void	both_on_bottom(t_stack **stack_a, t_stack **stack_b, t_stack *element)
{
	int		i;
	int		min_cost;
	size_t	size_b;
	size_t	size_a;

	size_b = assign_indexes(*stack_b);
	size_a = assign_indexes(*stack_a);
	min_cost = min(size_a - element->index, size_b - element->target->index);
	i = 0;
	while (i < min_cost)
	{
		double_reverse_rotate(stack_a, stack_b, STACK_BOTH);
		i++;
	}
	while ((size_t)i < size_a - element->index)
	{
		reverse_rotate(stack_a, STACK_A);
		i++;
	}
	while ((size_t)i < size_b - element->target->index)
	{
		reverse_rotate(stack_b, STACK_B);
		i++;
	}
}

void	element_bottom_target_top(t_stack **sa, t_stack **sb, t_stack *elem)
{
	int		i;
	size_t	size_a;

	size_a = assign_indexes(*sa);
	i = 0;
	while ((size_t)i < size_a - elem->index)
	{
		reverse_rotate(sa, STACK_A);
		i++;
	}
	i = 0;
	while (i < elem->target->index)
	{
		rotate(sb, STACK_B);
		i++;
	}
}
