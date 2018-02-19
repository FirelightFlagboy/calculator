/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 22:11:56 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/19 22:21:09 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

t_token	*ft_create_token(void)
{
	t_token *node;

	if (!(node = (t_token*)malloc(sizeof(t_token))))
		return (NULL);
	node->next = 0;
	node->type = NOT;
	node->value[0] = 0;
	return (node);
}

void			ft_free_lexer(t_token **headref)
{
	t_token *node;
	t_token *tmp;

	if (headref == NULL)
		return ;
	node = *headref;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	*headref = NULL;
}
