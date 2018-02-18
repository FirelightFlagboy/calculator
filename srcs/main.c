/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:08:11 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/18 21:58:06 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

int		main(void)
{
	char	*res;
	int		r;
	t_token	*lexem;

	res = 0;
	res = ft_read_input();
	if (res == NULL)
		return (0);
	printf("input:%s\n", res);
	if (!(lexem = ft_lexer(res)))
		return (1);
	ft_clean_lexem(&lexem);
	ft_tf_opt_lexem(&lexem);
	ft_print_lexem(lexem);
	r = parse_sum(lexem);
	printf("result:%d\n", r);
	ft_free_lexer(&lexem);
	return (0);
}
