/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:30:52 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/18 19:31:25 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/**
 * @brief		Initialize mlx, window, hooks and the update loop
 *
 * @param vars	t_vars typedef defined in utils.h	
 *
 * @return		-1 on error, 0 if everything goes right
 */
int	ft_init_vars(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == MLX_NULL_HANDLE)
		return (-1);
	ft_init_vars_info(vars);
	vars->win = mlx_new_window(vars->mlx, &vars->info);
	if (vars->win == MLX_NULL_HANDLE)
		return (-1);
	if (ft_init_player(vars) == -1)
		return (-1);
	mlx_set_fps_goal(vars->mlx, 60);
	mlx_add_loop_hook(vars->mlx, update_loop, vars);
	mlx_on_event(vars->mlx, vars->win, MLX_KEYDOWN, key_hook, vars);
	mlx_on_event(vars->mlx, vars->win, MLX_WINDOW_EVENT, window_hook, vars);
	return (0);
}

/**
 * @brief		Initialize window info creation for mlx
 *
 * @param vars	t_vars typedef defined in utils.h	
 */
void	ft_init_vars_info(t_vars *vars)
{
	vars->info.title = "Hello MacroLibX";
	vars->info.width = 1280;
	vars->info.height = 720;
	vars->info.is_fullscreen = false;
	vars->info.is_resizable = false;
	vars->info.render_target = NULL;
}

/**
 * @brief		Destroy and free shit contained in vars
 *
 * @param vars	t_vars typedef defined in utils.h	
 */
void	ft_destroy_vars(t_vars *vars)
{
	if (vars->player)
	{
		mlx_destroy_image(vars->mlx, vars->player->img);
		free(vars->player);
	}
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
		mlx_destroy_context(vars->mlx);
}
