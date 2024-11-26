/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation_type_checker.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 15:01:04 by spyun         #+#    #+#                 */
/*   Updated: 2024/11/26 15:04:18 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_rotate_type_ab(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;
	int		moves;

	if (!a || !b)
		return (-1);
	tmp = a;
	moves = ft_calc_rarb_b(a, b, a->nbr);
	i = moves;
	while (tmp)
	{
		moves = ft_calc_rarb_b(a, b, tmp->nbr);
		if (moves != -1 && i > moves)
			i = moves;
		moves = ft_calc_rrarrb_b(a, b, tmp->nbr);
		if (moves != -1 && i > moves)
			i = moves;
		moves = ft_calc_rarrb_b(a, b, tmp->nbr);
		if (moves != -1 && i > moves)
			i = moves;
		moves = ft_calc_rrarb_b(a, b, tmp->nbr);
		if (moves != -1 && i > moves)
			i = moves;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_rotate_type_ba(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;
	int		moves;

	if (!a || !b)
		return (-1);
	tmp = b;
	moves = ft_calc_rarb_a(a, b, b->nbr);
	i = moves;
	while (tmp)
	{
		moves = ft_calc_rarb_a(a, b, tmp->nbr);
		if (moves != -1 && i > moves)
			i = moves;
		moves = ft_calc_rrarrb_a(a, b, tmp->nbr);
		if (moves != -1 && i > moves)
			i = moves;
		moves = ft_calc_rarrb_a(a, b, tmp->nbr);
		if (moves != -1 && i > moves)
			i = moves;
		moves = ft_calc_rrarb_a(a, b, tmp->nbr);
		if (moves != -1 && i > moves)
			i = moves;
		tmp = tmp->next;
	}
	return (i);
}
