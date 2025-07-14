/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:57:32 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/14 11:25:24 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_rrotate(t_stack *stack)
{
	t_stack		*result;
	t_stack		*temp;
	t_stack		*temp2;

	if (!stack)
		return (stack_free(stack), NULL);
	temp = stack;
	while (temp->next)
	{
		temp2 = temp;
		temp = temp->next;
	}
	result = stack_add_front(stack, temp->nb);
	if (!result)
		return (stack_free(stack), NULL);
	stack_delete(temp);
	recalculate(result);
	temp2->next = NULL;
	return (result);
}
