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
#define FDF_H
/* ************************************************************************** */
#include "minilibx_macos/mlx.h"
#include "structure.h"
#include "libft.h"
#include "config.h"
#include "X.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
/* ************************************************************************** */
#define W_HEIGHT 600
#define W_WIDTH 1200
#define W_TITLE "La fenetre a Sorakann"
#define MLX_ERROR 1
#define SCREEN_OVERFLOW 1
#define NO_SCREEN_OVERFLOW 0
/* ************************************************************************** */
int initialisation (t_data *data);
void draw_grid(int size, t_data *data, int color);

int key_press(int key, void *param);
int	mouse_action(int button,int x,int y,void *param);


int bresenham(t_point start, t_point end, t_data *data, int color);
/* ------------------------------------------------------------------------- */
bool is_screen_overflow(int x, int y);
void put_pixel_to_img(t_img_data *img, t_point p, int color);


/* ************************************************************************** */
#endif
