/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:34:58 by saad              #+#    #+#             */
/*   Updated: 2024/02/11 22:31:54 by saad             ###   ########.fr       */
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

void	sort_three(t_stack **stack_a)
{
	int		index;
	t_stack	*tmp;

	index = get_min(*stack_a)->index;
	if (index == 0)
	{
		tmp = (*stack_a)->next;
		if (tmp->n > tmp->next->n)
		{
			reverse_rotate(stack_a, STACK_A);
			swap(stack_a, STACK_A);
		}
	}
	else if (index == 1)
	{
		tmp = *stack_a;
		if (tmp->n < tmp->next->next->n)
			swap(stack_a, STACK_A);
		else
			rotate(stack_a, STACK_A);
	}
	else
	{
		tmp = *stack_a;
		if (tmp->n > tmp->next->n)
		{
			rotate(stack_a, STACK_A);
			swap(stack_a, STACK_A);
		}
		else
			reverse_rotate(stack_a, STACK_A);
	}
}

void	push_element(t_stack **stack_a, t_stack **stack_b, t_stack *element)
{
	size_t	size_a;
	size_t	size_b;
	int	i;
	int		min_cost;

	size_a = assign_indexes(*stack_a);
	size_b = assign_indexes(*stack_b);
	if ((size_t)element->index < size_a / 2)
	{
		if ((size_t)element->target->index < size_b / 2)
		{
			min_cost = min(element->index, element->target->index);
			i = 0;
			while (i < min_cost)
			{
				double_rotate(stack_a, stack_b);
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
		else
		{
			i = 0;
			while (i < element->index)
			{
				rotate(stack_a, STACK_A);
				i++;
			}
			i = 0;
			while ((size_t)i < size_b - element->target->index)
			{
				reverse_rotate(stack_b, STACK_B);
				i++;
			}
		}
	}
	else
	{
		if ((size_t)element->target->index > size_b / 2)
		{
			min_cost = min(size_a - element->index, size_b - element->target->index);
			i = 0;
			while (i < min_cost)
			{
				double_reverse_rotate(stack_a, stack_b);
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
		else
		{
			i = 0;
			while ((size_t)i < size_a - element->index)
			{
				reverse_rotate(stack_a, STACK_A);
				i++;
			}
			i = 0;
			while (i < element->target->index)
			{
				rotate(stack_b, STACK_B);
				i++;
			}
		}
	}
	push(stack_a, stack_b, STACK_A);
}

size_t	get_cost(t_stack *node, size_t sa, size_t sb)
{
	size_t	cost;
	int		min_cost;

	cost = 0;
	if ((size_t)node->index< sa / 2)
	{
		if ((size_t)node->target->index < sb / 2)
		{
			min_cost = min(node->index, node->target->index);
			cost += min_cost + (max(node->index, node->target->index) - min_cost);
		}
		else
		{
			cost += node->index;
			cost += sb - node->target->index;
		}
	}
	else
	{
		if ((size_t)node->target->index > sb / 2)
		{
			min_cost = min(sa - node->index, sb - node->target->index);
			cost += min_cost + (max(sa - node->index, sb - node->target->index) - min_cost);
		}
		else
		{
			cost += sa - node->index;
			cost += node->target->index;
		}
	}
	return (++cost);
}

t_stack	*get_cheapest(t_stack *stack_a, t_stack *stack_b, size_t sa, size_t sb)
{
	t_stack	*cheapest;
	t_stack	*tmp;
	size_t	min_cost;
	size_t	cost;

	assign_targets(stack_a, stack_b);
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
		cheapest = get_cheapest(*stack_a, *stack_b, size_a, size_b);
		push_element(stack_a, stack_b, cheapest);
		size_a = assign_indexes(*stack_a);
		size_b = assign_indexes(*stack_b);
	}
	sort_three(stack_a);
	push_back_to_a(stack_a, stack_b);
	rotate_to_min(stack_a);
}
