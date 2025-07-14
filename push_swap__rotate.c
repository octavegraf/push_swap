/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:57:32 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/14 19:35:29 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_rotate(t_stack *stack)
{
	t_stack		*result;

	if (!stack)
		return (stack_free(stack), NULL);
	result = stack_add_back(stack, stack->nb, stack->i);
	if (!result)
		return (stack_free(stack), NULL);
	result = result->next;
	stack_delete(stack);
	return (result);
}

int	ra(t_stacks *stacks)
{
	t_stack	*result;

	if (!stacks->a)
		return (1);
	result = ft_rotate(stacks->a);
	if (!result)
		return (0);
	stacks->a = result;
	return (printf("ra\n"), 1);
}

int	rb(t_stacks *stacks)
{
	t_stack	*result;

	if (!stacks->b)
		return (1);
	result = ft_rotate(stacks->b);
	if (!result)
		return (0);
	stacks->b = result;
	return (printf("rb\n"), 1);
}

int	rr(t_stacks *stacks)
{
	t_stack	*result_a;
	t_stack	*result_b;

	if (!stacks->a || !stacks->b)
		return (1);
	result_a = ft_rotate(stacks->a);
	result_b = ft_rotate(stacks->b);
	if (!result_a || !result_b)
		return (stack_free(stacks->a), stack_free(stacks->b), 0);
	stacks->a = result_a;
	stacks->b = result_b;
	return (printf("rr\n"), 1);
}
