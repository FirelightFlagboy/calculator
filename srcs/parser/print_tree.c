/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:51:33 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/24 14:08:08 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

static void	ft_printf_ast_util(t_tree *head, int space, int count)
{
	int i;
	
	if (head == NULL)
		return ;
	space += 5;
	ft_printf_ast_util(head->high, space, count + 1);
	printf("\n");
	for (i = 5; i < space; i++)
		printf(" ");

	printf("%d:%s\n", count, head->val);
	ft_printf_ast_util(head->low, space, count + 2);
}

void	ft_printf_ast(t_tree *head)
{
	printf("\nPrint ast\n");
	ft_printf_ast_util(head, 0, 1);
}
