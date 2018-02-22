/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:51:33 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/22 22:16:34 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

static void	ft_printf_ast_util(t_tree *head, int space)
{
	int i;
	
	if (head)
		return ;
	space += 5;
	ft_printf_ast(head->high, space);
	printf("\n");
	for (i = 5; i < space; i++)
		printf(" ");
	printf("%s\n", head->token->value);
	ft_printf_ast(head->low, space);
}

void	ft_printf_ast(t_tree *head)
{
	ft_printf_ast_util(head, 0);
}
