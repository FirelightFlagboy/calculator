/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 22:04:29 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/19 22:13:21 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculator.h"

char			*ft_add_nb(t_token **noderef, char *str)
{
	int		i;
	t_token	*node;

	i = 0;
	node = *noderef;
	node->type = INT;
	while (ft_isdigits(str[i]))
	{
		node->value[i] = str[i];
		i++;
	}
	node->value[i] = 0;
	if (!(*noderef = ft_create_token()))
		exit(!!dprintf(2, "error malloc ft_add_nb:%s\n", strerror(errno)));
	node->next = *noderef;
	return (str + i);
}

char			*ft_add_kwd(t_token **noderef, char *str, char *keyword)
{
	int		i;
	t_token	*node;

	i = -1;
	node = *noderef;
	node->type = KWD;
	while (keyword[++i])
		node->value[i] = keyword[i];
	node->value[i] = 0;
	if (!(*noderef = ft_create_token()))
		exit(!!dprintf(2, "error malloc ft_add_kwd%s\n", strerror(errno)));
	node->next = *noderef;
	return (str + i);
}

t_token			*ft_lexer(char	*res)
{
	t_token	*head;
	t_token	*node;
	char	*keyword[]={"(", ")", "+", "-", "*", "/", "%", NULL};
	int		n;
	int		i;

	if (!(head = ft_create_token()))
		return (NULL);
	node = head;
	while (*res)
	{
		n = 0;
		if (ft_isdigits(*res) && (n = 1))
			res = ft_add_nb(&node, res);
		i = -1;
		while (keyword[++i])
			if (strncmp(keyword[i], res, strlen(keyword[i])) == 0 && (n = 1))
			{
				res = ft_add_kwd(&node, res, keyword[i]);
				break ;
			}
		if (!n)
			res++;
	}
	return (head);
}
