/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 08:28:03 by ski               #+#    #+#             */
/*   Updated: 2022/02/02 08:28:06 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
t_p *get_data_from_file(t_file *file, t_it *info_table)
{
	t_p		*xyz;
	
	xyz = NULL;

	if (get_info_table(file, info_table) == ERROR_GET_INFO_TABLE)
		return (NULL);

	xyz = do_table(file, info_table);

	return (xyz);
}

/* ************************************************************************** */
// t_p *get_data_from_file(t_file *file, t_it *info_table)
// {
// 	int		*z_table;
// 	t_p		*xyz;
	
// 	/* ------------------------------------------------------------------- */
// 	z_table = NULL;
// 	xyz = NULL;
// 	/* ------------------------------------------------------------------- */
// 	file->fd = open(file->name, O_RDONLY);
// 	if (file->fd == -1)
// 		return (NULL);
// 	/* ------------------------------------------------------------------- */
// 	info_table->max_l = 0;
// 	info_table->max_c = 0;
// 	/* ------------------------------------------------------------------- */
// 	z_table = do_z_table(file, info_table);
// 	xyz = do_xyz_table(info_table, z_table);
	
// 	if(z_table)
// 		free(z_table);	
// 	/* ------------------------------------------------------------------- */
// 	close(file->fd);
// 	return (xyz);
// }