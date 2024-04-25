/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:39:16 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 14:50:06 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_frame *frame)
{
	long	tmp;

	if (frame->b)
	{
		tmp = frame->b->num;
		rmv_stack_head(frame, 'b');
		append_stack(frame, 'a', tmp, 1);
	}
	write(1, "pa\n", 3);
}

void	push_b(t_frame *frame)
{
	long	tmp;

	if (frame->a)
	{
		tmp = frame->a->num;
		rmv_stack_head(frame, 'a');
		append_stack(frame, 'b', tmp, 1);
	}
	write(1, "pb\n", 3);
}
