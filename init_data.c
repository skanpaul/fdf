/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:01:18 by ski               #+#    #+#             */
/*   Updated: 2022/02/06 14:01:21 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void	init_data(t_data *data)
{
	data->coef = 1;
	data->coef_x = 1;
	data->coef_y = 1;
	data->coef_z = 1;
	data->alpha_z = 0;
	data->alpha_x = 0;
	data->alpha_y = 0;
	data->max_up = 0;
	data->max_down = 0;
	data->max_left = 0;
	data->max_right = 0;
	init_vector_unit_iso(data);
	init_vector_zoom(data, data->coef);
	init_vector_decal(data);
}
