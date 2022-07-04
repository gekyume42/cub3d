/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anguinau <constantasg@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 02:25:57 by anguinau          #+#    #+#             */
/*   Updated: 2022/07/04 21:57:17 by anguinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	loop_hook(void)
{
	if (!(data())->moved)
		return (1);
	move();
	(data())->screen_x = -1;
	while (++(data())->screen_x < (data())->screen_width)
	{
	//	Find draw_start & draw_end && side
	//	draw_line(x, -1, -1);
	}
	return (1);
}
