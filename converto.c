/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:25:08 by bdurmus           #+#    #+#             */
/*   Updated: 2022/04/27 12:26:34 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*mlx_to_image(t_game **game, char *path)
{
	return (mlx_xpm_file_to_image((*game)->mlx,
			path, &(*game)->size, &(*game)->size));
}

void	convertoxpm(t_game **game)
{
	(*game)->exit = mlx_to_image(game, "./sprites/exit.xpm");
	(*game)->bg = mlx_to_image(game, "./sprites/background.xpm");
	(*game)->rock = mlx_to_image(game, "./sprites/rock.xpm");
	(*game)->coin = mlx_to_image(game, "./sprites/coin.xpm");
	(*game)->playerr = mlx_to_image(game, "./sprites/playerr.xpm");
	(*game)->playerl = mlx_to_image(game, "./sprites/playerl.xpm");
}
