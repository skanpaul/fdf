/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:02:50 by ski               #+#    #+#             */
/*   Updated: 2022/01/20 15:02:52 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
/* ************************************************************************** */
# include "minilibx_macos/mlx.h"
# include "structure.h"
# include "libft.h"
# include "config.h"
# include "X.h"
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdbool.h>
/* ************************************************************************** */
# define W_HEIGHT 1200
# define W_WIDTH 2000
# define W_TITLE "La fenetre a Sorakann"
# define NO_ERROR 0
# define MLX_ERROR 1
# define SCREEN_OVERFLOW 1
# define ERROR_GET_INFO_TABLE 1
/* ************************************************************************** */
int		init_mlx (t_data *data);

void 	init_vector_zoom(t_data *data, int coef);
void 	init_vector_unit(t_data *data);
void 	init_vector_decal(t_data *data);

/* ------------------------------------------------------------------------- */
t_p		*get_data_from_file(t_file *file, t_it *info_table);
// int		*do_z_table(t_file *file, t_it *info_table);	// N'EST PLUS UTILISE
// t_p		*do_xyz_table(t_it *info_table, int *z_table);	// N'EST PLUS UTILISE

t_p		*do_table(t_file *file, t_it *info_table);
int		get_info_table(t_file *file, t_it *info_table);

/* ------------------------------------------------------------------------- */
int		action_key(int key, void *param);
int		action_mouse(int button,int x,int y,void *param);
/* ------------------------------------------------------------------------- */
int		bresenham(t_p start, t_p end, t_data *data, int color);
void	put_pixel_to_img(t_img *img, int x, int y, int color);
/* ------------------------------------------------------------------------- */
void	draw_grid(int size, t_data *data, int color);
void	draw_square(t_data *data, int color);
void 	draw_clean(t_data *data);
void	draw (t_p *table, int size_l, int size_c, t_data *data);
/* ------------------------------------------------------------------------- */
void	init_table (t_p *table, int size_l, int size_c);
bool	is_screen_overflow(int x, int y);
/* ------------------------------------------------------------------------- */
t_p		*trans_zoom(t_p *input, t_data *data);
t_p		*trans_deform(t_p *input, t_data *data);
t_p		*trans_decal(t_p *input, t_data *data);
// t_p		*trans_rot(...);
/* ************************************************************************** */
#endif
