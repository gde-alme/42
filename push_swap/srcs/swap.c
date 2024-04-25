/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:40:04 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 14:43:59 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_frame	*frame)
{
	long	tmp;

	if ((frame->a != NULL) && (frame->a->prev != frame->a))
	{
		tmp = frame->a->num;
		frame->a->num = frame->a->next->num;
		frame->a->next->num = tmp;
	}
	if (frame->no_write == 0)
		write(1, "sa\n", 3);
}

void	swap_b(t_frame	*frame)
{
	long	tmp;

	if ((frame->b != NULL) && (frame->b->next != frame->b))
	{
		tmp = frame->b->num;
		frame->b->num = frame->b->next->num;
		frame->b->next->num = tmp;
	}
	if (frame->no_write == 0)
		write(1, "sb\n", 3);
}

void	swap_ss(t_frame *frame)
{
	frame->no_write = 1;
	swap_a(frame);
	swap_b(frame);
	write(1, "ss\n", 3);
	reset_frame(frame, 1, NO_W);
}
