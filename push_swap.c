/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:50:39 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/15 16:20:24 by ocgraf           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc <= 2)
		error(133);
	stacks = push_swap_init();
	if (!stacks)
		error(12);
	if (int_detector(argv + 1, argc - 1))
		stacks->a = create_stack_from_array(argv + 1, argc - 1);
	if (!stacks->a)
		return (stack_free(stacks->a), stack_free(stacks->b), free(stacks),
			error(12), 1);
	if (!radix(stacks, argc - 1, biggest_bit(argc - 1)))
		return (stack_free(stacks->a), stack_free(stacks->b), free(stacks),
			error(12), 1);
	stack_free(stacks->a);
	stack_free(stacks->b);
	free(stacks);
	return (0);
}
