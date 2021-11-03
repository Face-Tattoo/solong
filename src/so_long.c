/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:44:25 by prafael-          #+#    #+#             */
/*   Updated: 2021/10/22 17:56:560 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	key_hook(int keycode, t_vars *vars)
// {
// 	if(keycode == KEY_ESC)
// 		return (-1);
// 	ft_printf("Hello from key_hook!%d\n", keycode);
// 	return(0);
// }

int	main(int argc, char **argv)
{
	t_module	*module;

	if(argc == 2)
	{
		module = malloc(1 * sizeof(t_module));
		if(module == NULL)
			return(error(14, NULL)); 
		if (verify_map(argv[1], module) == 0)
		{
			start_game(module);
			hook(module);
			mlx_loop(module->vars->mlx);
		}
		else
		{
			clear_map(module->map);
			exit(1);
		}
	}
	else
		return (error(22, NULL));
	exit (0);
}

