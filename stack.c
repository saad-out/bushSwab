/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:41:57 by saad              #+#    #+#             */
/*   Updated: 2024/02/11 22:31:25 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

int	add_to_stack(t_stack **stack, int nbr)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->n = nbr;
	new->next = NULL;
	new->prev = NULL;
	new->target = NULL;
	tmp = *stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (!tmp)
	{
		*stack = new;
		new->index = 0;
	}
	else
	{
		tmp->next = new;
		new->prev = tmp;
		new->index = tmp->index + 1;
	}
	return (1);
}

size_t	stack_size(t_stack *stack)
{
	size_t	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

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
