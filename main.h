/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:03:08 by soutchak          #+#    #+#             */
/*   Updated: 2024/02/11 22:31:38 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

/* MARCROS */
# ifndef HASH_SIZE
#  define HASH_SIZE 100
# endif /* HASH_SIZE */

# ifndef N
#  define N 3
# endif /* N */

# ifndef STACK_A
#  define STACK_A 0
# endif /* STACK_A */

# ifndef STACK_B
#  define STACK_B 1
# endif /* STACK_B */

# ifndef STACK_BOTH
#  define STACK_BOTH 2
# endif /* STACK_BOTH */

# ifndef DO_NOT_PRINT
#  define DO_NOT_PRINT -1
# endif /* DO_NOT_PRINT */
/* ------ */

/* INCLUDES */
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft.h"
/* -------- */

/* STRUCTS */
typedef struct s_dup
{
	int				n;
	struct s_dup	*next;
}	t_dup;

typedef struct s_stack
{
	int				n;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;
/* ------ */

/* PROTOTYPES */
t_stack	*parse_args(int size, char **args);
void	push_swap(int ac, char **av);
void	clear_stack(t_stack **stack);
void	clear_hash(t_dup *hash[HASH_SIZE]);
int		ft_atoerr(const char *nptr, int *err);
int		is_duplicate(t_dup *duplicates[HASH_SIZE], int nbr);
int		add_to_hash(t_dup **duplicates, int nbr);
int		add_to_stack(t_stack **stack, int nbr);
void	print_stack(t_stack *stack);
void	print_stack_backwards(t_stack *stack);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);
size_t	stack_size(t_stack *stack);
size_t	assign_indexes(t_stack *stack);
t_stack	*get_max(t_stack *stack);
t_stack	*get_min(t_stack *stack);
void	assign_targets(t_stack *stack_a, t_stack *stack_b);
int		max(int a, int b);
int		min(int a, int b);
void	sort_three(t_stack **stack_a);

void	push(t_stack **src, t_stack **dest, int flag);
void	rotate(t_stack **stack, int flag);
void	reverse_rotate(t_stack **stack, int flag);
void	swap(t_stack **stack, int flag);
void	double_rotate(t_stack **a, t_stack **b);
void	double_reverse_rotate(t_stack **a, t_stack **b);
void	double_swap(t_stack **a, t_stack **b);

/* BONUS */
void	checker(int ac, char **av);
char	*get_next_line(int fd);
/* --------- */

#endif /* MAIN_H */