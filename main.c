/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:36:26 by ski               #+#    #+#             */
/*   Updated: 2022/01/25 13:36:33 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

/* ************************************************************************** */
int	main(int argc, char **argv)
{
	t_data	data;
	t_img	img;

	if (argc != 2)
	{
		ft_printf("Nombre d'argument INCORRECT\n");
		return (-1);
	}
	data.file.name = argv[1];
	data.xyz = get_data_from_file(&(data.file), &(data.info_table));
	if (data.xyz == NULL)
		return (0);
	if (init_mlx(&data) == MLX_ERROR)
		return (MLX_ERROR);
	img.ptr = mlx_new_image(data.mlx_ptr, W_WIDTH, W_HEIGHT);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp,
			&img.size_line, &img.endian);
	data.img = &img;
	init_data(&data);
	rendering(data.xyz, &data);
	mlx_mouse_hook(data.win_ptr, action_mouse, (void *)&data);
	mlx_key_hook(data.win_ptr, action_key, (void *)&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
