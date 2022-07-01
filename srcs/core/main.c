/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:03:36 by anguinau          #+#    #+#             */
/*   Updated: 2022/07/01 02:31:38 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	init_data(void)
{
	data();
	(data())->map.map = NULL;
	(data())->map.map_infos = NULL;
	(data())->map.c_color = 0;
	(data())->map.f_color = 0;
	(data())->map.n_tex = NULL;
	(data())->map.s_tex = NULL;
	(data())->map.e_tex = NULL;
	(data())->map.w_tex = NULL;
	(data())->mlx.ptr = mlx_init();
}

int	init_mlx(void)
{
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		init_data();
		(data())->ret = parse_file(av[1], 0, 0, NULL);
		if (!(data())->ret)
			return (exit_proprely(1));
		if ((data())->ret == -1)
			return (exit_proprely(0));
		if (!init_mlx())
			return (exit_proprely(0));
//		mlx_loop((data())->mlx.ptr);
	}
	else
		ft_putstr_fd("We want 1 .cub file\n", 1);
	return (exit_proprely(0));
}
