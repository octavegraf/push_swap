/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocgraf <ocgraf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:50:39 by ocgraf            #+#    #+#             */
/*   Updated: 2025/07/14 12:29:19 by ocgraf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int error)
{
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

	stacks = calloc(2, sizeof(t_stack *));
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = push_swap_init();
	if (argc <= 2)
		error(134);
	if (int_detector(argv + 1, argc - 1))
		stacks->a = create_stack_from_array(argv + 1, argc - 1);
	if (!stacks->a)
		error(133);
	return (0);
}
