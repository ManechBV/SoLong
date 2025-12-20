/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:26:46 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/19 23:49:11 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "map.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_player
{
	mlx_image	img;
	int			x;
	int			y;
	int			w;
	int			h;
} t_player;

typedef struct	s_vars
{
	mlx_context				mlx;
	mlx_window_create_info	info;
	mlx_window				win;
	t_player				*player;
	t_map					*map;
} t_vars;

// ft_window.c
int		ft_init_vars(t_vars	*vars);
void	ft_init_vars_info(t_vars *vars);
void	ft_destroy_vars(t_vars *vars);

// player.c
int		ft_init_player(t_vars *vars);
void	ft_draw_player(t_vars *vars);

// hooks.c
void	update_loop(void *param);
void	key_hook(int key, void *param);
void	window_hook(int event, void *param);

#endif
