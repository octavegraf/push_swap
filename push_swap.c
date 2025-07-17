/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:50:39 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/17 11:08:51 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	error(int error)
{
	errno = error;
	if (error < 132)
		perror("Error");
	if (error > 133)
		ft_printf("Error\n");
	if (error == 134)
		ft_printf("You Must have at least 2 int.");
	exit(EXIT_FAILURE);
}

t_stacks	*push_swap_init(void)
{
	t_stacks	*stacks;

	stacks = calloc(1, sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = NULL;
	stacks->b = NULL;
	return (stacks);
}

int	push_swap(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = NULL;
	if (argc < 2)
		return (1);
	stacks = push_swap_init();
	if (!stacks)
		return (1);
	if (int_detector(argv, argc - 1))
		stacks->a = create_stack_from_array(argv, argc - 1);
	if (!stacks->a)
		return (stack_free(stacks->a), stack_free(stacks->b), free(stacks), 1);
	if (argc == 4 || argc == 6)
	{
		if (!small_sort_bis(stacks, argc - 1))
			return (stack_free(stacks->a), stack_free(stacks->b),
				free(stacks), 1);
	}
	else if (!radix(stacks, argc - 1, biggest_bit(argc - 1)))
		return (stack_free(stacks->a), stack_free(stacks->b), free(stacks), 1);
	stack_free(stacks->a);
	stack_free(stacks->b);
	free(stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		result;

	args = NULL;
	if (argc == 1)
		error(133);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			error(133);
		argc = array_size(args) + 1;
		result = push_swap(argc, args);
		free_it((void *)args);
	}
	else
		result = push_swap(argc, argv + 1);
	if (result)
		return (error(13), 1);
	return (0);
}
/*
- Segfaults / leaks
*/