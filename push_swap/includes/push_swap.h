/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-alme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 14:36:48 by gde-alme          #+#    #+#             */
/*   Updated: 2022/06/18 15:17:26 by gde-alme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define NO_W "no_write"

typedef struct s_stack
{
	long int		num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_frame
{
	struct s_stack	*a;
	struct s_stack	*b;
	char			**argv;
	int				no_write;
	int				hold_max;
	int				hold_min;
	int				chunk_i;
}	t_frame;

void		append_stack(t_frame *frame, char s, int new_e, int to_top);
t_frame		*create_frame(t_frame *frame, char **argv);
void		push_swap(t_frame *frame);
int			ft_stacklen(t_frame *frame, char stack_name);
void		fill_stack_a(t_frame *frame);
int			ft_validate_size(int num);
long		atoi_push_swap(t_frame *frame, char *str);
void		check_duplicates(t_frame *frame);
int			check_sorted(t_frame *frame);
long		find_smallest(t_frame *frame, char stack_name);
long		find_biggest(t_frame *frame, char stack_name);
void		find_big_small(t_frame *frame);
void		push_swap_error(t_frame *frame);
void		push_swap_free(t_frame *frame);
void		free_stack(t_stack *t_head);
void		rmv_stack_last(t_frame *frame, char stack_name);
void		rmv_stack_head(t_frame *frame, char stack_name);
void		reset_frame(t_frame *frame, ...);
void		swap_ss(t_frame *frame);
void		swap_b(t_frame	*frame);
void		swap_a(t_frame	*frame);
void		move_chunk(t_frame *frame, int step);
void		rotate_to_top(t_frame *frame, char stack_name, long num);
void		_index(t_frame *frame, int *array);
long		closest_above(t_frame *frame);
void		sort_chunk(t_frame *frame, int step);
void		solve_5(t_frame *frame);
void		solve_4(t_frame *frame);
void		solve_3(t_frame *frame);
void		solve_2(t_frame *frame);
void		hanoi_2(t_frame *frame);
void		loop_(t_frame *frame, int mode, long i);
void		rotate_rr(t_frame *frame);
void		rotate_b(t_frame *frame);
void		rotate_a(t_frame *frame);
void		rev_rotate_a(t_frame *frame);
void		rev_rotate_b(t_frame *frame);
void		rev_rotate_r(t_frame *frame);
void		push_a(t_frame *frame);
void		push_b(t_frame *frame);
void		move_to_top(t_frame *frame);
char		**ft_split(const char *str, char c);
int			ft_strcmp(char *s1, char *s2);
int			ft_strlen(const char *s);
char		*ft_strdup(const char *s);
int			ft_strlcpy(char *str, const char *src, unsigned int n);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
