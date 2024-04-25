/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:39:01 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 15:14:53 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_frame *frame)
{
	int	len;

	if (check_sorted(frame) == 0)
	{
		len = ft_stacklen(frame, 'a');
		if (len)
		{
			if (len == 2)
				solve_2(frame);
			else if (len == 3)
				solve_3(frame);
			else if (len == 4)
				solve_4(frame);
			else if (len == 5)
				solve_5(frame);
			else
				hanoi_2(frame);
		}
	}
}

int	main(int argc, char **argv)
{
	t_frame		*frame;
	char		**new_argv;
	char		*input;

	frame = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
	{
		input = ft_strjoin("balelas ", argv[1]);
		new_argv = ft_split(input, ' ');
		free(input);
		frame = create_frame(frame, new_argv);
	}
	else
		frame = create_frame(frame, argv);
	fill_stack_a(frame);
	push_swap(frame);
	push_swap_free(frame);
	return (0);
}
