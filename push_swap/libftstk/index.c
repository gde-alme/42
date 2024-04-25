/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:37:16 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 15:01:30 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	array_bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < (size))
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	_index(t_frame *frame, int *array)
{
	t_stack	*head;
	t_stack	*node;
	int		i;

	head = frame->a;
	node = head->next;
	array[0] = head->num;
	i = 1;
	while (node != head)
	{
		array[i] = node->num;
		i++;
		node = node->next;
	}
	i--;
	array_bubble_sort(array, ft_stacklen(frame, 'a'));
}
