/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:35:15 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/08 21:59:08 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	play_sound(char *sound, t_cub3d *cub)
{
	pid_t pid;
	char *first_cmd;
	char *second_cmd;
	int status;

	(void)cub;
	(void)pid;

	if (NO_SOUND == 0)
		return ;
	first_cmd = ft_strjoin(B_SOUND, sound);
	second_cmd = ft_strjoin(first_cmd, E_SOUND);
	status = system(second_cmd);
	if (status == -1)
		ft_putstr_fd("Error: sound not found\n", 2);
	free(first_cmd);
	free(second_cmd);
}

void	kill_sound(void)
{
	int status;

	if (NO_SOUND == 0)
		return ;
	status = system("killall ffplay");
	if (status == -1)
		ft_putstr_fd("Error: killing sound failed\n", 2);
}
