/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:07:51 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/19 20:09:11 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"
#include "map_draw.h"
#include "ft_printf.h"

static int	ft_strlen_nonl(char *s)
{
	int	len;

	if (!s)
		return (-1);
	len = 0;
	while (s[len] != 0 && s[len] != '\n')
		len++;
	return (len);
}

static int	map_check_iregularity(t_map *map)
{
	int			len;
	t_map_node	*curr;

	curr = map->head;
	len = ft_strlen_nonl(curr->line);
	while (curr->next)
	{
		if (ft_strlen_nonl(curr->line) != len)
		{
			write(2, "walls are irregular", 19);
			return (-1);
		}
		curr = curr->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 2)
		return (-1);
	if (ft_init_vars(&vars) == -1)
	{
		ft_destroy_vars(&vars);
		return (-1);
	}
	vars.map = read_map(av[1]);
	if (vars.map == NULL)
	{
		ft_destroy_vars(&vars);
		return (-1);
	}
	ft_load_map_img(&vars);
	if (map_check_iregularity(vars.map) == 0)
	{
		if (ft_check_map_and_flood(vars.map) == 0 && checkcollec(vars.map) == 0)
			mlx_loop(vars.mlx);
	}
	ft_destroy_vars(&vars);
	free_map(vars.map);
	return (0);
}
