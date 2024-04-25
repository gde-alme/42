/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hanoi2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:38:57 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 15:40:53 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_chunks(t_frame *frame)
{
	if (ft_stacklen(frame, 'a') <= 100)
		return (5);
	else
		return (11);
}

long	closest_above(t_frame *frame)
{
	long	c_above;
	long	i;
	t_stack	*node;

	c_above = find_biggest(frame, 'a');
	i = 0;
	node = frame->a;
	while (ft_stacklen(frame, 'a') - i >= 0)
	{
		if (node->num > frame->b->num && node->num <= c_above)
			c_above = node->num;
		i++;
		node = node->next;
	}
	return (c_above);
}

void	sort_chunk(t_frame *frame, int step)
{
	long	tmp;

	while (step-- > 0)
	{
		rotate_to_top(frame, 'b', find_biggest(frame, 'b'));
		tmp = closest_above(frame);
		if (tmp == frame->b->num)
			tmp = find_smallest(frame, 'a');
		rotate_to_top(frame, 'a', tmp);
		push_a(frame);
	}
}

static void	do_rest(t_frame *frame, int *array, int n, int rest)
{
	frame->hold_max = array[n];
	frame->hold_min = array[n - rest + 1];
	move_chunk(frame, rest);
	sort_chunk(frame, rest);
}

void	hanoi_2(t_frame *frame)
{
	int			chunks;
	int			step;
	int			rest;
	static int	*array;
	int			n;

	array = (int *)malloc(sizeof(int) * ft_stacklen(frame, 'a'));
	_index(frame, array);
	chunks = get_chunks(frame);
	step = ft_stacklen(frame, 'a') / chunks;
	rest = ft_stacklen(frame, 'a') % chunks;
	n = ft_stacklen(frame, 'a') - 1;
	while (chunks > 0)
	{
		frame->hold_max = array[n];
		frame->hold_min = array[n - step + 1];
		move_chunk(frame, step);
		sort_chunk(frame, step);
		chunks--;
		n = n - step;
	}
	if (rest > 0)
		do_rest(frame, array, n, rest);
	free(array);
}
