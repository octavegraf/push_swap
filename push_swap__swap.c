/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:31:41 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/10 16:47:23 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack *first, t_stack *second)
{
	t_stack	*temp;

	if (!first || !second)
		return (NULL);
	temp->nb = second->nb;
	temp->i = second->i;
	temp->next = second->nb;
	second->nb = first->nb;
	second->i = first->i;
	second->next = first->next;
	first->nb = temp->nb;
	first->i = temp->i;
	first->next = temp->next;
	return (1);
}

int	ft_push(t_stack *stack)
{

}
