/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:31:41 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/11 17:02:24 by ocgraf           ###   ########.fr       */
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
	temp = stack_add_front(top_stack, to_move->nb);
	if (!temp)
		return (stack_free(to_move), stack_free(top_stack), result);
	next = to_move->next;
	stack_delete(to_move);
	recalculate(next);
	recalculate(temp);
	result.a = next;
	result.b = temp;
	return (result);
}

