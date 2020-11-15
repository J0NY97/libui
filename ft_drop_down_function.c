/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drop_down_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:54:31 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/26 16:28:34 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	ft_drop_item_function(SDL_Event e, t_element *elem)
{
	t_list *item;
	t_drop_down *dd;

	dd = elem->parent_elem->info;
	item = dd->items;
	while (item)
	{
		((t_element *)item->content)->state = 0;
		((t_element *)item->content)->default_state = 0;
		item = item->next;
	}
	elem->state = 1;
	elem->default_state = 1;
	ft_update_drop(elem->parent_elem);
	ft_set_text(&elem->parent_elem->text, elem->text.text);
}

// this should be called when new item is added to the drop menu
void	ft_update_drop(t_element *elem)
{
	t_drop_down *dd;
	t_list		*curr;
	t_element	*item;
	SDL_Rect	temp;

	dd = elem->info;
	SDL_FreeSurface(elem->states[1]);
	dd->drop_height = (dd->item_amount + 1) * dd->height;
	elem->states[1] = ft_create_rgba_surface(elem->coord.w, dd->drop_height);
	ft_update_background(elem->states[1], 0xff00ff00);
	curr = dd->items;
	while (curr)
	{
		item = curr->content;
		temp.x = item->rel_coord.x;
		temp.y = item->rel_coord.y;
		temp.w = item->rel_coord.w;
		temp.h = item->rel_coord.h;
		ft_update_element(item);
		SDL_BlitSurface(item->surface, NULL, elem->states[1], &temp);
		curr = curr->next;
	}
}

void	ft_drop_down_function(SDL_Event e, t_element *elem)
{
	t_list		*curr;
	t_element	*item;
	t_drop_down *dd;
	SDL_Rect	temp;

	dd = elem->info;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (elem->state == 1)
		{
			curr = dd->items;
			while (curr)
			{
				item = curr->content;
				item->coord.x = elem->coord.x + item->rel_coord.x;
				item->coord.y = elem->coord.y + item->rel_coord.y;
				item->event_handler(e, item);
				curr = curr->next;
			}
		}
		if (elem->state == 0)
		{
			elem->coord.h = dd->drop_height;
			elem->rel_coord.h = dd->drop_height;
			elem->state = 1;
			elem->default_state = 1;
		}
		else if (elem->state == 1)
		{
			elem->coord.h = dd->height;
			elem->rel_coord.h = dd->height;
			elem->state = 0;
			elem->default_state = 0;
		}
	}
}
