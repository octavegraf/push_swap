/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:56:09 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/05 15:13:47 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_detector(char **list)
{
	int	i;
	int	j;

	i = -1;
	while (list[++i])
	{
		j = -1;
		if ((list[i][j] == '-') || (list[i][j] == '+'))
			j++;
		while (list[i][++j])
		{
			if (list[i][j] > '9' || list[i][j] < '0')
				return (0);
		}
	}
	return (1);
}

int	*create_tab_int_from_char(char **list)
{
	int				i;
	int				j;
	int				k;
	long long int	*array;

	i = 0;
	while (list[i])
		i++;
	array = ft_calloc(i + 1, sizeof(int));
	if (!array)
		return (NULL);
	j = -1;
	while (++j < i)
		array[j] = ft_atol(list[j]);
	i = -1;
	while (++j < i)
	{
		k = j;
		while (++k < i)
			if (array[j] == array[k])
				return (free(array), NULL);
	}
	if (detect_bad_numbers(array, i))
		return (free(array), NULL);
	return (array);
}

int	detect_bad_numbers(long long int *array, int size)
{
	int	i;

	i = -1;
	if (!array)
		return (1);
	while (i < size)
	{
		if (array[i] > INT_MAX || array[i] < INT_MIN || array[i] == 0)
			return (1);
	}
	return (0);
}
