/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soutchak <soutchak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:49:32 by soutchak          #+#    #+#             */
/*   Updated: 2024/02/12 18:50:02 by soutchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

size_t	element_close_to_top(t_stack *node, size_t sb)
{
	size_t	cost;
	int		min_cost;

	cost = 0;
	if ((size_t)node->target->index < sb / 2)
	{
		min_cost = min(node->index, node->target->index);
		cost += min_cost + (max(node->index, node->target->index) - min_cost);
	}
	else
	{
		cost += node->index;
		cost += sb - node->target->index;
	}
	return (cost);
}

size_t	element_close_to_bottom(t_stack *n, size_t sa, size_t sb)
{
	size_t	cost;
	int		min_c;

	cost = 0;
	if ((size_t)n->target->index > sb / 2)
	{
		min_c = min(sa - n->index, sb - n->target->index);
		cost += min_c + (max(sa - n->index, sb - n->target->index) - min_c);
	}
	else
	{
		cost += sa - n->index;
		cost += n->target->index;
	}
	return (cost);
}

size_t	get_cost(t_stack *node, size_t sa, size_t sb)
{
	size_t	cost;

	cost = 0;
	if ((size_t)node->index < sa / 2)
		cost += element_close_to_top(node, sb);
	else
		cost += element_close_to_bottom(node, sa, sb);
	return (++cost);
}
