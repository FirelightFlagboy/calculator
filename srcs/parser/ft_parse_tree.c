/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 21:36:25 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/23 21:57:50 by fbenneto         ###   ########.fr       */
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

int			search_input_tree(t_token *token, int type)
{
	int		index;

	index = 0;
	while (token)
	{
		if (token->type == type)
			return (index);
		else if (token->type != INT)
			break;
		token = token->next;
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

t_tree	*parse_sum_tree(t_token *token)
{
	t_tree	*node;
	t_token	*t_right;
	t_token	*t_left;
	int		index;

	index = search_input_tree(token, SUM);
	cut_input(token, &t_left, &t_right, index);
	node = insert_tree(token, index);
}

t_tree		*parser_tree(t_token **head)
{
	t_tree	*tree;

	tree = parse_sum_tree(*head);
	tree = NULL;
	return (tree);
}
