/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacklen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:37:10 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 15:01:57 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stacklen(t_frame *frame, char stack_name)
{
	int		len;
	t_stack	*head;
	t_stack	*tmp;

	len = 1;
	if (stack_name == 'a')
		head = frame->a->next;
	else
		head = frame->b->next;
	tmp = head->prev;
	while (head != tmp)
	{
		len++;
		head = head->next;
	}
	return (len);
}
