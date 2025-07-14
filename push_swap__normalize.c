/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__normalize.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:20:27 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/14 18:54:59 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	normalize(t_stack *stack)
{
	int		i;
	int		j;
	int		**array;
	t_stack	original;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	array = ft_calloc(i, sizeof(int **));
	if (!array)
		return (0);
	j = 0;
	while (j < i)
	{
		array[j] = original.nb;
		j++;
	}
	bubble_sort(array, i);
	sort_index(stack, array, i);
}

void	bubble_sort(int **array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - 1)
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

void	sort_index(t_stack *stack, int **array, int size)
{
	int	i;
	int	j;

	while (stack)
	{
		i = 0;
		while (stack->nb != array[i] && i < size - 1)
		{
			i++;
		}
		stack->i = i;
		stack = stack->next;
	}
}
 