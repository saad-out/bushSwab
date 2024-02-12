/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:37:56 by saad              #+#    #+#             */
/*   Updated: 2024/02/12 17:03:52 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
