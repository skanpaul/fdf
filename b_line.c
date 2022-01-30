/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_line.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:55:48 by ski               #+#    #+#             */
/*   Updated: 2022/01/25 14:55:50 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
static int	prepare_step_x(t_point start, t_point end);
static int	prepare_step_y(t_point start, t_point end);
static void	init_bresenham(t_bresenham *b, t_point start, t_point end);

/* ************************************************************************** */
int	bresenham(t_point start, t_point end, t_data *data, int color)
{
	t_bresenham	b;

	init_bresenham(&b, start, end);
	while (true)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		b.e2 = 2 * b.err;
		if (b.e2 >= b.diff_y)
		{
			if (start.x == end.x)
				break ;
			b.err += b.diff_y;
			start.x += b.step_x;
		}
		if (b.e2 <= b.diff_x)
		{
			if (start.y == end.y)
				break ;
			b.err += b.diff_x;
			start.y += b.step_y;
		}
	}
	return (0);
}

/* ************************************************************************** */
static int	prepare_step_x(t_point start, t_point end)
{
	int	step_x;

	if (start.x < end.x)
		step_x = 1;
	else
		step_x = -1;
	return (step_x);
}

/* ************************************************************************** */
static int	prepare_step_y(t_point start, t_point end)
{
	int	step_y;

	if (start.y < end.y)
		step_y = 1;
	else
		step_y = -1;
	return (step_y);
}

/* ************************************************************************** */
static void	init_bresenham(t_bresenham *b, t_point start, t_point end)
{
	b->diff_x = abs(end.x - start.x);
	b->step_x = prepare_step_x(start, end);
	b->diff_y = -abs(end.y - start.y);
	b->step_y = prepare_step_y(start, end);
	b->err = b->diff_x + b->diff_y;
}
