/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:08:19 by ski               #+#    #+#             */
/*   Updated: 2022/02/04 17:08:20 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void	rendering(t_p *xyz, t_data *data)
{
	t_p	*input;
	t_p	*output;

	input = xyz;
	output = trans_zoom(input, data);
	input = output;
	output = trans_rot_z(input, data, data->alpha_z);
	free(input);
	input = output;
	output = trans_rot_x(input, data, data->alpha_x);
	free(input);
	input = output;
	output = trans_rot_y(input, data, data->alpha_y);
	free(input);
	input = output;
	output = trans_deform(input, data);
	free(input);
	input = output;
	output = trans_decal(input, data);
	free(input);
	input = output;
	draw_clean(data);
	draw(input, data);
	free(input);
}
