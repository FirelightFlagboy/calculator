/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:22:31 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/17 21:59:48 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

char	*ft_read_input()
{
	static char	s[2048];
	int			rt;

	dprintf(2, ">>");
	rt = read(1, s, 2048);
	if (rt == -1)
		exit(!!(dprintf(2, "error read\n")));
	if (rt == 2048)
		exit(!!(dprintf(2, "error input too big\n")));
	s[rt] = 0;
	return (s);
}
