/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:07:51 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/20 00:35:58 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac < 2)
	{
		write(1, "not enought args\n", 17);
		return (-1);
	}
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

	/* affiche la map --debug--
	t_map_node	*curr = vars.map->head;
	while (curr->next != NULL)
	{
		printf("%s", curr->line);
		curr = curr->next;
	}
	*/

	mlx_loop(vars.mlx);
	ft_destroy_vars(&vars);
	free_map(vars.map);
	return (0);
}
