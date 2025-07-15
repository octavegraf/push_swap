/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__radix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:24:07 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/15 19:45:02 by ocgraf           ###   ########.fr       */
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
	while (++i < bits)
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
