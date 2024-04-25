/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_frame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:39:29 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 14:46:50 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	sort_reset(t_frame *frame, va_list argv)
{
	char	*str;

	str = ft_strdup(va_arg(argv, char *));
	if (ft_strcmp(str, "no_write") == 1)
		frame->no_write = 0;
	free(str);
	return (1);
}

void	reset_frame(t_frame *frame, ...)
{
	int		argc;
	va_list	argv;

	va_start(argv, frame);
	argc = va_arg(argv, int);
	while (argc > 0)
	{
		sort_reset(frame, argv);
		argc--;
	}
	va_end(argv);
}
