/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:04:48 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/20 00:21:46 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <fcntl.h>

typedef struct	s_map_node
{
	char				*line;
	struct s_map_node	*next;
	struct s_map_node	*prev;
} t_map_node;

typedef struct	s_map
{
	unsigned int	w;
	unsigned int	h;
	t_map_node		*head;
} t_map;

t_map		*ft_new_map(void);
t_map		*read_map(char *filename);
t_map_node	*ft_new_node(char *line);
void		ft_add_node_to_list(t_map_node *head, char *line);
void		free_map(t_map *map);

#endif
