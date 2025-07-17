/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:32:37 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/17 15:50:50 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_from_array(long long int *array, int size)
{
	int		i;
	t_stack	*stack;

	if (!array)
		return (NULL);
	i = 0;
	stack = stack_new_element(array[i], 0);
	if (!stack)
		return (NULL);
	while (++i < size)
	{
		if (!stack_add_back(stack, array[i], 0))
			return (stack_free(stack), NULL);
	}
	bubble_sort(array, size);
	sort_index(stack, array, size);
	return (stack);
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
	t_stack	*original;
	t_stack	*new;

	original = stack;
	while (stack->next)
		stack = stack->next;
	new = stack_new_element(nb, i);
	if (!new)
		return (NULL);
	stack->next = new;
	return (original);
}

t_stack	*stack_add_front(t_stack *stack, int nb, int i)
{
	t_stack	*new;

	new = stack_new_element(nb, i);
	if (!new)
		return (NULL);
	new->next = stack;
	return (new);
}

void	stack_delete(t_stack *stack)
{
	if (!stack)
		return ;
	free(stack);
	stack = NULL;
}
