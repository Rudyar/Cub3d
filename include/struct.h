/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:05:31 by arudy             #+#    #+#             */
/*   Updated: 2022/05/16 19:23:36 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mlx		t_mlx;
typedef struct s_key		t_key;
typedef struct s_data		t_data;
typedef struct s_color		t_color;
typedef struct s_map_fd		t_map_fd;
typedef struct s_player		t_player;
typedef struct s_texture	t_texture;
typedef struct s_garbage	t_garbage;

struct	s_data
{
	int			in_fd;
	int			filled;
	char		**map;
	char		*filename;
	t_mlx		*mlx;
	t_key		*key;
	t_player	*player;
	t_map_fd	*map_fd;
	t_texture	*texture;
	t_garbage	*garbage;
};

struct s_key
{
	int	w_pressed;
	int	s_pressed;
	int	a_pressed;
	int	d_pressed;
	int	la_pressed;
	int	lr_pressed;
};

struct s_mlx
{
	int		bpp;
	int		line_length;
	int		endian;
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	char	*addr_map;
};

struct s_player
{
	char	dir;
	float	x;
	float	y;
	float	old_x;
	float	old_y;
	float	dir_x;
	float	dir_y;
	float	dx;
	float	dy;
	float	old_dx;
	float	old_dy;
	float	angle;
};

struct s_map_fd
{
	int	begin;
	int	ended;
	int	height;
	int	width;
};

struct	s_texture
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		no_fd;
	int		so_fd;
	int		we_fd;
	int		ea_fd;
	t_color	*c;
	t_color	*f;
};

struct	s_color
{
	int	r;
	int	g;
	int	b;
};

struct	s_garbage
{
	struct s_garbage	*prev;
	void				*ptr;
	struct s_garbage	*next;
};

#endif
