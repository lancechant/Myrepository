/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchant <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 15:24:07 by lchant            #+#    #+#             */
/*   Updated: 2017/04/30 15:24:09 by lchant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

extern	char g_sudoku_area[9][9];

_Bool	ft_compare_row(int row, int num);
_Bool	ft_compare_column(int column, int num);
_Bool	ft_compare_box(int row, int column, int num);
_Bool	ft_check_compatible(int row, int column, int num);
char	*ft_retrieve_compatible(int row, int column);

_Bool	ft_confirm_argv(int argc, char *argv[]);
void	ft_put_into_array(char *argv[]);
void	ft_display_array(void);
_Bool	ft_next_one(int row, int column);
_Bool	ft_fill_box(int row, int column);

#endif
