/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:58:10 by saad              #+#    #+#             */
/*   Updated: 2024/02/12 22:10:47 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "get_next_line_bonus.h"

t_list	*read_instructions(void)
{
	t_list	*instructions;
	char	*line;

	instructions = NULL;
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!add_instruction(&instructions, line))
		{
			get_next_line(INVALID_FD);
			ft_lstclear(&instructions, free);
			free(line);
			return (NULL);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (instructions);
}

void	perform_instruction(char *ins, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(ins, "sa"))
		swap(stack_a, DO_NOT_PRINT);
	else if (!ft_strcmp(ins, "sb"))
		swap(stack_b, DO_NOT_PRINT);
	else if (!ft_strcmp(ins, "ss"))
		double_swap(stack_a, stack_b);
	else if (!ft_strcmp(ins, "pb"))
		push(stack_a, stack_b, DO_NOT_PRINT);
	else if (!ft_strcmp(ins, "pa"))
		push(stack_b, stack_a, DO_NOT_PRINT);
	else if (!ft_strcmp(ins, "ra"))
		rotate(stack_a, DO_NOT_PRINT);
	else if (!ft_strcmp(ins, "rb"))
		rotate(stack_b, DO_NOT_PRINT);
	else if (!ft_strcmp(ins, "rr"))
		double_rotate(stack_a, stack_b);
	else if (!ft_strcmp(ins, "rra"))
		reverse_rotate(stack_a, DO_NOT_PRINT);
	else if (!ft_strcmp(ins, "rrb"))
		reverse_rotate(stack_b, DO_NOT_PRINT);
	else if (!ft_strcmp(ins, "rrr"))
		double_reverse_rotate(stack_a, stack_b);
}

void	execute_instructions(t_list *ins, t_stack **stack_a, t_stack **stack_b)
{
	t_list	*tmp;

	tmp = ins;
	while (tmp)
	{
		perform_instruction((char *)tmp->content, stack_a, stack_b);
		tmp = tmp->next;
	}
}

void	checker(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*instructions;

	stack_a = parse_args(ac - 1, av + 1);
	if (!stack_a)
		return (ft_putendl_fd("Error", 2), exit(EXIT_FAILURE));
	stack_b = NULL;
	instructions = read_instructions();
	if (!instructions)
	{
		ft_putendl_fd("Error", 2);
		return (clear_stack(&stack_a), exit(EXIT_FAILURE));
	}
	execute_instructions(instructions, &stack_a, &stack_b);
	if (is_sorted(stack_a) && !stack_b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear(&instructions, free);
	clear_stack(&stack_a);
	clear_stack(&stack_b);
}
