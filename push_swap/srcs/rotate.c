/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:39:46 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 14:45:42 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	loop_(t_frame *frame, int mode, long i)
{
	if (i)
	{
		while (i)
		{
			if (mode == 1)
				rotate_a(frame);
			else if (mode == 2)
				rev_rotate_a(frame);
			else if (mode == 3)
				rotate_b(frame);
			else
				rev_rotate_b(frame);
			i--;
		}
	}
}

void	rotate_a(t_frame *frame)
{
	long	num;

	if (frame->a == NULL)
		return ;
	else
	{
		num = frame->a->num;
		rmv_stack_head(frame, 'a');
		append_stack(frame, 'a', num, 0);
	}
	if (frame->no_write == 0)
		write(1, "ra\n", 3);
}

void	rotate_b(t_frame *frame)
{
	long	num;

	if (frame->b == NULL)
		return ;
	else
	{
		num = frame->b->num;
		rmv_stack_head(frame, 'b');
		append_stack(frame, 'b', num, 0);
	}
	if (frame->no_write == 0)
		write(1, "rb\n", 3);
}

void	rotate_rr(t_frame *frame)
{
	frame->no_write = 42;
	rotate_a(frame);
	rotate_b(frame);
	write(1, "rr\n", 3);
	reset_frame(frame, 1, NO_W);
}
