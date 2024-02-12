/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:37 by saad              #+#    #+#             */
/*   Updated: 2024/02/12 19:27:04 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
			c == '\v' || c == '\f' || c == '\r');
}

int	result_overflow(long result, int sign)
{
	if ((sign > 0 && result > INT_MAX)
		|| (sign < 0 && result > ((long)INT_MAX + 1)))
		return (1);
	return (0);
}

int	result_sign(const char *nptr, int i, int *sign)
{
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
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
	i = result_sign(nptr, i, &sign);
	if (!nptr[i])
		return (*err = 1, 0);
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		if (result_overflow(result, sign))
			return (*err = 1, 0);
		i++;
	}
	if (nptr[i] != '\0')
		return (*err = 1, 0);
	return ((int)(result * (long)sign));
}
