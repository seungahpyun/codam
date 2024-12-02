/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/29 17:08:29 by spyun         #+#    #+#                 */
/*   Updated: 2024/12/02 09:49:04 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <unistd.h>
#include <stdlib.h>

static void	ft_execute_instruction(t_stack **stack_a,
								t_stack **stack_b,
								char *line)
{
	if (!ft_strncmp(line, "sa", 2))
		ft_sa(stack_a, 1);
	else if (!ft_strncmp(line, "sb", 2))
		ft_sb(stack_b, 1);
	else if (!ft_strncmp(line, "ss", 2))
		ft_ss(stack_a, stack_b, 1);
	else if (!ft_strncmp(line, "pa", 2))
		ft_pa(stack_a, stack_b, 1);
	else if (!ft_strncmp(line, "pb", 2))
		ft_pb(stack_a, stack_b, 1);
	else if (!ft_strncmp(line, "ra", 2))
		ft_ra(stack_a, 1);
	else if (!ft_strncmp(line, "rb", 2))
		ft_rb(stack_b, 1);
	else if (!ft_strncmp(line, "rr", 2))
		ft_rr(stack_a, stack_b, 1);
	else if (!ft_strncmp(line, "rra", 3))
		ft_rra(stack_a, 1);
	else if (!ft_strncmp(line, "rrb", 3))
		ft_rrb(stack_b, 1);
	else if (!ft_strncmp(line, "rrr", 3))
		ft_rrr(stack_a, stack_b, 1);
	else
		ft_error();
}

static int	ft_handle_instruction(t_stack **stack_a,
								t_stack **stack_b,
								char *instr,
								int *i)
{
	if (*i == 0)
		return (1);
	instr[*i] = '\0';
	ft_execute_instruction(stack_a, stack_b, instr);
	*i = 0;
	return (0);
}

static void	ft_read_and_execute(t_stack **stack_a, t_stack **stack_b)
{
	char	instr[4];
	int		i;
	int		ret;
	char	c;

	i = 0;
	ret = read(0, &c, 1);
	while (ret > 0)
	{
		if (c == '\n')
		{
			if (ft_handle_instruction(stack_a, stack_b, instr, &i))
			{
				ret = read(0, &c, 1);
				continue ;
			}
		}
		else if (i < 3)
			instr[i++] = c;
		else
			ft_error();
		ret = read(0, &c, 1);
	}
	if (ret < 0 || i != 0)
		ft_error();
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (EXIT_SUCCESS);
	stack_a = ft_parse_input(argc, argv);
	if (!stack_a || ft_has_duplicates(stack_a))
	{
		ft_free(&stack_a);
		ft_error();
	}
	stack_b = NULL;
	ft_read_and_execute(&stack_a, &stack_b);
	if (ft_is_sorted(stack_a) && !stack_b)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDERR_FILENO);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (EXIT_SUCCESS);
}
