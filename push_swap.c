/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:56 by saad              #+#    #+#             */
/*   Updated: 2024/02/10 17:50:17 by saad             ###   ########.fr       */
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

void	push_swap(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	size;

	stack_a = parse_args(ac - 1, av + 1);
	if (!stack_a)
		return (ft_putendl_fd("Error", 2), exit(EXIT_FAILURE));
	stack_b = NULL;
	if (!is_sorted(stack_a))
	{
		size = stack_size(stack_a);
		if (size == 2)
			swap(&stack_a, STACK_A);
		else if (size == 3)
			sort_three(&stack_a);
		else
			turk_sort(&stack_a, &stack_b);
	}
	clear_stack(&stack_a);
	clear_stack(&stack_b);
}
