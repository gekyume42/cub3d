/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:25:52 by anguinau          #+#    #+#             */
/*   Updated: 2022/07/04 22:27:14 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	put_from_tex(int x, int y, int i, int j)
{
	(data())->tex = (data())->map.n_tex;
	if ((data())->side == 2)
		(data())->tex = (data())->map.s_tex;
	if ((data())->side == 3)
		(data())->tex = (data())->map.e_tex;
	if ((data())->side == 4)
		(data())->tex = (data())->map.w_tex;
	j = (y - (data())->draw_start) * ((data())->tex->height
			/ ((data())->draw_end - (data())->draw_start));
	// Find i
	mlx_pixel_put((data())->mlx.ptr, (data())->mlx.win, x, y,
		*(unsigned int *)((data())->tex->addr
			+ (j * (data())->tex->line_length + i
				* ((data())->tex->bits_per_pixel / 8))));
}

int	draw_line(int x, int y, int color)
{
	while (++y < (data())->screen_height)
	{
		if (y < (data())->draw_start || y > (data())->draw_end)
		{
			color = (data())->map.c_color;
			if (y >= (data())->screen_height / 2)
				color = (data())->map.f_color;
			mlx_pixel_put((data())->mlx.ptr, (data())->mlx.win, x, y, color);
		}
		else
			put_from_tex(x, y, 0, 0);
	}
	return (1);
}
