/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_big_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:38:52 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 15:00:09 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	find_smallest(t_frame *frame, char stack_name)
{
	t_stack	*head;
	t_stack	*tmp;
	long	i;

	head = frame->a;
	if (stack_name == 'b')
		head = frame->b;
	tmp = head->next;
	i = head->num;
	while (tmp != head)
	{
		if (i >= tmp->num)
			i = tmp->num;
		tmp = tmp->next;
	}
	return (i);
}

long	find_biggest(t_frame *frame, char stack_name)
{
	t_stack	*head;
	t_stack	*tmp;
	long	i;

	head = frame->a;
	if (stack_name == 'b')
		head = frame->b;
	tmp = head->next;
	i = head->num;
	while (tmp != head)
	{
		if (i <= tmp->num)
			i = tmp->num;
		tmp = tmp->next;
	}
	return (i);
}

void	find_big_small(t_frame *frame)
{
	find_smallest(frame, 'a');
	find_biggest(frame, 'a');
}
