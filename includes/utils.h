/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:26:46 by mabenois          #+#    #+#             */
/*   Updated: 2026/01/26 20:38:24 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "map.h"
# include "map_check.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_player
{
	mlx_image	img;
	int			x;
	int			y;
	int			w;
	int			h;
	int			draw_x;
	int			draw_y;
	char		cell_below;
	int			can_exit;
}	t_player;

typedef struct s_vars
{
	mlx_context				mlx;
	mlx_window_create_info	info;
	mlx_window				win;
	t_player				*player;
	t_map					*map;
	float					scale;
	int						moves;
	unsigned int			timer;
	unsigned int			timer_ceil;
	unsigned int			coin_frame;
}	t_vars;

// ft_window.c
int				ft_init_vars(t_vars	*vars);
void			ft_init_vars_info(t_vars *vars);
void			ft_destroy_vars(t_vars *vars);

// player.c
int				ft_init_player(t_vars *vars);
void			ft_draw_player(t_vars *vars);

// player_move.c
void			ft_player_move(t_vars *vars, int dir);
void			ft_player_try_move(t_vars *vars, char *from, char *dest);

// hooks.c
void			update_loop(void *param);
void			key_hook(int key, void *param);
void			window_hook(int event, void *param);

// map_draw.c
void			ft_draw_img(t_vars *vars, mlx_image *img,
					unsigned int x, unsigned int y);

// ft_count_collec.c
unsigned int	ft_count_collec(t_vars *vars);

#endif
