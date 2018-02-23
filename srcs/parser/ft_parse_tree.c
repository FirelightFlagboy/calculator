/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:36:25 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/23 21:41:14 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

/*
** 2*3+4*5:
**      +
**    /  \
**   *    *
**  /\  /\
**  2 3 4 5
*/

int			search_input_tree(t_token **head, int type)
{
	t_token	*node;
	int		index;

	node = *head;
	index = 0;
	while (node)
	{
		if (node->type == type)
			return (index);
		else if (node->type != INT)
			break;
		index++;
	}
	return (-1);
}

// void		parse_factor_tree(t_token **head, t_tree **tree)
// {
// }

// void		parse_product_tree(t_token **head, t_tree **tree)
// {
// }

void		parse_sum_tree(t_token **head, t_tree **tree)
{
	t_tree	*node;
	t_token	*token;
	int		index;

	(void)tree;
	(void)node;
	printf("parse sum : \n");
	index = search_input_tree(head, SUM);
	token = *head;
	printf("\tindex : %d\n", index);
	while (index >= 0)
	{
		token = token->next;
		index--;
	}
	printf("\tvalue : %s\n", token->value);
}

t_tree		*parser_tree(t_token **head)
{
	t_tree	*tree;

	tree = NULL;
	parse_sum_tree(head, &tree);
	return (tree);
}
