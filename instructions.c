/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:07:16 by saad              #+#    #+#             */
/*   Updated: 2024/02/09 18:25:49 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	push(t_stack **src, t_stack **dest, int flag)
{
	t_stack *tmp;

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
		printf("pb\n");
	else if (flag == STACK_B)
		printf("pa\n");
}

void	rotate(t_stack **stack, int flag)
{
	t_stack *tmp;
	t_stack *last;

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
		printf("ra\n");
	else if (flag == STACK_B)
		printf("rb\n");
}

void	reverse_rotate(t_stack **stack, int flag)
{
	t_stack *tmp;
	t_stack *last;

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
		printf("rra\n");
	else if (flag == STACK_B)
		printf("rrb\n");
}

void	swap(t_stack **stack, int flag)
{
	t_stack *tmp;

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
		printf("sa\n");
	else if (flag == STACK_B)
		printf("sb\n");
}

void	double_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a, STACK_BOTH);
	swap(stack_b, STACK_BOTH);
	printf("ss\n");
}

void	double_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, STACK_BOTH);
	rotate(stack_b, STACK_BOTH);
	printf("rr\n");
}

void	double_reverse_rotate(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, STACK_BOTH);
	reverse_rotate(stack_b, STACK_BOTH);
	printf("rrr\n");
}
