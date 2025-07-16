/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__radix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:24:07 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/16 15:04:58 by ocgraf           ###   ########.fr       */
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
				return (stack_free(stacks->a), stack_free(stacks->b), 0);
		}
		while (stacks->b)
		{
			status = pa(stacks);
			if (!status)
				return (stack_free(stacks->a), stack_free(stacks->b), 0);
		}
	}
	return (1);
}

int	small_sort(t_stacks *stacks)
{
	int		array[3];
	t_stack	*list;
	int		i;
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
	return (result);
}

int	small_sort_bis(t_stacks *stacks, int argc)
{
	t_stack	*list;
	t_stack	*og;
	int		i;

	if (is_sorted(stacks))
		return (1);
	i = -1;
	og = stacks->a;
	list = stacks->a;
	if (argc)
	{	
		while (++i < 2)
		{
			while (list && (list->i != 3 && list->i != 4))
				list = list->next;
			stacks->a = list;
			if (!pb(stacks))
				return (0);
		}
	}
	stacks->a = og;
	if (stacks->b->i == 4)
		if (!rb(stacks))
			return (0);
	if (small_sort(stacks) != 2)
		return (0);
	return (1);
}
