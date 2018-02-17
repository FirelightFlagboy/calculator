/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 22:04:29 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/17 22:15:56 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

static t_token	*ft_create_token(void)
{
	t_token *node;

	if (!(node = (t_token*)malloc(sizeof(t_token))))
		return (NULL);
	node->next = 0;
	node->type = NOT;
	node->value[0] = 0;
}

void			ft_free_lexer(t_token **headref)
{
	t_token *node;
	t_token *tmp;

	if (headref == NULL)
		return ;
	node = *headref
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*headref = NULL;
}

t_token			*ft_lexer(char	*res)
{
	t_token *head;
	t_token	*node;

	if (!(head = ft_create_token()))
		return (NULL);
	node = head;
	while (*res)
	{
		res++;
	}
	return (head);
}
