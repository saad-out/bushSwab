/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:43:23 by soutchak          #+#    #+#             */
/*   Updated: 2024/02/12 18:43:52 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	min_on_top(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = (*stack_a)->next;
	if (tmp->n > tmp->next->n)
	{
		reverse_rotate(stack_a, STACK_A);
		swap(stack_a, STACK_A);
	}
}

void	min_in_middle(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (tmp->n < tmp->next->next->n)
		swap(stack_a, STACK_A);
	else
		rotate(stack_a, STACK_A);
}

void	min_in_bottom(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	if (tmp->n > tmp->next->n)
	{
		rotate(stack_a, STACK_A);
		swap(stack_a, STACK_A);
	}
	else
		reverse_rotate(stack_a, STACK_A);
}

void	sort_three(t_stack **stack_a)
{
	int		index;

	index = get_min(*stack_a)->index;
	if (index == 0)
		min_on_top(stack_a);
	else if (index == 1)
		min_in_middle(stack_a);
	else
		min_in_bottom(stack_a);
}
