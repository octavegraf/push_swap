/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:31:41 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/14 19:20:24 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	ft_push(t_stack *to_move, t_stack *top_stack)
{
	t_stack		*temp;
	t_stack		*next;
	t_stacks	result;

	result.a = NULL;
	result.b = NULL;
	if (!to_move || !top_stack)
		return (stack_free(to_move), stack_free(top_stack), result);
	temp = stack_add_front(top_stack, to_move->nb, to_move->i);
	if (!temp)
		return (stack_free(to_move), stack_free(top_stack), result);
	next = to_move->next;
	stack_delete(to_move);
	result.a = next;
	result.b = temp;
	return (result);
}

int	pa(t_stacks *stacks)
{
	t_stacks	result;

	if (!stacks->a || !stacks->b)
		return (1);
	result = ft_push(stacks->b, stacks->a);
	if (!result.a || !result.b)
		return (stack_free(stacks->a), stack_free(stacks->b), 0);
	stacks->a = result.a;
	stacks->b = result.b;
	return (printf("pa\n"), 1);
}

int	pb(t_stacks *stacks)
{
	t_stacks	result;

	if (!stacks->a || !stacks->b)
		return (1);
	result = ft_push(stacks->a, stacks->b);
	if (!result.a || !result.b)
		return (stack_free(stacks->a), stack_free(stacks->b), 0);
	stacks->a = result.a;
	stacks->b = result.b;
	return (printf("pb\n"), 1);
}
