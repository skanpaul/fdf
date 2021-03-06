/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key_decalage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:29:51 by ski               #+#    #+#             */
/*   Updated: 2022/02/06 12:29:55 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void	action_key_decalage(int key, t_data *data)
{
	if (key == KEY_ARROW_UP)
	{
		data->decal.y -= 20;
		rendering(data->xyz, data);
	}
	if (key == KEY_ARROW_DOWN)
	{
		data->decal.y += 20;
		rendering(data->xyz, data);
	}
	if (key == KEY_ARROW_LEFT)
	{
		data->decal.x -= 20;
		rendering(data->xyz, data);
	}
	if (key == KEY_ARROW_RIGHT)
	{
		data->decal.x += 20;
		rendering(data->xyz, data);
	}
}
