/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:08:11 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/24 12:47:38 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

void	ft_parser_direct(t_token *lexem)
{
	int		r;
	
	r = parse_sum(&lexem);
	printf("\ndirect result:%d\n", r);
}

void	ft_parser_ast(t_token *lexem)
{
	t_tree	*tree;
	
	tree = parser_tree(&lexem);
	ft_printf_ast(tree);
	dprintf(2, "free tree\n");
	ft_ttree_free(&tree);
}

int		main(void)
{
	char	*res;
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
	printf("lexer :\n");
	ft_print_lexem(lexem);
	ft_parser_direct(lexem);
	ft_parser_ast(lexem);
	dprintf(2, "free lexer\n");
	ft_free_lexer(&lexem);
	return (0);
}
