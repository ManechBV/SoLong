/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:02:08 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/20 18:47:55 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "map.h"
#include "get_next_line.h"

t_map_node	*ft_new_node(char *line)
{
	t_map_node	*node;

	node = malloc(sizeof(t_map_node));
	if (!node)
		return (NULL);
	node->line = line;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_add_node_to_list(t_map_node *head, char *line)
{
	t_map_node	*curr;
	t_map_node	*node_to_add;

	node_to_add = ft_new_node(line);
	if (!node_to_add)
		return ;
	curr = head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = node_to_add;
	node_to_add->prev = curr;
}

t_map	*ft_new_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->w = 0;
	map->h = 0;
	map->head = NULL;
	return (map);
}

t_map	*read_map(char *filename)
{
	t_map		*map;
	int			fd;
	char		*tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = ft_new_map();
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	tmp = get_next_line(fd);
	map->w = ft_strlen_gnl(tmp);
	map->h = 0;
	map->head = ft_new_node(tmp);
	while (tmp != NULL)
	{
		tmp = get_next_line(fd);
		ft_add_node_to_list(map->head, tmp);
		map->h += 1;
	}
	close(fd);
	return (map);
}

void	free_map(t_map *map)
{
	t_map_node	*curr;

	curr = map->head;
	while (curr->next != NULL)
	{
		curr = curr->next;
		free(curr->prev->line);
		free(curr->prev);
	}
	free(curr);
	free(map);
}
