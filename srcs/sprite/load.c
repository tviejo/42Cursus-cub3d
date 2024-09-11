/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-sarr <ade-sarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:59:02 by ade-sarr          #+#    #+#             */
/*   Updated: 2024/09/11 17:11:26 by ade-sarr         ###   ########.fr       */
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
			mlx_destroy_image(c->mlx.mlx_ptr, c->sprites[i].images[j].img.ptr);
		free(c->sprites[i].images);
	}
	c->nb_sprites = 0;
}

/* idem strlcpy mais avec un entier qui sera conertit en string comme source
*/
size_t	strlcpynum(char *dst, int num, size_t size)
{
	char *const	snum = ft_itoa(num);
	size_t		ret;

	ret = ft_strlcpy(dst, snum, size);
	free(snum);
	return (ret);
}

int	load_sprites(t_cub3d *c)
{
	t_sprite *const	sprite = &c->sprites[SPR_MONSTER1];
	int				i;
	const char		filename[256] = PATH_SPR_MONSTER1;
	const int		pathlen = ft_strlen(filename);
	char *const		strnum = (char *)filename + pathlen;

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
	return (EXIT_SUCCESS);
}
