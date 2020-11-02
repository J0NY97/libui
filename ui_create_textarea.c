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

void		text_area(SDL_Event e, t_element *elem)
{
	char		*tmp;

	if (e.type == SDL_MOUSEBUTTONDOWN && elem->loop != 1)
	{
		elem->loop = 1;
		free(elem->text.text);
		elem->text.text = ft_strdup("<-");
	}
	else if (e.type == SDL_TEXTINPUT)
	{
		tmp = ft_strndup(elem->text.text, (ft_strlen(elem->text.text) - 2));
		ft_strdel(&elem->text.text);
		elem->text.text = ft_strjoiner(tmp, e.text.text, "<-");
		free(tmp);
	}
	else if (elem->loop == 1 && e.key.keysym.sym == SDLK_BACKSPACE && e.type == SDL_KEYDOWN)
	{
		tmp = ft_strndup(elem->text.text, (ft_strlen(elem->text.text) - 3));
		ft_strdel(&elem->text.text);
		elem->text.text = ft_strjoin(tmp, "<-");
		free(tmp);
	}
	if (elem->loop == 1 && e.key.keysym.sym == SDLK_RETURN)
	{
		tmp = ft_strndup(elem->text.text, (ft_strlen(elem->text.text) - 2));
		ft_strdel(&elem->text.text);
		elem->text.text = ft_strdup(tmp);
		free(tmp);
		elem->loop = 0;
	}
}

t_element		*ui_create_textarea(t_window *win, t_xywh rel_coord, t_element *parent)
{
	t_element_info	info;
	t_element		*elem;

	info = ft_default_elem_info(win, rel_coord, parent);
	info.info = (t_textarea *)malloc(sizeof(t_textarea));
	info.info_size = 0;
	info.f = &text_area;
	elem = ft_create_element(info);
	ft_set_text(&elem->text, "empty");
	ft_add_element_to_window_elements(win, elem);
	return (elem);
}
