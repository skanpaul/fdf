/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key_perspective.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 12:30:09 by ski               #+#    #+#             */
/*   Updated: 2022/02/06 12:30:10 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
void	action_key_perspective(int key, t_data *data)
{
	if (key == KEY_K)
	{
		init_vector_unit_standard(data);
		rendering(data->xyz, data);
	}
	if (key == KEY_L)
	{
		init_vector_unit_iso(data);
		rendering(data->xyz, data);
	}
}
