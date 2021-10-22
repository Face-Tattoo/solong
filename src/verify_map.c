/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:37:11 by prafael-          #+#    #+#             */
/*   Updated: 2021/10/22 17:06:34 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int verify_width_map(t_map *map, char *content, int height_now)
{
	if (map->width < 4)
		return (error(0, "Width is too small!"));
	if (ft_verify_str(content, "1", map->width) == 0)
	{
		if (((int)ft_strlen(content)) != map->width && height_now > 0)
			return (error(0, "Wrong construct of the map!"));
		if (((int)ft_strlen(content)) - 1 != map->width && height_now == 0)
			return (error(0, "Wrong construct of the map!"));
		content[map->width] = '\0';
		return(0);
	}
	else if (ft_verify_str(content, "10ECPJ", map->width) == 0)
	{
		if (content [0] != '1' && content [map->width - 1] != '1')
			return (error(0, "Wrong construct of the map!"));
		if (((int)ft_strlen(content)) - 1 != map->width)
			return (error(0, "Wrong construct of the map!"));
		content[map->width] = '\0';
		return(0);
	}
	return (error(0, "Wrong construct of the map this letter is not allowed!"));
}

int	read_map(t_map *map)
{
	t_list	*tmp;
	int		a;

	map->map = malloc(1 * sizeof(t_list *));
	tmp = malloc(1 * sizeof(t_list));
	if(map->map == NULL || tmp == NULL)
		return (error(14, NULL));
	tmp->content = get_next_line(map->fd);
	map->width = ft_strlen(tmp->content) - 1;
	map->map[0] = tmp;
	a = 0;
	while(tmp->content != NULL)
	{
		if(verify_width_map(map, (char *) tmp->content, a) == 1)
			return(1);
		tmp->next = malloc(1 * sizeof(t_list));
		tmp = tmp->next;
		tmp->content = get_next_line(map->fd);
		a++;
	}
	if(a < 4)
		return (error(0, "Height is too small!"));
	map->height = a;
	return(0);
}

int	verify_map(char *name_map, t_module *module)
{
	module->map = malloc(sizeof(t_map));
	if(module->map == NULL)
		return (error(14, NULL));
	printf("%s \n", name_map);
	module->map->fd = open(name_map, O_RDONLY);
	if (module->map->fd == -1)
		return (error(9, NULL));
	if(read_map(module->map) == 1)
		return (1);
	return (0);
}