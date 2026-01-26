/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:49:36 by mabenois          #+#    #+#             */
/*   Updated: 2026/01/26 20:39:53 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECK_H
# define MAP_CHECK_H

# include "utils.h"
# include "map.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_check
{
	unsigned int	exit;
	unsigned int	start;
	unsigned int	collectible;
	unsigned int	*flood_map;
}	t_check;

// map_check.c
unsigned int	ft_strcountchr(char *s, char c);
t_check			*ft_new_check(t_map *map);
void			ft_free_check(t_check *check);
int				ft_check_map(t_map *map, t_check *check);
int				ft_check_error(int i);

// map_check_flood.c
void			ft_copy_map_to_int(unsigned int *tab, t_map *map);
int				ft_check_map_and_flood(t_map *map);
int				ft_check_map_border(t_map *map);
void			ft_flood_fill(t_map *map, unsigned int *tab);
unsigned int	ft_nb_of_empty(t_map *map, unsigned int *tab);

#endif
