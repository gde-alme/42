/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:39:53 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 14:44:44 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_to_a(t_frame *frame, long num)
{
	long	i;
	t_stack	*head;

	i = 0;
	head = frame->a;
	while (head->num != num)
	{
		i++;
		head = head->next;
	}
	if (i > (ft_stacklen(frame, 'a') / 2) + 1)
		loop_(frame, 2, ft_stacklen(frame, 'a') - i);
	else
		loop_(frame, 1, i);
}

void	rotate_to_b(t_frame *frame, long num)
{
	long	i;
	int		len;
	t_stack	*head;

	head = frame->b;
	len = ft_stacklen(frame, 'b');
	i = 0;
	while (head->num != num)
	{
		i++;
		head = head->next;
	}
	if (i > (len / 2) + 1)
		loop_(frame, 4, ft_stacklen(frame, 'b') - i);
	else
		loop_(frame, 3, i);
}

void	rotate_to_top(t_frame *frame, char stack_name, long num)
{
	if (num != frame->a->num)
	{
		if (stack_name == 'a')
			rotate_to_a(frame, num);
		else
			rotate_to_b(frame, num);
	}
}
