/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <mabenois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 01:32:10 by mabenois          #+#    #+#             */
/*   Updated: 2026/01/08 16:40:35 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_draw.h"
#include "mlx_extended.h"

void	ft_load_map_img(t_vars *vars)
{
	vars->map->empty_img = mlx_new_image_from_file(
		vars->mlx, "res/grass.png", NULL, NULL);
	vars->map->wall_img = mlx_new_image_from_file(
		vars->mlx, "res/mure.png", NULL, NULL);
	vars->map->exit_img = mlx_new_image_from_file(
		vars->mlx, "res/exit.png", NULL, NULL);
}

void	ft_draw_map(t_vars *vars)
{
	unsigned int	i;
	unsigned int	x;
	unsigned int	y;
	t_map_node		*curr;

	curr = vars->map->head;
	x = 0;
	y = 0;
	while (curr->next != NULL)
	{
		i = 0;
		while (curr->line[i] != 0 && curr->line[i] != '\n')
		{
			ft_draw_cell(vars, curr->line[i], x, y);
			x++;
			i++;
		}
		x = 0;
		y++;
		curr = curr->next;
	}
}

void	ft_draw_cell(t_vars *vars, char c, unsigned int x, unsigned int y)
{
	mlx_image	*img_to_draw;

	if (c == 'P')
	{
		vars->player->x = x * (120.0 * vars->scale);
		vars->player->y = y * (120.0 * vars->scale);
		if (vars->player->cell_below == 'E')
			img_to_draw = &vars->map->exit_img;
		else
			img_to_draw = &vars->map->empty_img;
	}
	if (c == '0' || c == 'C')
		img_to_draw = &vars->map->empty_img;
	if (c == '1')
		img_to_draw = &vars->map->wall_img;
	if (c == 'E')
		img_to_draw = &vars->map->exit_img;
	mlx_put_transformed_image_to_window(
		vars->mlx, vars->win, *img_to_draw,
		x * (120.0 * vars->scale), y * (120.0 * vars->scale),
		vars->scale, vars->scale, 0.0);
}
