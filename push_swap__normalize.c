/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__normalize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:20:27 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/14 19:44:25 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(long long int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

void	sort_index(t_stack *stack, long long int *array, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (stack->nb != array[i] && i < size)
			i++;
		stack->i = i;
		stack = stack->next;
	}
}
