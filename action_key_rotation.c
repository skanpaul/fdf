/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:30:20 by ski               #+#    #+#             */
/*   Updated: 2022/02/06 12:30:22 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void	action_key_rotation(int key, t_data *data)
{
	int	inc;

	inc = 2;
	if (key == KEY_X)
		data->alpha_z += inc * (2 * M_PI / 360);
	if (key == KEY_Z)
		data->alpha_z -= inc * (2 * M_PI / 360);
	if (key == KEY_C)
		data->alpha_x += inc * (2 * M_PI / 360);
	if (key == KEY_V)
		data->alpha_x -= inc * (2 * M_PI / 360);
	if (key == KEY_B)
		data->alpha_y += inc * (2 * M_PI / 360);
	if (key == KEY_N)
		data->alpha_y -= inc * (2 * M_PI / 360);
	rendering(data->xyz, data);
}
