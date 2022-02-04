/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:44:52 by ski               #+#    #+#             */
/*   Updated: 2022/01/23 12:44:57 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int	action_mouse(int event,int x,int y,void *param)
{
	t_data *data;

	static int memory = 0;
	static t_p origine = {.x = 0, .y = 0};

	data = (t_data *)param;
	
	if (event == MOUSE_SCROLL_UP)
	{
		ft_printf("MOUSE_SCROLL_UP\n");
		data->coef++;
		init_vector_zoom(data, data->coef);
		rendering(data->xyz, data);
	}
	/* ----------------------------------------------------- */
	if (event == MOUSE_SCROLL_DOWN)
	{
		ft_printf("MOUSE_SCROLL_DOWN\n");
		data->coef--;
		if(data->coef <= 0)
			data->coef = 1;
		init_vector_zoom(data, data->coef);
		rendering(data->xyz, data);
	}
	/* ----------------------------------------------------- */
	if (event == MOUSE_CLICK_LEFT)
	{
		if(memory == 0)
		{
			ft_printf("button: %d\t x: %d\ty: %d\n", event, x, y);
			origine = (t_p){.x = x, .y = y};
			memory = 1;
		}
		else
		{
			bresenham(origine, (t_p){.x = x, .y = y},data, COLOR_RED);
			memory = 0;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->ptr, 0, 0);
	}
	/* ----------------------------------------------------- */
	if (event == MOUSE_CLICK_RIGHT)
	{

	}
	/* ----------------------------------------------------- */
	return (0);
}

/* ************************************************************************** */
// int	action_mouse(int event,int x,int y,void *param)
// {
// 	t_data *data;
// 	static int memory = 0;
// 	static t_p origine = {.x = 0, .y = 0};

// 	data = (t_data *)param;

// 	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, COLOR_RED, "Sorakann Ki");


// 	if(memory == 0)
// 	{
// 		ft_printf("button: %d\t x: %d\ty: %d\n", event, x, y);
// 		origine = (t_p){.x = x, .y = y};
// 		memory = 1;
// 	}
// 	else
// 	{
// 		bresenham(origine, (t_p){.x = x, .y = y},data, COLOR_RED);
// 		memory = 0;
// 	}
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->ptr, 0, 0);
// 	return (0);
// }
