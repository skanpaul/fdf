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
static void free_malloc(t_p *table_1, t_p *table_2, t_p *table_3);

/* ************************************************************************** */
void rendering(t_p *xyz, t_data *data)
{
	t_p *zoom = NULL;
	t_p *deform = NULL;
	t_p *decal = NULL;

	
	zoom = trans_zoom(xyz, data);
	deform = trans_deform(zoom, data);
	decal = trans_decal(deform, data);
	
	draw_clean(data);
	draw(decal, data);
	free_malloc(zoom, deform, decal);
}

/* ************************************************************************** */
static void free_malloc(t_p *table_1, t_p *table_2, t_p *table_3)
{
	if (table_1)
		free(table_1);
	if (table_2)
		free(table_2);
	if (table_3)
		free(table_3);
}
