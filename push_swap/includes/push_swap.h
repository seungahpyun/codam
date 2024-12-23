/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/20 16:33:42 by spyun         #+#    #+#                 */
/*   Updated: 2024/12/03 11:20:03 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
}	t_stack;

void	ft_error(void);
void	ft_free(t_stack **lst);
void	ft_free_split(char **split);

t_stack	*ft_stack_new(long nbr);
t_stack	*ft_stack_last(t_stack *stack);
int		ft_stack_size(t_stack *stack);
void	ft_stack_add_back(t_stack **stack, t_stack *stack_new);

t_stack	*ft_parse_input(int argc, char **argv);

bool	ft_has_duplicates(t_stack *a);
bool	ft_is_sorted(t_stack *a);
bool	ft_is_valid_number(const char *str);
bool	ft_is_int_range(const char *str);

void	ft_sa(t_stack **stack_a, int print_flag);
void	ft_sb(t_stack **stack_b, int print_flag);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int print_flag);
void	ft_pa(t_stack **stack_a, t_stack **stack_b, int print_flag);
void	ft_pb(t_stack **stack_a, t_stack **b, int print_flag);
void	ft_ra(t_stack **stack_a, int print_flag);
void	ft_rb(t_stack **stack_b, int print_flag);
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int print_flag);
void	ft_rra(t_stack **stack_a, int print_flag);
void	ft_rrb(t_stack **stack_b, int print_flag);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int print_flag);

int		ft_find_index(t_stack *stack, long nbr);
int		ft_find_place_a(t_stack *stack_a, int nbr_push);
int		ft_find_place_b(t_stack *stack_b, int nbr_push);
int		ft_min(t_stack *a);
int		ft_max(t_stack *a);

void	ft_sort_small_stack(t_stack **stack_a);
void	ft_sort_three(t_stack **stack_a);
void	ft_sort(t_stack **stack_a);

void	ft_move_to_b_except_three(t_stack **stack_a, t_stack **stack_b);
void	ft_move_back_to_a(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_initialize_stack_b(t_stack **stack_a);
void	ft_align_stack(t_stack **stack_a);

int		ft_calc_rarb_a(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_calc_rarrb_a(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_calc_rrarrb_a(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_calc_rrarb_a(t_stack *stack_a, t_stack *stack_b, int c);

int		ft_calc_rarb_b(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_calc_rarrb_b(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_calc_rrarb_b(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_calc_rrarrb_b(t_stack *stack_a, t_stack *stack_b, int c);

int		ft_rotate_type_ab(t_stack *stack_a, t_stack *stack_b);
int		ft_rotate_type_ba(t_stack *stack_a, t_stack *stack_b);

int		ft_apply_rarb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int		ft_apply_rarrb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int		ft_apply_rrarb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int		ft_apply_rrarrb(t_stack **stack_a, t_stack **stack_b, int c, char s);
#endif
