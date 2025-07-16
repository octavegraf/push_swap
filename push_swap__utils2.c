/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:00:58 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/16 13:09:48 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->next)
		stack_free(stack->next);
	stack_delete(stack);
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

int	array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	is_sorted(t_stacks *stacks)
{
	int		i;
	t_stack	*list;

	i = 0;
	list = stacks->a;
	while (list)
	{
		if (list->i != i++)
			return (0);
		list = list->next;
	}
	return (1);
}
