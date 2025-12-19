/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:30:36 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/18 19:34:11 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_init_player(t_vars *vars)
{
	vars->player = malloc(sizeof(t_player));
	if (!vars->player)
		return (-1);
	vars->player->x = 0;
	vars->player->y = 0;
	vars->player->w = 0;
	vars->player->h = 0;
	vars->player->img = mlx_new_image_from_file(
		vars->mlx,
		"res/PINGOUIN100x100.png",
		&vars->player->w,
		&vars->player->h
	);
	return (0);
}

void	ft_draw_player(t_vars *vars)
{
	mlx_put_image_to_window(
		vars->mlx, vars->win, vars->player->img,
		vars->player->x, vars->player->y
	);
}
