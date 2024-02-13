/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:07:16 by saad              #+#    #+#             */
/*   Updated: 2024/02/12 19:02:15 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	push(t_stack **src, t_stack **dest, int flag)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	*dest = tmp;
	if (flag == STACK_A)
		ft_putendl_fd("pb", STDOUT_FILENO);
	else if (flag == STACK_B)
		ft_putendl_fd("pa", STDOUT_FILENO);
}

void	rotate(t_stack **stack, int flag)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last = *stack;
	while (last && last->next)
		last = last->next;
	last->next = tmp;
	tmp->prev = last;
	tmp->next = NULL;
	if (flag == STACK_A)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (flag == STACK_B)
		ft_putendl_fd("rb", STDOUT_FILENO);
}

void	reverse_rotate(t_stack **stack, int flag)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last && last->next)
		last = last->next;
	tmp = last->prev;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	tmp->next = NULL;
	if (flag == STACK_A)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (flag == STACK_B)
		ft_putendl_fd("rrb", STDOUT_FILENO);
}

void	swap(t_stack **stack, int flag)
{
	t_stack	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
	if (flag == STACK_A)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (flag == STACK_B)
		ft_putendl_fd("sb", STDOUT_FILENO);
}
