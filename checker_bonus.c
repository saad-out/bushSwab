/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saad <saad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:58:10 by saad              #+#    #+#             */
/*   Updated: 2024/02/12 17:12:10 by saad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "get_next_line.h"

int	invalid_instruction(char *ins)
{
	if (!ft_strcmp(ins, "sa") || !ft_strcmp(ins, "sb") || !ft_strcmp(ins, "ss")
		|| !ft_strcmp(ins, "pa") || !ft_strcmp(ins, "pb") || !ft_strcmp(ins, "ra")
		|| !ft_strcmp(ins, "rb") || !ft_strcmp(ins, "rr") || !ft_strcmp(ins, "rra")
		|| !ft_strcmp(ins, "rrb") || !ft_strcmp(ins, "rrr"))
		return (0);
	return (1);
}

char	*get_instruction(char *line)
{
	char	*ins;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	ins = malloc(i + 1);
	if (!ins)
		return (NULL);
	ft_strlcpy(ins, line, i + 1);
	if (invalid_instruction(ins))
	{
		free(ins);
		return (NULL);
	}
	return (ins);
}

int	add_instruction(t_list **instructions, char *line)
{
	t_list	*new;
	char	*ins;

	ins = get_instruction(line);
	if (!ins)
		return (0);
	new = ft_lstnew(ins);
	if (!new)
		return (free(ins), 0);
	ft_lstadd_back(instructions, new);
	return (1);
}

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
