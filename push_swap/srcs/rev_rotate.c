/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:39:34 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 14:39:35 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rotate_a(t_frame *frame)
{
	long	num;

	if (frame->a == NULL)
		return ;
	else
	{
		num = frame->a->prev->num;
		rmv_stack_last(frame, 'a');
		append_stack(frame, 'a', num, 1);
	}
	if (frame->no_write == 0)
		write(1, "rra\n", 4);
}

void	rev_rotate_b(t_frame *frame)
{
	long	num;

	if (frame->b == NULL)
		return ;
	else
	{
		num = frame->b->prev->num;
		rmv_stack_last(frame, 'b');
		append_stack(frame, 'b', num, 1);
	}
	if (frame->no_write == 0)
		write(1, "rrb\n", 4);
}

void	rev_rotate_r(t_frame *frame)
{
	frame->no_write = 42;
	rev_rotate_a(frame);
	rev_rotate_b(frame);
	write(1, "rrr\n", 4);
	reset_frame(frame, 1, NO_W);
}
