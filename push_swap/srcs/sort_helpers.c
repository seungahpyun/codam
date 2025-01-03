/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_helpers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/26 15:42:58 by spyun         #+#    #+#                 */
/*   Updated: 2024/12/03 10:55:07 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_move_to_b_except_three(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		i;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	while (ft_stack_size(*stack_a) > 3 && !ft_is_sorted(*stack_a))
	{
		temp = *stack_a;
		i = ft_rotate_type_ab(*stack_a, *stack_b);
		while (temp && i >= 0)
		{
			if (i == ft_calc_rarb_b(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rarb(stack_a, stack_b, temp->nbr, 'a');
			else if (i == ft_calc_rrarrb_b(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rrarrb(stack_a, stack_b, temp->nbr, 'a');
			else if (i == ft_calc_rarrb_b(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rarrb(stack_a, stack_b, temp->nbr, 'a');
			else if (i == ft_calc_rrarb_b(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rrarb(stack_a, stack_b, temp->nbr, 'a');
			else
				temp = temp->next;
		}
	}
}

void	ft_move_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		i;

	while (*stack_b)
	{
		temp = *stack_b;
		i = ft_rotate_type_ba(*stack_a, *stack_b);
		while (i >= 0 && temp)
		{
			if (i == ft_calc_rarb_a(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rarb(stack_a, stack_b, temp->nbr, 'b');
			else if (i == ft_calc_rarrb_a(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rarrb(stack_a, stack_b, temp->nbr, 'b');
			else if (i == ft_calc_rrarrb_a(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rrarrb(stack_a, stack_b, temp->nbr, 'b');
			else if (i == ft_calc_rrarb_a(*stack_a, *stack_b, temp->nbr))
				i = ft_apply_rrarb(stack_a, stack_b, temp->nbr, 'b');
			else
				temp = temp->next;
		}
	}
}

t_stack	*ft_initialize_stack_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	if (!stack_a || !*stack_a)
		return (NULL);
	stack_b = NULL;
	if (ft_stack_size(*stack_a) > 3 && !ft_is_sorted(*stack_a))
	{
		ft_pb(stack_a, &stack_b, 0);
		if (ft_stack_size(*stack_a) > 3)
			ft_pb(stack_a, &stack_b, 0);
		if (ft_stack_size(*stack_a) > 3)
			ft_move_to_b_except_three(stack_a, &stack_b);
		if (!ft_is_sorted(*stack_a))
			ft_sort_three(stack_a);
	}
	return (stack_b);
}

void	ft_align_stack(t_stack **stack_a)
{
	int	i;

	i = ft_find_index(*stack_a, ft_min(*stack_a));
	if (i < ft_stack_size(*stack_a) - i)
		while ((*stack_a)->nbr != ft_min(*stack_a))
			ft_ra(stack_a, 0);
	else
		while ((*stack_a)->nbr != ft_min(*stack_a))
			ft_rra(stack_a, 0);
}
