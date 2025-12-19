/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:07:51 by mabenois          #+#    #+#             */
/*   Updated: 2025/12/18 19:17:37 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"

int	main(void)
{
	t_vars	vars;

	if (ft_init_vars(&vars) == 0)
		mlx_loop(vars.mlx);
	ft_destroy_vars(&vars);
	return (0);
}
