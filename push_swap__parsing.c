/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap__parsing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:56:09 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/01 18:29:27 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_detector(char *list)
{
	while (*list)
	{
		if ((*list > '9' || *list < '0') && *list != '-' && *list != '+'
			&& *list != ' ')
			return (0);
		list++;
	}
	return (1);
}

int	*convert_char_tab_to_int(char **list)
{
	int	i;
	int	j;
	int	*array;

	i = 0;
	while (list[i])
		i++;
	array = ft_calloc(i + 1, sizeof(int));
	if (!array)
		return (NULL);
	j = -1;
	while (++j < i)
		array[j] = ft_atoi(list[j]);
	array[j] = NULL;
	return (array);
}
