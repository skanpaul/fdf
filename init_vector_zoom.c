/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vector_zoom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:40:48 by ski               #+#    #+#             */
/*   Updated: 2022/02/04 13:40:49 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void init_vector_zoom(t_data *data, int coef)
{
	data->factor_x = data->coef_x * coef;
	data->factor_y = data->coef_y * coef;
	data->factor_z = data->coef_z * coef;
}

/* ************************************************************************** */
// void init_vector_zoom(t_data *data, int coef)
// {
// 	int x_fact;
// 	int y_fact;
// 	int z_fact;

// 	x_fact = 1 * coef;
// 	y_fact = 1 * coef;
// 	z_fact = 1 * coef;

// 	data->factor = (t_p){.x = x_fact, .y = y_fact, .z = z_fact};
// }
