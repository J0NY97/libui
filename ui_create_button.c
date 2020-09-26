/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_create_button.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 11:04:46 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/26 13:53:51 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		default_click(SDL_Event e, t_element *elem)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
		ft_putstr("An element was clicked.\n");
	else if (e.type == SDL_MOUSEMOTION)
		ft_putstr("An element was hovered.\n");
}

void		single_click(SDL_Event e, t_element *elem)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		ft_putstr("A button was clicked.\n");
		elem->state = 1;
	}
}

void		toggle_click(SDL_Event e, t_element *elem)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		ft_putstr("A button was clicked.\n");
		if (elem->state == 1)
			elem->default_state = 0;
		else if (elem->state == 0)
			elem->default_state = 1;
	}
}

t_element	*ui_create_button(t_window *win, t_xywh rel_coord, t_element *parent)
{
	t_element_info info;
	t_element	*elem;

	info = ft_default_elem_info(win, rel_coord, parent);
	info.info = (t_button *)malloc(sizeof(t_button));
	info.info_size = 0;
	info.f = &default_click;
	elem = ft_create_element(info);
	ft_add_element_to_window_elements(win, elem);
	return (elem);
}
