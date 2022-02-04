/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:23:03 by ski               #+#    #+#             */
/*   Updated: 2022/02/04 13:23:06 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int get_info_table(t_file *file, t_it *info_table)
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