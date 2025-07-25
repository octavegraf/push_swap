/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:31:41 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/15 18:41:08 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_swap(t_stack *head)
{
	int	temp_nb;
	int	temp_i;

	if (!head || !head->next)
		return (head);
	temp_nb = head->nb;
	temp_i = head->i;
	head->nb = head->next->nb;
	head->i = head->next->i;
	head->next->nb = temp_nb;
	head->next->i = temp_i;
	return (head);
}

int	sa(t_stacks *stacks)
{
	if (!stacks->a)
		return (1);
	stacks->a = ft_swap(stacks->a);
	return (ft_printf("sa\n"), 1);
}

int	sb(t_stacks *stacks)
{
	if (!stacks->b)
		return (1);
	stacks->b = ft_swap(stacks->b);
	return (ft_printf("sb\n"), 1);
}

int	ss(t_stacks	*stacks)
{
	if (!stacks->a || !stacks->b)
		return (1);
	stacks->a = ft_swap(stacks->a);
	if (!stacks->a)
		return (0);
	stacks->b = ft_swap(stacks->b);
	if (!stacks->b)
		return (0);
	return (ft_printf("ss\n"), 1);
}
