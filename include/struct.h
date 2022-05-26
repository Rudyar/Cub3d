/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:05:31 by arudy             #+#    #+#             */
/*   Updated: 2022/05/26 14:27:58 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_mlx			t_mlx;
typedef struct s_key			t_key;
typedef struct s_ray			t_ray;
typedef struct s_data			t_data;
typedef struct s_color			t_color;
typedef struct s_map_fd			t_map_fd;
typedef struct s_player			t_player;
typedef struct s_texture		t_texture;
typedef struct s_garbage		t_garbage;
typedef struct s_data_texture	t_data_texture;

struct	s_data
{
	int			in_fd;
	int			filled;
	int			win_width;
	int			win_height;
	char		**map;
	char		*m;
	char		*filename;
	t_mlx		*mlx;
	t_key		*key;
	t_ray		*ray;
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
	int		bpp2;
	int		line_length;
	int		line_length2;
	int		endian;
	int		endian2;
	void	*ptr;
	void	*ptr2;
	void	*win;
	void	*win2;
	void	*img;
	void	*img2;
	char	*addr;
	char	*addr2;
};

struct s_ray
{
	int		hit;
	int		side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		line_h;
	int		draw_end;
	int		draw_start;
	float	pwd;
	float	ddy;
	float	ddx;
	float	sdy;
	float	sdx;
	float	dir_x;
	float	dir_y;
	float	old_x;
	float	old_y;
	float	angle;
	float	plane_x;
	float	plane_y;
	float	camera_x;
};

struct s_player
{
	int		change;
	char	dir;
	float	x;
	float	y;
	float	old_x;
	float	old_y;
	float	dir_x;
	float	dir_y;
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

struct s_data_texture
{
	char	*path;
	int		fd;
	void	*addr;
	void	*img;
};

struct	s_texture
{
	t_data_texture	*no;
	t_data_texture	*so;
	t_data_texture	*ea;
	t_data_texture	*we;
	int				c_color;
	int				f_color;
	int				dir;
	t_color			*c;
	t_color			*f;
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
