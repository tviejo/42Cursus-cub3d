/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:59:02 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/14 19:29:16 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_sprites(t_cub3d *c)
{
	int	i;
	int	j;

	i = c->nb_sprites;
	while (i--)
	{
		j = c->sprites[i].nb_images;
		while (j--)
		{
			if (c->sprites[i].images[j].img.ptr != NULL)
				mlx_destroy_image(c->mlx.mlx_ptr,
					c->sprites[i].images[j].img.ptr);
		}
		if (c->sprites[i].images != NULL)
			free(c->sprites[i].images);
	}
	c->nb_sprites = 0;
}

/* idem strlcpy mais avec un entier qui sera conertit en string comme source
 * todo : ajouter à libft
 */
size_t	strlcpynum(char *dst, int num, size_t size)
{
	size_t	ret;

	char *const snum = ft_itoa(num);
	ret = ft_strlcpy(dst, snum, size);
	free(snum);
	return (ret);
}

void	set_scale_n_ratio(t_sprite *sprite, double scale, double ratio)
{
	sprite->scale = scale;
	if (ratio != 0.0)
		sprite->ratio_w_h = ratio;
	else
		sprite->ratio_w_h = sprite->images->img.dim.width
			/ (double)sprite->images->img.dim.height;
}

int	load_sprites(t_cub3d *c)
{
	int			i;
	const char	filename[256] = PATH_SPR_MONSTER1;
	const int	pathlen = ft_strlen(filename);

	t_sprite *const sprite = &c->sprites[SPR_MONSTER1];
	char *const strnum = (char *)filename + pathlen;
	c->nb_sprites = 0;
	sprite->images = malloc(NBIMG_SPR_MONSTER1 * sizeof(t_sprite_img));
	if (sprite->images == NULL)
		return (EXIT_FAILURE);
	c->nb_sprites++;
	sprite->nb_images = 0;
	i = NBIMG_SPR_MONSTER1;
	while (i--)
	{
		strlcpynum(strnum, i + 1, 256 - pathlen);
		ft_strlcat(strnum, ".xpm", 256 - pathlen);
		if (load_texture(c->mlx.mlx_ptr, (char *)filename,
				&sprite->images[i].img) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		sprite->nb_images++;
	}
	set_scale_n_ratio(sprite, 1.0, 0.0);
	return (EXIT_SUCCESS);
}
