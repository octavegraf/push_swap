/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:05:52 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/16 15:04:28 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include <errno.h>

typedef struct s_stack
{
	int				nb;
	int				i;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	struct s_stack	*a;
	struct s_stack	*b;
}					t_stacks;

//normalize
void		bubble_sort(long long int *array, int size);
void		sort_index(t_stack *stack, long long int *array, int size);

//parsing
int			int_detector(char **list, int size);
t_stack		*create_stack_from_array(char **list, int i);
int			detect_bad_numbers(long long int *array, int size);

//rotate
t_stack		*ft_rotate(t_stack *stack);
int			ra(t_stacks *stacks);
int			rb(t_stacks *stacks);
int			rr(t_stacks *stacks);

//rrotate
t_stack		*ft_rrotate(t_stack *stack);
int			rra(t_stacks *stacks);
int			rrb(t_stacks *stacks);
int			rrr(t_stacks *stacks);

//swap
t_stack		*ft_swap(t_stack *head);
int			sa(t_stacks *stacks);
int			sb(t_stacks *stacks);
int			ss(t_stacks *stacks);

//push
t_stacks	ft_push(t_stack *to_move, t_stack *top_stack);
int			pa(t_stacks *stacks);
int			pb(t_stacks *stacks);

//radix
int			biggest_bit(int size);
int			radix(t_stacks *stacks, int size, int bits);
int			small_sort(t_stacks *stacks);
int			small_sort_bis(t_stacks *stacks, int argc);

//utils
t_stack		*stack_from_array(long long int *array, int size);
t_stack		*stack_new_element(int nb, int i);
t_stack		*stack_add_back(t_stack *stack, int nb, int i);
t_stack		*stack_add_front(t_stack *stack, int nb, int i);
void		stack_delete(t_stack *stack);

//utils2
void		stack_free(t_stack *stack);
void		free_it(void **pointer);
int			array_size(char **array);
int			is_sorted(t_stacks *stacks);


//push_swap
t_stacks	*push_swap_init(void);
int			push_swap(int argc, char **argv);
void		error(int error);


#endif