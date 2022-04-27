/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:41:07 by bdurmus           #+#    #+#             */
/*   Updated: 2022/04/27 13:44:31 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_read_map(t_game **game, int fd)
{
	int			rd_bytes;
	char		map[2];
	char		*value;

	value = NULL;
	rd_bytes = 1;
	while (rd_bytes != 0)
	{
		rd_bytes = read(fd, map, 1);
		map[rd_bytes] = '\0';
		value = ft_str_join(value, map);
	}
	return (value);
}

static int	check_objects(t_game *game, int x, int y)
{
	int	*obj;

	obj = ft_calloc(3, sizeof(int));
	while (++y < game->max_y)
	{
		x = -1;
		while (++x < game->max_x)
		{
			if (game->map[y][x] == 'E')
				obj[0]++;
			else if (game->map[y][x] == 'C')
				obj[1]++;
			else if (game->map[y][x] == 'P')
				obj[2]++;
		}
	}
	if (obj[0] == 0 || obj[1] == 0 || obj[2] != 1)
	{
		free(obj);
		printm("Gecersiz obje girisi !", &game);
	}
	free(obj);
	return (1);
}

static int	check_walls(t_game *game, int x, int y)
{
	while (++y < game->max_y)
	{
		x = -1;
		while (++x < game->max_x)
		{
			if ((y == 0 || y == game->max_y - 1) && game->map[y][x] != '1')
				printm("Haritanin alti/ustu kapali olmali!", &game);
			if (!(ft_strchr("01CEP", game->map[y][x])))
				printm("Haritada gecersiz karakter !", &game);
			if ((x == 0 || x == game->max_x - 1) && game->map[y][x] != '1')
				printm("Haritanin sagi/solu kapali olmalidir!", &game);
		}
		if (ft_strlen(game->map[y]) != game->max_x)
			printm("Orantisiz harita girisi !", &game);
	}
	return (check_objects(game, -1, -1));
}

int	init_map(t_game **game, char **argv)
{
	int		fd;
	char	*map;

	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		printm("Dosya acilamadi!", game);
	map = ft_read_map(game, fd);
	(*game)->map = ft_split_fs(map, "\n", &(*game)->max_y);
	free(map);
	close(fd);
	(*game)->max_x = ft_strlen((*game)->map[0]);
	if (!(check_walls(*game, -1, -1)))
		return (0);
	return (create_map(game));
}
