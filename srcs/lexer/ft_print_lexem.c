/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lexem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 21:51:30 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/18 21:56:42 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

char	*ft_type(int	type)
{
	if (type == INT)
		return ("Integer");
	if (type == KWD)
		return ("Keyword");
	if (type == SUM)
		return ("Sum");
	if (type == FACTOR)
		return ("Factor");
	if (type == PTH)
		return ("Bracket");
	return ("bad value");
}

void	ft_print_lexem(t_token *lexem)
{
	while (lexem)
	{
		printf("type:%-10s :%-2d value:%s\n",\
		ft_type(lexem->type), lexem->type, lexem->value);
		lexem = lexem->next;
	}
}
