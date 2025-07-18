/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__radix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:24:07 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/18 17:28:05 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	biggest_bit(int size)
{
	int	bits;

	bits = 0;
	while ((size >> bits) != 0)
		bits++;
	return (bits);
}

int	radix(t_stacks *stacks, int size, int bits)
{
	int		i;
	int		j;
	int		status;

	i = -1;
	while (++i < bits && !is_sorted(stacks))
	{
		j = -1;
		while (++j < size)
		{
			if (!((stacks->a->i >> i) & 1))
				status = pb(stacks);
			else
				status = ra(stacks);
			if (!status)
				return (0);
		}
		while (stacks->b)
		{
			status = pa(stacks);
			if (!status)
				return (0);
		}
	}
	return (1);
}

int	small_sort(t_stacks *stacks, int i)
{
	int		array[3];
	t_stack	*list;
	int		result;

	i = -1;
	result = 0;
	list = stacks->a;
	while (++i < 3)
	{
		array[i] = list->i;
		list = list->next;
	}
	if (array[0] == 0 && array[1] == 2 && array[2] == 1)
		result = sa(stacks) + ra(stacks);
	else if (array[0] == 1 && array[1] == 0 && array[2] == 2)
		result = sa(stacks) + 1;
	else if (array[0] == 1 && array[1] == 2 && array[2] == 0)
		result = rra(stacks) + 1;
	else if (array[0] == 2 && array[1] == 0 && array[2] == 1)
		result = ra(stacks) + 1;
	else if (array[0] == 2 && array[1] == 1 && array[2] == 0)
		result = sa(stacks) + rra(stacks);
	else if (array[0] == 0 && array[1] == 1 && array[2] == 2)
		result = 2;
	return (result);
}

int	small_sort_bis(t_stacks *stacks, int argc)
{
	if (is_sorted(stacks))
		return (1);
	while (argc >= 5 && argc < 7)
	{
		if (stacks->a->i == 3 || stacks->a->i == 4)
		{
			argc++;
			if (!pb(stacks))
				return (0);
		}
		else
			if (!ra(stacks))
				return (0);
	}
	if (stacks && stacks->b && stacks->b->i == 3)
		if (!rb(stacks))
			return (0);
	if (small_sort(stacks, 0) != 2)
		return (0);
	while (stacks->b)
		if (!pa(stacks))
			return (0);
	if (argc == 7 && (!ra(stacks) || !ra(stacks)))
		return (0);
	return (1);
}
