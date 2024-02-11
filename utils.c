/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:37 by saad              #+#    #+#             */
/*   Updated: 2024/02/09 15:48:01 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoerr(const char *nptr, int *err)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	*err = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	if (!nptr[i])
		return (*err = 1, 0);
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0')
		return (*err = 1, 0);
	else if ((sign > 0 && result > INT_MAX) || (sign < 0 && result > ((long)INT_MAX + 1)))
		return (*err = 1, 0);
	return ((int)(result * (long)sign));
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		// ft_putnbr_fd(stack->n, 1);
		// ft_putchar_fd('\n', 1);
		printf("i: %d -> %d\n", stack->index, stack->n);
		stack = stack->next;
	}
}

void	print_stack_backwards(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		// ft_putnbr_fd(tmp->n, 1);
		// ft_putchar_fd('\n', 1);
		printf("i: %d -> %d\n", stack->index, stack->n);
		tmp = tmp->prev;
	}
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
