/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:30:36 by mabenois          #+#    #+#             */
/*   Updated: 2026/01/09 15:11:50 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "mlx_extended.h"

int	ft_init_player(t_vars *vars)
{
	vars->player = malloc(sizeof(t_player));
	if (!vars->player)
		return (-1);
	vars->player->x = 0;
	vars->player->y = 0;
	vars->player->draw_x = 0;
	vars->player->draw_y = 0;
	vars->player->w = 0;
	vars->player->h = 0;
	vars->player->img = mlx_new_image_from_file(
		vars->mlx,
		"res/PINGOUIN100x100.png",
		&vars->player->w,
		&vars->player->h
	);
	if (vars->player->img == MLX_NULL_HANDLE)
		return (-1);
	vars->player->cell_below = '0';
	return (0);
}

void	ft_draw_player(t_vars *vars)
{
	mlx_put_transformed_image_to_window(
			vars->mlx, vars->win, vars->player->img,
			vars->player->draw_x, vars->player->draw_y,
			vars->scale, vars->scale, 0.0
			);
}

