/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_lexem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 09:16:02 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/18 09:26:05 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

void	ft_clean_lexem(t_token **headref)
{
	t_token	*head;
	t_token *nhead;
	t_token	*node;
	t_token	*tmp;

	head = NULL;
	tmp = NULL;
	node = *headref;
	while (node)
	{
		tmp = node;
		if (node->type != NOT)
		{
			if (head == NULL && (head = node))
				nhead = node;
			else if ((nhead->next = node))
				nhead = nhead->next;
			tmp = NULL;
		}
		node = node->next;
		if (tmp)
			free(tmp);
	}
	nhead->next = NULL;
	*headref = head;
}
