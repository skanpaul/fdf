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
// #ifndef STRUCTURE_H
// # define STRUCTURE_H
/* ************************************************************************** */
typedef struct s_data		t_data;
typedef struct s_file		t_file;
typedef struct s_it			t_it;
typedef struct s_p			t_p;
typedef struct s_bresenham	t_bresenham;
typedef struct s_vector		t_vector;
typedef struct s_img		t_img;
/* ************************************************************************** */
typedef struct s_it
{
	int		max_c;
	int		max_l;
} t_it;
/* -------------------------------------------------------------------------- */
typedef struct s_file
{
	char	*name;
	int		fd;
} t_file;
/* -------------------------------------------------------------------------- */
typedef struct s_p
{
	int	x;
	int	y;
	int	z;
} t_p;
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
/* -------------------------------------------------------------------------- */
typedef struct s_vector
{
	t_p start;
	t_p	end;
} t_vector;
/* -------------------------------------------------------------------------- */
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_file	file;
	t_it	info_table;
	t_img	*img;
} t_data;
/* -------------------------------------------------------------------------- */
typedef struct s_img
{
	void *ptr;		// ou ID
	char *addr;
	int size_line;	// BYTE
	int bpp; // bits_per_pixel souvent = 32
	int endian;	
} t_img;
/* ************************************************************************** */
// #endif

