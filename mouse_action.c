/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mouse_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:44:52 by ski               #+#    #+#             */
/*   Updated: 2022/01/23 12:44:57 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int	mouse_action(int button,int x,int y,void *param)
{
	t_data *data;
	static int memory = 0;
	static t_point origine = {.x = 0, .y = 0};

	data = (t_data *)param;

	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, COLOR_RED, "Sorakann Ki");


	if(memory == 0)
	{
		ft_printf("button: %d\nx: %d\ny: %d\n", button, x, y);
		origine = (t_point){.x = x, .y = y};
		memory = 1;
	}
	else
	{
		bresenham(origine, (t_point){.x = x, .y = y},data, COLOR_RED);
		memory = 0;
	}

	return (0);
}
