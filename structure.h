/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:32:24 by ski               #+#    #+#             */
/*   Updated: 2022/01/25 14:32:27 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef STRUCTURE_H
# define STRUCTURE_H

/* ************************************************************************** */
typedef struct s_data t_data;
typedef struct s_point t_point;
typedef struct s_vector t_vector;
typedef struct s_img_data t_img_data;
typedef struct s_bresenham t_bresenham;

/* ************************************************************************** */
typedef struct s_data
{
	void *mlx_ptr;
	void *win_ptr;
} t_data;
/* -------------------------------------------------------------------------- */
typedef struct s_point
{
	int x;
	int y;
	int z;
} t_point;

/* -------------------------------------------------------------------------- */
typedef struct s_vector
{
	t_point start;
	t_point	end;
} t_vector;
/* -------------------------------------------------------------------------- */
typedef struct s_img_data
{
	char *addr;
	void *img;
	int line_length; // BYTE
	int bits_per_pixel;
	int *endian;
	
} t_img_data;
/* -------------------------------------------------------------------------- */
typedef struct s_bresenham 
{
	int	diff_x;
	int	diff_y;
	int	step_x;
	int	step_y;
	int	err;
	int	e2;	
} t_bresenham;
/* ************************************************************************** */
#endif