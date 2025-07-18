/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:56:09 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/18 18:54:27 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_detector(char **list, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		if (ft_strlen(list[i]) > 11)
			return (ft_printf("Error\nNot an int or int(over/under)flow\n"), 0);
		if (((list[i][0] == '-') || (list[i][0] == '+')) && list[i][1]
				&& (list[i][1] <= '9' && list[i][1] >= '0'))
			j++;
		while (list[i][++j])
		{
			if (list[i][j] > '9' || list[i][j] < '0')
				return (ft_printf("Error\nNot integer detected.\n"), 0);
		}
	}
	return (1);
}

t_stack	*create_stack_from_array(char **list, int i)
{
	int				j;
	int				k;
	long long int	*array;
	t_stack			*result;

	array = ft_calloc(i, sizeof(long long int));
	if (!array)
		return (NULL);
	j = -1;
	while (++j < i)
		array[j] = ft_atol(list[j]);
	j = -1;
	while (++j < i)
	{
		k = j;
		while (++k < i)
			if (array[j] == array[k])
				return (free(array),
					ft_printf("Error\nDuplicate detected.\n"), NULL);
	}
	if (detect_bad_numbers(array, i))
		return (free(array), NULL);
	result = stack_from_array(array, i);
	return (free(array), result);
}

int	detect_bad_numbers(long long int *array, int size)
{
	int	i;

	i = -1;
	if (!array)
		return (1);
	while (++i < size)
	{
		if (array[i] > INT_MAX || array[i] < INT_MIN)
			return (ft_printf("Error\nInt (over/under)flow\n"), 1);
	}
	return (0);
}
