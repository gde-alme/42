/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:39:23 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 14:47:10 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_stack *t_head)
{
	t_stack	*t_next;
	t_stack	*t_del;

	if (t_head)
	{
		t_next = t_head->next;
		while (t_next != t_head)
		{
			t_del = t_next;
			t_next = t_next->next;
			free(t_del);
		}
		free(t_next);
	}
}

void	push_swap_free(t_frame *frame)
{
	char	**arg;
	int		i;

	i = ft_stacklen(frame, 'a') + 1;
	arg = frame->argv;
	if (arg[0][0] == 'b')
	{
		while (i-- > 0)
			free(arg[i]);
		free(arg);
	}
	if (frame->a)
		free_stack(frame->a);
	else if (frame->b)
		free_stack(frame->b);
	free(frame);
}

void	push_swap_error(t_frame *frame)
{
	write(2, "Error\n", 6);
	push_swap_free(frame);
	exit(-1);
}
