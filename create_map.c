/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:30:24 by bdurmus           #+#    #+#             */
/*   Updated: 2022/04/27 11:42:35 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_put_image(t_game **game, void *obj, int x, int y)
{
	mlx_put_image_to_window((*game)->mlx, (*game)->window,
		obj, x * (*game)->size, y * (*game)->size);
}

static void	ft_create_object(t_game **game, char obj, int x, int y)
{
	if (obj == '0')
		ft_mlx_put_image(game, (*game)->bg, x, y);
	else if (obj == '1')
		ft_mlx_put_image(game, (*game)->rock, x, y);
	else if (obj == 'P')
	{
		ft_mlx_put_image(game, (*game)->playerr, x, y);
		(*game)->player_x = x;
		(*game)->player_y = y;
	}
	else if (obj == 'C')
	{
		ft_mlx_put_image(game, (*game)->coin, x, y);
		(*game)->coinc++;
	}
	else if (obj == 'E')
		ft_mlx_put_image(game, (*game)->exit, x, y);
}

int	create_map(t_game **game)
{
	int	x;
	int	y;

	(*game)->mlx = mlx_init();
	(*game)->coinc = 0;
	(*game)->window = mlx_new_window((*game)->mlx, (*game)->max_x
			* (*game)->size, (*game)->max_y * (*game)->size, "So_Long");
	convertoxpm(game);
	y = -1;
	while (++y < (*game)-> max_y)
	{
		x = -1;
		while (++x < (*game)-> max_x)
		{
			ft_create_object(game, (*game)->map[y][x], x, y);
		}
	}
	return (1);
}
