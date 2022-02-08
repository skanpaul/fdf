/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:02:50 by ski               #+#    #+#             */
/*   Updated: 2022/01/20 15:02:52 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MAIN_H
# define MAIN_H
/* ************************************************************************** */
# define W_HEIGHT 1200
# define W_WIDTH 2000
# define W_TITLE "La fenetre a Sorakann"
# define NO_ERROR 0
# define MLX_ERROR 1
# define SCREEN_OVERFLOW 1
# define ERROR_GET_INFO_TABLE 1
# define ERROR_COLUMN_AMOUNT 1
/* ************************************************************************** */
# include "minilibx_macos/mlx.h"
# include "libft.h"
# include "structure.h"
# include "config.h"
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdbool.h>
/* ************************************************************************** */
int		init_mlx(t_data *data);
/* ------------------------------------------------------------------------- */
void	init_data(t_data *data);
void	init_vector_zoom(t_data *data, int coef);
void	init_vector_unit_iso(t_data *data);
void	init_vector_unit_standard(t_data *data);
void	init_vector_decal(t_data *data);
/* ------------------------------------------------------------------------- */
t_p		*get_data_from_file(t_file *file, t_it *info_table);
t_p		*do_table(t_file *file, t_it *info_table);
int		get_info_table(t_file *file, t_it *info_table);
/* ------------------------------------------------------------------------- */
int		action_key(int key, void *param);
void	action_key_rotation(int key, t_data *data);
void	action_key_decalage(int key, t_data *data);
void	action_key_perspective(int key, t_data *data);
void	action_key_usefull(int key, t_data *data);
/* ------------------------------------------------------------------------- */
int		action_mouse(int event, int x, int y, void *param);
/* ------------------------------------------------------------------------- */
int		bresenham(t_p start, t_p end, t_data *data, int color);
void	put_pixel_to_img(t_img *img, int x, int y, int color);
/* ------------------------------------------------------------------------- */
void	draw_grid(int size, t_data *data, int color);
void	draw_square(t_data *data, int color);
void	draw_clean(t_data *data);
void	draw(t_p *table, t_data *data);
void	rendering(t_p *xyz, t_data *data);
/* ------------------------------------------------------------------------- */
void	init_table(t_p *table, int size_l, int size_c);
/* ------------------------------------------------------------------------- */
t_p		*trans_zoom(t_p *input, t_data *data);
t_p		*trans_deform(t_p *input, t_data *data);
t_p		*trans_decal(t_p *input, t_data *data);
t_p		*trans_rot_z(t_p *input, t_data *data, double alpha_z);
t_p		*trans_rot_x(t_p *input, t_data *data, double alpha_x);
t_p		*trans_rot_y(t_p *input, t_data *data, double alpha_y);
/* ************************************************************************** */
#endif
