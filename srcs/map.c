/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:02:08 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/19 20:25:47 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
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

int	ft_add_node_to_list(t_map_node **head, t_map_node *node_to_add)
{
	
}
