/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:58:41 by lleveque          #+#    #+#             */
/*   Updated: 2022/06/01 11:59:36 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strdup_bzero(char *s, t_data *data)
{
	int		i;
	char	*dst;

	i = -1;
	dst = ft_calloc(sizeof(char), data->map_fd->width + 1, data);
	while (s[++i])
		dst[i] = s[i];
	ft_free(s, data);
	return (dst);
}

void	init_plane_e_w(t_data *data)
{
	if (data->player->dir == 'E')
	{
		data->player->dir_y = 1;
		data->ray->plane_x = 0.66;
	}
	else if (data->player->dir == 'W')
	{
		data->player->dir_y = -1;
		data->ray->plane_x = -0.66;
	}
}

void	init_plane(t_data *data)
{
	if (data->player->dir == 'N')
	{
		data->player->dir_x = -1;
		data->ray->plane_y = 0.66;
	}
	else if (data->player->dir == 'S')
	{
		data->player->dir_x = 1;
		data->ray->plane_y = -0.66;
	}
	else
		init_plane_e_w(data);
}

void	find_player_data(char **s, int x, int y, t_data *data)
{
	if (data->player->dir)
		ft_exit_message("Map is invalid: only 1 player", data, 1);
	data->player->dir = s[x][y];
	data->player->x = (float)x + 0.5;
	data->player->y = (float)y + 0.5;
	data->player->old_y = data->player->y;
	data->player->old_x = data->player->x;
	init_plane(data);
	data->player->old_dx = data->player->dir_x;
	data->player->old_dy = data->player->dir_y;
	data->player->change = 1;
}

int	check_line(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		if (!ft_is_whitespace(buff[i]))
			return (1);
		i++;
	}
	return (0);
}
