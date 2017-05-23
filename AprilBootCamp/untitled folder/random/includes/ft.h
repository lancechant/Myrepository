/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:09:28 by lde-jage          #+#    #+#             */
/*   Updated: 2017/03/06 10:09:32 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <errno.h>

typedef struct	s_param
{
	int			row;
	int			col;
	char		free;
	char		obs;
	char		full;
	char		**grid;
	int			max;
	int			row_p;
	int			col_p;
}				t_param;

int				ft_check(char *str, int i, t_param *map);
void			ft_error(void);
void			ft_side(t_param *map);
void			ft_solve(t_param *map);
void			print_square(t_param *map, int side);
void			openfile(int ac, char **arr, t_param *map, char str[4097]);
int				ft_atoi(char *str);
int				ft_row(t_param *map, int r, int c, int rt);
int				ft_col(t_param *map, int r, int c, int ct);
int				ft_square_calc(t_param *map, int r, int c);
void			sep_param(char *str, t_param *map);
char			**ft_map(char *str, int i, t_param *map);
int				get_map_param(char *str, t_param *map);
void			print(t_param *map);
char			**alloc_map(char *str, int i, t_param *map);
void			fr_mem(t_param *map);
int				ft_letters(char *str, int i, t_param *map);
void			read_str(int fd, char str[4097]);

#endif
