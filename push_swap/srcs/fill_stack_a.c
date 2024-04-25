/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:38:47 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 15:00:26 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sorted(t_frame *frame)
{
	t_stack	*node;

	node = frame->a;
	while (node->next != frame->a)
	{
		if (node->num > node->next->num)
			return (0);
		node = node->next;
	}
	return (1);
}

void	check_duplicates(t_frame *frame)
{
	t_stack	*needle;
	t_stack	*stack;

	needle = frame->a;
	while (needle != frame->a->prev)
	{
		stack = needle->next;
		while (stack != frame->a)
		{
			if (needle->num == stack->num)
				push_swap_error(frame);
			stack = stack->next;
		}
		needle = needle->next;
	}
}

long	atoi_push_swap(t_frame *frame, char *str)
{
	long		num;
	long		negative;

	negative = 1;
	num = 0;
	if (*str == '-')
	{
		negative *= -1;
		str++;
	}
	if (*str > '9' || *str < '0')
		push_swap_error(frame);
	while (*str <= '9' && *str >= '0')
	{
		num = (num * 10) + (*str - '0');
		if ((*(str + 1) > '9' || *(str + 1) < '0') && *(str + 1) != '\0')
			push_swap_error(frame);
		str++;
	}
	if (num > 2147483647 || num < -2147483648)
		push_swap_error(frame);
	return (num * negative);
}

int	ft_validate_size(int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

void	fill_stack_a(t_frame *frame)
{
	char	*input;
	long	i;
	long	new_element;

	i = 1;
	input = frame->argv[i];
	while (input)
	{
		new_element = atoi_push_swap(frame, input);
		if (ft_validate_size(new_element) > 10)
			push_swap_error(frame);
		append_stack(frame, 'a', new_element, 0);
		input = frame->argv[++i];
	}
	if (!frame->a)
		push_swap_error(frame);
	check_duplicates(frame);
}
