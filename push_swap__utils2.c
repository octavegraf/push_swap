/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:00:58 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/14 14:57:23 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack *stack)
{
	if (stack->next)
		stack_free(stack->next);
	stack_delete(stack);
}

void	recalculate(t_stack *stack)
{
	int	i;

	i = -1;
	while (stack->next)
	{
		stack->i = ++i;
		stack = stack->next;
	}
	stack->i = ++i;
}

void	free_it(void **pointer)
{
	int	i;

	if (!pointer)
		return ;
	i = -1;
	while (pointer[++i])
	{
		free(pointer[i]);
		pointer[i] = NULL;
	}
	free(pointer);
	pointer = NULL;
}
