/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 17:49:36 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/20 18:54:46 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CHECK_H
# define MAP_CHECK_H

# include "utils.h"
# include "map.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct	s_check
{
	unsigned int	exit;
	unsigned int	start;
	unsigned int	collectible;
} t_check;
 
unsigned int	ft_strcountchr(char *s, char c);
t_check			*ft_new_check(void);
int				ft_check_map(t_map *map);
int				ft_check_error(int i);

#endif
