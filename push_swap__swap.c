/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:31:41 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/14 15:47:49 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_swap(t_stack *head)
{
	t_stack	*next;
	t_stack	*temp;

	if (!head || !head->next)
		return (stack_free(head), NULL);
	temp->nb = next->nb;
	temp->i = next->i;
	temp->next = next->nb;
	next->nb = head->nb;
	next->i = head->i;
	next->next = head->next;
	head->nb = temp->nb;
	head->i = temp->i;
	head->next = temp->next;
	recalculate(next);
	return (next);
}

int	sa(t_stacks *stacks)
{
	if (!stacks->a)
		return (1);
	stacks->a = ft_swap(stacks->a);
	if (!stacks->a)
		return (stack_free(stacks->a), 0);
	return (printf("sa\n"), 1);
}

int	sb(t_stacks *stacks)
{
	if (!stacks->b)
		return (1);
	stacks->b = ft_swap(stacks->b);
	if (!stacks->b)
		return (free_it(stacks->b), 0);
	return (printf("sb\n"), 1);
}

int	ss(t_stacks	*stacks)
{
	if (!stacks->a || !stacks->b)
		return (1);
	stacks->a = ft_swap(stacks->a);
	if (!stacks->a)
		return (stack_free(stacks->a), 0);
	stacks->b = ft_swap(stacks->b);
	if (!stacks->b)
		return (stack_free(stacks->b), 0);
	return (printf("ss\n"), 1);
}
