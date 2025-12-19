/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:40:45 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/19 20:00:46 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief	Update loop called through a hook
 */
void	update_loop(void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	mlx_clear_window(vars->mlx, vars->win, (mlx_color){ .rgba = 0x101010FF });
	ft_draw_player(vars);
}

void	key_hook(int key, void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	if (key == 41)
		mlx_loop_end(vars->mlx);
}

void	window_hook(int event, void *param)
{
	t_vars	*vars;

	vars = (t_vars *) param;
	if (event == 0)
		mlx_loop_end(vars->mlx);
}
