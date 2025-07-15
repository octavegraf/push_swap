/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:57:32 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/15 15:39:03 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_rrotate(t_stack *stack)
{
	t_stack	*result;
	t_stack	*temp;
	t_stack	*temp2;

	if (!stack)
		return (NULL);
	temp = stack;
	while (temp->next)
	{
		temp2 = temp;
		temp = temp->next;
	}
	result = stack_add_front(stack, temp->nb, temp->i);
	if (!result)
		return (NULL);
	stack_delete(temp);
	temp2->next = NULL;
	return (result);
}

int	rra(t_stacks *stacks)
{
	t_stack	*result;

	if (!stacks->a)
		return (1);
	result = ft_rrotate(stacks->a);
	if (!result)
		return (0);
	stacks->a = result;
	return (printf("rra\n"), 1);
}

int	rrb(t_stacks *stacks)
{
	t_stack	*result;

	if (!stacks->b)
		return (1);
	result = ft_rrotate(stacks->b);
	if (!result)
		return (0);
	stacks->b = result;
	return (printf("rrb\n"), 1);
}

int	rrr(t_stacks *stacks)
{
	t_stack	*result_a;
	t_stack	*result_b;

	if (!stacks->a || !stacks->b)
		return (1);
	result_a = ft_rrotate(stacks->a);
	result_b = ft_rrotate(stacks->b);
	if (!result_a || !result_b)
		return (0);
	stacks->a = result_a;
	stacks->b = result_b;
	return (printf("rrr\n"), 1);
}
