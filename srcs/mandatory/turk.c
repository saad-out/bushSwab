/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:34:58 by saad              #+#    #+#             */
/*   Updated: 2024/02/12 19:30:50 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rotate_to_min(t_stack **stack)
{
	t_stack	*min;
	size_t	size;
	int		i;

	size = assign_indexes(*stack);
	min = get_min(*stack);
	if ((size_t)min->index < size / 2)
	{
		i = 0;
		while (i++ < min->index)
			rotate(stack, STACK_A);
	}
	else
	{
		i = 0;
		while ((size_t)i++ < size - min->index)
			reverse_rotate(stack, STACK_A);
	}
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*target;

	tmp = *stack_b;
	while (tmp)
	{
		target = get_target(*stack_a, tmp);
		push_target_to_top(stack_a, target);
		push(stack_b, stack_a, STACK_B);
		tmp = *stack_b;
	}
}

void	push_element(t_stack **stack_a, t_stack **stack_b, t_stack *element)
{
	size_t	size_a;
	size_t	size_b;

	size_a = assign_indexes(*stack_a);
	size_b = assign_indexes(*stack_b);
	if ((size_t)element->index < size_a / 2)
	{
		if ((size_t)element->target->index < size_b / 2)
			both_on_top(stack_a, stack_b, element);
		else
			element_top_target_bottom(stack_a, stack_b, element);
	}
	else
	{
		if ((size_t)element->target->index > size_b / 2)
			both_on_bottom(stack_a, stack_b, element);
		else
			element_bottom_target_top(stack_a, stack_b, element);
	}
	push(stack_a, stack_b, STACK_A);
}

t_stack	*get_cheapest(t_stack *stack_a, size_t sa, size_t sb)
{
	t_stack	*cheapest;
	t_stack	*tmp;
	size_t	min_cost;
	size_t	cost;

	min_cost = (size_t)-1;
	tmp = stack_a;
	while (tmp)
	{
		cost = get_cost(tmp, sa, sb);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	if (min_cost == (size_t)-1)
		return (get_max(stack_a));
	return (cheapest);
}

void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack		*cheapest;
	size_t		size_a;
	size_t		size_b;
	int			i;

	size_a = assign_indexes(*stack_a);
	size_b = assign_indexes(*stack_b);
	i = 0;
	while (size_a > 3 && i++ < 2)
	{
		push(stack_a, stack_b, STACK_A);
		size_a = assign_indexes(*stack_a);
		size_b = assign_indexes(*stack_b);
	}
	while (size_a > 3)
	{
		assign_targets(*stack_a, *stack_b);
		cheapest = get_cheapest(*stack_a, size_a, size_b);
		push_element(stack_a, stack_b, cheapest);
		size_a = assign_indexes(*stack_a);
		size_b = assign_indexes(*stack_b);
	}
	sort_three(stack_a);
	push_back_to_a(stack_a, stack_b);
	rotate_to_min(stack_a);
}
