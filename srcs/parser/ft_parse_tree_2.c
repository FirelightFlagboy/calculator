/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tree_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 21:14:18 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/22 22:10:46 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"
//prio : [1 = '+|-', 2 = '*|/', 3 = '(|)']

int		search_input(t_token *input, int prio)
{
	int		res;

	res = 0;
	if (prio > INT)
		return (0);
	while (input)
	{
		if (input->type == prio)
			return (res);
		res++;
		input = input->next;
	}
	return (0);
}

void	cut_input(t_token *input, t_token **i_l, t_token **i_r, int index)
{
	t_token *prev;

	prev = NULL;
	*i_l = input;
	while (input && index)
	{
		index--;
		prev = input;
		input = input->next;
	}
	if (input)
	{
		prev->next = NULL;
		*i_r = input;
	}
}

t_tree *insert_tree(t_tree *tree, t_token *input, int index)
{
	if (!(tree = (t_tree*)malloc(sizeof(t_tree))))
		return (NULL);
	tree->high = NULL;
	tree->low = NULL;
	while (input && index)
	{
		index--;
		input = input->next;
	}
	tree->token = input;
	return (tree);
}

t_tree *cut_input_and_build_leaf(t_tree *tree, t_token *input, int prio)
{
	int index_input;
	t_token	*input_left;
	t_token	*input_right;
	
	input_left = NULL;
	input_right = NULL;
	index_input = search_input(input, prio);
	if (index_input)
	{
		tree = insert_tree(tree, input, index_input);
		cut_input(input, &input_left, &input_right, index_input);
		tree->high = cut_input_and_build_leaf(NULL, input_left, prio + 1);
		tree->low = cut_input_and_build_leaf(NULL, input_right, prio);
	}
	return (tree);
}

t_tree		*parser_tree_2(t_token **head)
{
	t_tree *tree;

	tree = cut_input_and_build_leaf(NULL, *head, 1);
	return (tree);
}
