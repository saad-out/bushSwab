/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:01:53 by soutchak          #+#    #+#             */
/*   Updated: 2024/02/12 19:02:11 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	double_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, STACK_BOTH);
	swap(stack_b, STACK_BOTH);
	ft_putendl_fd("ss", STDOUT_FILENO);
}

void	double_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, STACK_BOTH);
	rotate(stack_b, STACK_BOTH);
	ft_putendl_fd("rr", STDOUT_FILENO);
}

void	double_reverse_rotate(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, STACK_BOTH);
	reverse_rotate(stack_b, STACK_BOTH);
	ft_putendl_fd("rrr", STDOUT_FILENO);
}
