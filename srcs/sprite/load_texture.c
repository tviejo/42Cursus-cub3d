/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 23:36:46 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/11 17:11:04 by ade-sarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	errmsg(char *msg, char *fname)
{
	ft_dprintf(2, "Error: %s [%s]\n", msg, fname);
	perror(NULL);
}

int	load_texture(void *mlx_ptr, char *filename,	t_image *img)
{
	img->ptr = mlx_xpm_file_to_image(mlx_ptr, filename,
			&img->dim.width, &img->dim.height);
	if (img->ptr == NULL)
		return (errmsg("load_texture(): mlx_xpm_file_to_image()", filename),
			EXIT_FAILURE);
	img->pixels = mlx_get_data_addr(img->ptr, &img->bpp, &img->line_size,
			&img->endian);
	if (img->pixels == NULL)
		return (errmsg("load_texture(): mlx_get_data_addr()", filename),
			EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
