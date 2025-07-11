/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:05:52 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/11 17:02:36 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"

typedef struct s_stack
{
	int				nb;
	int				i;
	struct t_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	struct t_stack	*a;
	struct t_stack	*b;
}					t_stacks;

t_stack		*stack_from_array(int *array, int size);
t_stack		*stack_new_element(int nb, int i);
t_stack		*stack_add_back(t_stack *stack, int nb);
t_stack		*stack_add_front(t_stack *stack, int nb);
void		stack_delete(t_stack *stack);

void		stack_free(t_stack *stack);
void		recalculate(t_stack *stack);

int			int_detector(char **list);
int			*create_tab_int_from_char(char **list);
int			detect_bad_numbers(long long int *array, int size);

int			ft_swap(t_stack *first, t_stack *second);

t_stacks	ft_push(t_stack *to_move, t_stack *top_stack);


#endif