/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:22:31 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/17 21:51:29 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

char	*ft_read_input()
{
	static char	s[2048];
	int			rt;

	dprintf(2, ">>");
	while ((rt = read(stdin->_file, s, 2048)))
	{
		if (rt == 2048)
			exit(!!(dprintf(2, "error input too big\n")));
		s[rt] = 0;
	}
	return (s);
}
