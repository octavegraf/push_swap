/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 14:32:37 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/14 11:31:29 by ocgraf           ###   ########.fr       */
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
		if (!stack_add_back(stack, array[i]))
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

t_stack	*stack_add_back(t_stack *stack, int nb)
{
	t_stack	*next;
	t_stack	*original;
	int		i;

	if (!stack)
		return (NULL);
	original = stack;
	i = 0;
	next = stack_new_element(nb, i);
	if (!next)
		return (stack_free(original), NULL);
	return (stack);
}

t_stack	*stack_add_front(t_stack *stack, int nb)
{
	t_stack	*new;
	int		i;

	if (!stack)
		return (NULL);
	new = stack_new_element(nb, 0);
	if (!new)
		return (stack_free(stack), NULL);
	new->next = stack;
	i = 0;
	return (new);
}

void	stack_delete(t_stack *stack)
{
	if (!stack)
		return ;
	stack->i = NULL;
	stack->nb = NULL;
	stack->next = NULL;
	free(stack);
}
