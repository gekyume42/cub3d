/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:28:05 by anguinau          #+#    #+#             */
/*   Updated: 2022/07/01 00:42:21 by anguinau         ###   ########.fr       */
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
	float	player_x;
	float	player_y;
	int		ray_x;
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

#	endif
