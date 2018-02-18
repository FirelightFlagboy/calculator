/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:08:11 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/18 09:11:09 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

int		main(void)
{
	char	*res;
	t_token	*lexem;
	t_token	*node;

	res = 0;
	res = ft_read_input();
	if (res == NULL)
		return (0);
	printf("input:%s\n", res);
	if (!(lexem = ft_lexer(res)))
		return (1);
	node = lexem;
	while (node)
	{
		printf("type:%-5d value:%s\n", node->type, node->value);
		node = node->next;
	}
	ft_free_lexer(&lexem);
	return (0);
}
