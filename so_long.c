/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:19:49 by bdurmus           #+#    #+#             */
/*   Updated: 2022/04/26 13:12:16 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	checker(char *name)
{
	char	*find;

	find = ft_strrchr(name, '.');
	if (!find || ft_strlen(find) != 4)
		return (0);
	if (ft_strncmp(find, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	game->size = 64;
	if (!game)
		return (0);
	if (argc != 2)
		printm("Eksik veya fazla arg girisi!\n", &game);
	if (!(checker(argv[1])) || !(init_map(&game, argv)))
		printm("Map olmadı be!\n", &game);
	game->move = 0;
	mlx_key_hook(game->window, ft_key_events, &game);
	mlx_hook(game->window, 17, 0, exit_hook, &game);
	mlx_loop(game->mlx);
	return (0);
}
