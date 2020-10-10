/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_button_image.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 12:30:44 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/17 13:18:07 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_set_element_image(t_element *elem, SDL_Surface *img, SDL_Rect *rect)
{
	elem->text.set_text = 0; // you might wnat to free the whole t_text from this elem
	SDL_BlitScaled(img, NULL, elem->states[0], rect);
	SDL_BlitScaled(img, NULL, elem->states[2], rect);
	SDL_BlitScaled(img, NULL, elem->states[1], rect);
	SDL_BlitScaled(img, NULL, elem->surface, rect);
}
