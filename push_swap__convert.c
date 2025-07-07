/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__convert.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:32:37 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/05 15:13:51 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_from_array(int *array, int size)
{
	int		i;
	t_stack	*stack;

	if (!array)
		return (NULL);
	i = 0;
	stack = stack_new_element(array[i], 0);
	if (!stack)
		return (0);
	while (++i < size)
	{
		if (!stack_add_back(stack, array[i], i))
			stack_free(stack);
	}
}

t_stack	*stack_new_element(int nb, int i)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->nb = nb;
	stack->i = i;
	stack->next = NULL;
	return (stack);
}

t_stack	*stack_add_back(t_stack *stack, int nb, int i)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	stack->next = stack_new_element(nb, i);
	return (stack);
}

void	stack_free(t_stack *stack)
{
	if (stack->next)
		stack_free(stack->next);
	free(stack);
}
