/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popup_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:11:56 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/19 13:19:06 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		mouse_pressed(SDL_Event *e, Uint8 button)
{
	if (button == e->button.button && e->button.type == SDL_MOUSEBUTTONDOWN)
	{
		e->button.button = 0;
		return (1);
	}
	return (0);
}
