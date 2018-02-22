/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:08:11 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/22 22:04:37 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

int		main(void)
{
	char	*res;
	int		r;
	t_token	*lexem;
	t_token *node;
	t_tree	*tree;

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
	printf("\n");
	node = lexem;
	r = parse_sum(&lexem);
	printf("\nresult:%d\n", r);
	lexem = node;
	tree = parser_tree_2(&lexem);
	ft_printf_ast(tree);
	ft_free_lexer(&node);
	return (0);
}
