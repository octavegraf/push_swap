/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:31:41 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/15 18:40:45 by ocgraf           ###   ########.fr       */
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
	if (!to_move)
		return (result);
	temp = stack_add_front(top_stack, to_move->nb, to_move->i);
	if (!temp)
		return (result);
	next = to_move->next;
	stack_delete(to_move);
	result.a = next;
	result.b = temp;
	return (result);
}

int	pa(t_stacks *stacks)
{
	t_stacks	result;

	if (!stacks->b)
		return (1);
	result = ft_push(stacks->b, stacks->a);
	if (!result.b)
		return (0);
	stacks->a = result.b;
	stacks->b = result.a;
	return (ft_printf("pa\n"), 1);
}

int	pb(t_stacks *stacks)
{
	t_stacks	result;

	if (!stacks->a)
		return (1);
	result = ft_push(stacks->a, stacks->b);
	if (!result.b)
		return (0);
	stacks->a = result.a;
	stacks->b = result.b;
	return (ft_printf("pb\n"), 1);
}
