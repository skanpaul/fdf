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
typedef struct s_data		t_data;
typedef struct s_file		t_file;
typedef struct s_it			t_it;
typedef struct s_p			t_p;
typedef struct s_bresenham	t_bresenham;
typedef struct s_img		t_img;
typedef struct s_vu			t_vu;
/* ************************************************************************** */
typedef struct s_file
{
	char	*name;
	int		fd;
}	t_file;
/* -------------------------------------------------------------------------- */
typedef struct s_it
{
	int		max_c;
	int		max_l;
}	t_it;
/* -------------------------------------------------------------------------- */
typedef struct s_p
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_p;
/* -------------------------------------------------------------------------- */
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_file	file;
	t_it	info_table;
	t_p		*xyz;
	t_img	*img;
	t_p		vu_i;
	t_p		vu_j;
	t_p		vu_k;
	int		coef;
	int		coef_x;
	int		coef_y;
	int		coef_z;
	t_p		factor;
	int		factor_x;
	int		factor_y;
	int		factor_z;
	double	alpha_z;
	double	alpha_x;
	double	alpha_y;
	double	cos_alpha;
	double	sin_alpha;
	int		max_up;
	int		max_down;
	int		max_left;
	int		max_right;
	t_p		decal;
	t_p		*input;
	t_p		*output;
	int		x;
	int		y;

}	t_data;
/* -------------------------------------------------------------------------- */
typedef struct s_bresenham
{
	int	diff_x;
	int	diff_y;
	int	step_x;
	int	step_y;
	int	err;
	int	e2;	
}	t_bresenham;
/* -------------------------------------------------------------------------- */
typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		size_line;
	int		bpp;
	int		endian;
}	t_img;
/* ************************************************************************** */
#endif
