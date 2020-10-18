/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:07:25 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/27 16:30:53 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

// @Note: the t_xywh coord in the t_elements doessnt actully use w and h, they
// are just the x2 and y2... if you know what i mean
int		mouse_hover(SDL_Event *e, t_xywh rect)
{
	int x;
	int y;

	SDL_GetMouseState(&x, &y);
	if (x >= rect.x && x <= rect.w &&
		y >= rect.y && y <= rect.w)
	{
		return (1);
	}
	return (0);
}
