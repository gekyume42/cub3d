/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:28:05 by anguinau          #+#    #+#             */
/*   Updated: 2022/07/04 21:57:50 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include "../ressources/libft/includes/libft.h"
# include <string.h>
# include <stdio.h>

typedef struct s_parsing
{
	char				c;
	struct s_parsing	*next;
}						t_parsing;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_map
{
	int		**map;
	char	*map_infos;
	int		c_color;
	int		f_color;
	t_img	*n_tex;
	t_img	*s_tex;
	t_img	*e_tex;
	t_img	*w_tex;
}			t_map;				

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}			t_mlx;

typedef struct s_data
{
	int		ret;
	int		screen_width;
	int		screen_height;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	screen_x;
	int		move_up;
	int		move_down;
	int		move_right;
	int		move_left;
	int		turn_right;
	int		turn_left;
	double	moved;
	int		draw_start;
	int		draw_end;
	int		side;
	t_img	*tex;
	t_map	map;
	t_mlx	mlx;
}			t_data;

t_data	*data(void);
int		exit_proprely(int print);
int		parse_file(char *path, int i, int fd, t_parsing *index);
int		upload_textures(char *str, int *i, int j, char ref);
int		get_colors(char *str, int *i, int l, char ref);
int		fill_map_struct(char *str, int i, int j);
int		check_map_infos(int i, int j, int inside, int e_count);
int		check_map_walls(int i, int j);
int		create_2d_map(int i, int j, int k, int l);
int		keyrelease_hook(int keycode);
int		keypress_hook(int keycode);
int		loop_hook(void);
int		draw_line(int x, int y, int color);
void	move(void);

#	endif
