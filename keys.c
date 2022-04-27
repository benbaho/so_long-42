/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdurmus <bdurmus@student.42kocaeli.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:44:42 by bdurmus           #+#    #+#             */
/*   Updated: 2022/04/27 13:11:57 by bdurmus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move(t_game **game, int a, int x, int y)
{
	ft_mlx_put_image(game, (*game)->bg, (*game)->player_x, (*game)->player_y);
	if (a == 1)
		ft_mlx_put_image(game, (*game)->playerl, (*game)->player_x + x,
			(*game)->player_y + y);
	else if (a == 0)
		ft_mlx_put_image(game, (*game)->playerr, (*game)->player_x + x,
			(*game)->player_y + y);
	(*game)->map[(*game)->player_y][(*game)->player_x] = '0';
	(*game)->map[(*game)->player_y + y][(*game)->player_x + x] = 'P';
	(*game)->player_x += x;
	(*game)->player_y += y;
	(*game)->move++;
	ft_printf(BLUE "Hamle sayisi : %i\n" RESET, (*game)->move);
}

void	ft_ismove(t_game **game, int a, int x, int y)
{
	if ((*game)->map[(*game)->player_y + y][(*game)->player_x + x] == '0')
		ft_move(game, a, x, y);
	else if ((*game)->map[(*game)->player_y + y][(*game)->player_x + x] == 'C')
	{
		ft_move(game, a, x, y);
		(*game)->coinc--;
	}
	else if ((*game)->map[(*game)->player_y + y][(*game)->player_x + x] == 'E')
	{
		if ((*game)->coinc == 0)
		{
			ft_printf(RED " *_* !TEBRIKLER! *_*\n" RESET);
			exit_hook(game);
		}
		else
			ft_printf(RED "Daha %i tane obje var!\n" RESET, (*game)->coinc);
	}
	else
		ft_printf(RED "Engel var ama ?\n" RESET);
}

int	ft_key_events(int key_code, t_game **game)
{
	if (key_code == KEY_ESC)
		exit_hook(game);
	else if (key_code == KEY_A)
		ft_ismove(game, 1, -1, 0);
	else if (key_code == KEY_D)
		ft_ismove(game, 0, 1, 0);
	else if (key_code == KEY_W)
		ft_ismove(game, 1, 0, -1);
	else if (key_code == KEY_S)
		ft_ismove(game, 0, 0, 1);
	return (0);
}
