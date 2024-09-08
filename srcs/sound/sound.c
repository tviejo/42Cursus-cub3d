/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sound.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tviejo <tviejo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:35:15 by tviejo            #+#    #+#             */
/*   Updated: 2024/09/08 14:01:35 by tviejo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	play_sound(char *sound)
{
	pid_t pid;
	char *first_cmd;
	char *second_cmd;

	pid = fork();
	if (pid == 0)
	{
		first_cmd = ft_strjoin(B_SOUND, sound);
		second_cmd = ft_strjoin(first_cmd, E_SOUND);
		system(second_cmd);
		free(first_cmd);
		free(second_cmd);
		exit(0);
	}
}

void	kill_sound(void)
{
	system("killall ffplay");
}