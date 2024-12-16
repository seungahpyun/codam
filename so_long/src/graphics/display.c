/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: spyun <spyun@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/13 11:01:02 by spyun         #+#    #+#                 */
/*   Updated: 2024/12/16 10:17:54 by spyun         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*create_moves_str(int moves)
{
	char	*moves_str;
	char	*temp;

	temp = ft_itoa(moves);
	if (!temp)
		return (NULL);
	moves_str = ft_strjoin("Moves: ", temp);
	free(temp);
	return (moves_str);
}

void	display_moves(t_game *game)
{
	char	*moves_str;

	moves_str = create_moves_str(game->moves);
	if (!moves_str)
		error_exit("Failed to create moves string", game);
	if (game->moves_text)
		mlx_delete_image(game->mlx, game->moves_text);
	game->moves_text = mlx_put_string(game->mlx, moves_str, 10, 10);
	if (!game->moves_text)
		error_exit("Failed to display moves", game);
	free(moves_str);
}
