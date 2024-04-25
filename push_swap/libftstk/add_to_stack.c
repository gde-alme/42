/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:36:54 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 15:16:52 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	append_stack(t_frame *frame, char s, int new_e, int to_top)
{
	t_stack		*tmp;
	t_stack		**head;

	head = &frame->a;
	if (s == 'b')
		head = &frame->b;
	if (*head == NULL)
	{
		*head = (t_stack *)malloc(sizeof(t_stack));
		(*head)->num = new_e;
		(*head)->next = *head;
		(*head)->prev = *head;
	}
	else
	{
		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->num = new_e;
		tmp->next = *head;
		tmp->prev = (*head)->prev;
		(*head)->prev = tmp;
		tmp->prev->next = tmp;
		if (to_top == 1)
			*head = (*head)->prev;
	}
}
