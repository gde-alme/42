/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:39:59 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 14:44:25 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_2(t_frame *frame)
{
	rotate_to_top(frame, 'a', find_smallest(frame, 'a'));
}

void	solve_3(t_frame *frame)
{
	t_stack	*head;

	head = frame->a;
	if ((head->num > head->next->num) && (head->num < head->prev->num))
		swap_a(frame);
	else if (head->num > head->next->num && head->next->num > head->prev->num)
	{
		swap_a(frame);
		rev_rotate_a(frame);
	}
	else if (head->num > head->next->num && head->next->num < head->prev->num)
		rotate_a(frame);
	else if (head->num < head->prev->num && head->next->num > head->prev->num)
	{
		swap_a(frame);
		rotate_a(frame);
	}
	else if (head->num < head->next->num && head->num > head->prev->num)
		rev_rotate_a(frame);
}

void	solve_4(t_frame *frame)
{
	t_stack	*head;
	long	i;

	head = frame->a;
	i = find_smallest(frame, 'a');
	while (head->num != i)
	{
		rotate_a(frame);
		head = head->next;
	}
	push_b(frame);
	solve_3(frame);
	push_a(frame);
}

void	solve_5(t_frame *frame)
{
	rotate_to_top(frame, 'a', find_smallest(frame, 'a'));
	push_b(frame);
	rotate_to_top(frame, 'a', find_smallest(frame, 'a'));
	push_b(frame);
	solve_3(frame);
	push_a(frame);
	push_a(frame);
}
