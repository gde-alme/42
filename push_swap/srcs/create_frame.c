/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:38:41 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 15:00:47 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_frame	*create_frame(t_frame *frame, char **argv)
{
	frame = (t_frame *)malloc(sizeof(t_frame));
	if (!(frame))
		exit(1);
	frame->a = NULL;
	frame->b = NULL;
	frame->argv = argv;
	frame->no_write = 0;
	frame->hold_max = 0;
	frame->hold_min = 0;
	frame->chunk_i = 0;
	return (frame);
}
