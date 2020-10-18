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

int	key_pressed(SDL_Event *e, SDL_Keycode key)
{
	if (key == e->key.keysym.sym)
	{
		e->key.keysym.sym = 0;
		return (1);
	}
	return (0);
}
