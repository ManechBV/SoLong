/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:40:45 by mabenois          #+#    #+#             */
/*   Updated: 2026/01/18 19:11:46 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "map_draw.h"

#include <stdio.h>

/**
 * @brief	Update loop called through a hook
 */
void	update_loop(void *param)
{
	t_vars	*vars;
	int		smooth;
	char	*moves_str;

	vars = (t_vars *) param;
	mlx_clear_window(vars->mlx, vars->win, (mlx_color){ .rgba = 0x101010FF });
	ft_draw_map(vars);
	smooth = 4;
	vars->player->draw_x += (vars->player->x - vars->player->draw_x) / smooth;
	vars->player->draw_y += (vars->player->y - vars->player->draw_y) / smooth;
	ft_draw_player(vars);
	moves_str = ft_itoa(vars->moves);
	mlx_string_put(vars->mlx, vars->win, 0, 0,
		(mlx_color){ .rgba = 0x000000FF }, moves_str);
	free(moves_str);
	if (vars->player->cell_below == 'E' && vars->player->can_exit == 0)
		mlx_loop_end(vars->mlx);
}

void	key_hook(int key, void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	if (key == 41)
		mlx_loop_end(vars->mlx);
	if (key == 79)
		ft_player_move(vars, 0);
	else if (key == 80)
		ft_player_move(vars, 1);
	else if (key == 81)
		ft_player_move(vars, 2);
	else if (key == 82)
		ft_player_move(vars, 3);
	if (vars->player->cell_below == 'C')
	{
		vars->player->cell_below = '0';
		if (ft_count_collec(vars) == 0)
			vars->player->can_exit = 0;
	}
}

void	window_hook(int event, void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	if (event == 0)
		mlx_loop_end(vars->mlx);
}
