/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:41:57 by saad              #+#    #+#             */
/*   Updated: 2024/02/12 17:45:07 by soutchak         ###   ########.fr       */
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
