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
static int get_info_table(t_file *file, t_it *info_table);

/* ************************************************************************** */
t_p *get_data_from_file(t_file *file, t_it *info_table)
{
	int		*z_table;
	t_p		*xyz;
	
	/* ------------------------------------------------------------------- */
	z_table = NULL;
	xyz = NULL;
	/* ------------------------------------------------------------------- */

	if (get_info_table(file, info_table) == ERROR_GET_INFO_TABLE)
		return (NULL);

	file->fd = open(file->name, O_RDONLY);
	if (file->fd == -1)
		return (NULL);
	/* ------------------------------------------------------------------- */
	info_table->max_l = 0;
	info_table->max_c = 0;
	/* ------------------------------------------------------------------- */
	z_table = do_z_table(file, info_table);
	xyz = do_xyz_table(info_table, z_table);
	
	if(z_table)
		free(z_table);	
	/* ------------------------------------------------------------------- */
	close(file->fd);
	return (xyz);
}

/* ************************************************************************** */
static int get_info_table(t_file *file, t_it *info_table)
{
	info_table->max_c = 0;
	info_table->max_l = 0;
	char **split;
	char *line;
	
	file->fd = open(file->name, O_RDONLY);
	if (file->fd == -1)
		return (ERROR_GET_INFO_TABLE);
	while (1)
	{
		line = get_next_line(file->fd);
		if(line == NULL)
			break ;
		if (info_table->max_l == 1)
		{
			split = ft_split(line, ' ');
			info_table->max_c = ft_split_count(split);
			ft_split_free(split);
		}
		free(line);
		info_table->max_l++;
	}	
	close(file->fd);
	return (NO_ERROR);
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