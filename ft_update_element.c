/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:38:36 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/26 13:39:28 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		ft_update_element(t_element *elem)
{
	if (elem->statique == 0)
	{
		if (elem->surface) // just to make so so no free errors
			SDL_FreeSurface(elem->surface);
		if (elem->state < 0 && elem->state > 2) // to make sure there are that many states if not elem->state, default to 0
			elem->state = 0;
		elem->surface = ft_create_rgba_surface(elem->states[elem->state]->w,
											elem->states[elem->state]->h);
		SDL_BlitSurface(elem->states[elem->state], NULL, elem->surface, NULL);
		if (elem->text.set_text == 1)
		{
			elem->text.parent = elem->surface;
			ft_create_text(&elem->text);
		}
		elem->state = elem->default_state;
	}
}
