/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drop_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:11:57 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/19 11:13:47 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	add_to_lst(t_list **list, void *new_v, size_t size)
{
	t_list *lst;

	lst = ft_lstnew(0, 0);
	lst->content = new_v;
	lst->content_size = size;
	if (*list == NULL)
		*list = lst;
	else
		ft_lstadd(list, lst);
}
