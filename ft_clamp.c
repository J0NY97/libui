/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 11:55:16 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/10 11:56:49 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int	ft_clamp(int val, int min, int max)
{
	if (val < min)
		return (min);
	else if (val > max)
		return (max);
	return (val);
}
