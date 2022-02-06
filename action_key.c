/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:01:26 by ski               #+#    #+#             */
/*   Updated: 2022/01/25 14:01:28 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int	action_key(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	ft_printf("Touche: %d\n", key);
	action_key_rotation(key, data);
	action_key_decalage(key, data);
	action_key_perspective(key, data);
	action_key_usefull(key, data);
	return (0);
}

/* ************************************************************************** */
