/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:25:46 by mabenois          #+#    #+#             */
/*   Updated: 2026/01/09 14:37:14 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_DRAW_H
# define MAP_DRAW_H

# include "map.h"
# include "utils.h"

void	ft_load_map_img(t_vars *vars);
void	ft_draw_map(t_vars *vars);
void	ft_draw_cell(t_vars *vars, char c, unsigned int x, unsigned int y);

#endif
