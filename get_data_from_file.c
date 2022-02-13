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
t_p	*get_data_from_file(t_file *file, t_it *info_table)
{
	t_p	*xyz;

	xyz = NULL;
	if (get_info_table(file, info_table) == ERROR_GET_INFO_TABLE)
	{
		ft_printf("Ouverture de fichier IMPOSSIBLE\n");
		return (NULL);
	}
	xyz = do_table(file, info_table);
	return (xyz);
}
