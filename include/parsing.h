/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 10:57:41 by arudy             #+#    #+#             */
/*   Updated: 2022/06/01 12:00:52 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "struct.h"

int		parsing(t_data *data);
int		check_line(char *buff);
int		open_textures(t_data *data);
int		check_wall_only(char **s, int x);
int		textures_all_filled(t_data *data);
int		check_wall(char **s, int x, int y);
int		is_texture(char *buff, t_data *data);
int		check_map_line(char *buff, t_data *data);
void	dup_map(t_data *data);
void	assign_trgb(t_data *data);
void	manage_colors(char *buff, int n, char c, t_data *data);
void	find_player_data(char **s, int x, int y, t_data *data);

#endif
