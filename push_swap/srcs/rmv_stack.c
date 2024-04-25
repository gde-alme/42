/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rmv_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:39:39 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 14:46:21 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rmv_stack_head(t_frame *frame, char stack_name)
{
	t_stack	**head;
	t_stack	*tmp;

	if (stack_name == 'a')
		head = &frame->a;
	else
		head = &frame->b;
	if (*head)
	{
		if ((*head)->next == *head)
		{
			free(*head);
			*head = NULL;
		}
		else
		{
			tmp = *head;
			*head = (*head)->next;
			tmp->prev->next = *head;
			(*head)->prev = tmp->prev;
			free(tmp);
		}
	}
}

void	rmv_stack_last(t_frame *frame, char stack_name)
{
	t_stack	**last;
	t_stack	*tmp;

	last = &(frame->a->prev);
	if (stack_name == 'b')
		last = &(frame->b->prev);
	if (*last)
	{
		if ((*last)->next == *last)
		{
			free(*last);
			*last = NULL;
		}
		else
		{
			tmp = *last;
			(*last) = (*last)->prev;
			tmp->next->prev = *last;
			(*last)->next = tmp->next;
			free(tmp);
		}
	}
}
