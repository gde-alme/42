/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:39:07 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 14:55:44 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_from_top(t_frame *frame)
{
	t_stack	*head;
	int		i;
	int		min;
	int		max;

	min = frame->hold_min;
	max = frame->hold_max;
	i = 0;
	head = frame->a;
	while (i > -1)
	{
		if (head->num >= min && head->num <= max)
			return (i);
		i++;
		head = head->next;
	}
	return (-1);
}

int	find_from_bottom(t_frame *frame)
{
	t_stack	*head;
	int		i;
	int		min;
	int		max;

	min = frame->hold_min;
	max = frame->hold_max;
	i = 0;
	head = frame->a->prev;
	while (1)
	{
		if (head->num >= min && head->num <= max)
			return (i);
		i++;
		head = head->prev;
	}
	return (-1);
}

void	move_to_top(t_frame *frame)
{
	int	i;
	int	j;

	i = find_from_top(frame);
	j = find_from_bottom(frame);
	if (i <= j)
		while (i-- > 0)
			rotate_a(frame);
	else
	{
		while (j-- >= 0)
			rev_rotate_a(frame);
	}
}

void	move_chunk(t_frame *frame, int step)
{
	while (step > 0)
	{
		move_to_top(frame);
		push_b(frame);
		if (frame->b->prev->num > frame->b->num)
			rotate_b(frame);
		else if (frame->b->num < frame->b->next->num)
			swap_b(frame);
		step--;
	}
}
