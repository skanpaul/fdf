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
// static void free_malloc(t_p *zoom, t_p *rot, t_p *deform, t_p *decal);
/* ************************************************************************** */
void rendering(t_p *xyz, t_data *data)
{
	// t_p *zoom = NULL;
	// t_p *rot = NULL;
	// t_p *deform = NULL;
	// t_p *decal = NULL;

	t_p *input;
	t_p *output;
	
	input = xyz;
	output = trans_zoom(xyz, data);

	input = output;
	output = trans_rot_z(input, data, data->alpha_z);
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
/* ************************************************************************** */
// void rendering(t_p *xyz, t_data *data)
// {
// 	t_p *zoom = NULL;
// 	t_p *rot = NULL;
// 	t_p *deform = NULL;
// 	t_p *decal = NULL;
	
// 	zoom = trans_zoom(xyz, data);
// 	rot = trans_rot_z(zoom, data, data->alpha_z);
// 	deform = trans_deform(rot, data);
// 	decal = trans_decal(deform, data);
	
// 	draw_clean(data);
// 	draw(decal, data);

// 	free_malloc(zoom, rot, deform, decal);
// }

/* ************************************************************************** */
// static void free_malloc(t_p *zoom, t_p *rot, t_p *deform, t_p *decal)
// {
// 	if (zoom)
// 		free(zoom);
// 	if (rot)
// 		free(rot);
// 	if (deform)
// 		free(deform);
// 	if (decal)
// 		free(decal);

// }
