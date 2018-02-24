/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <f.benneto@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 21:08:47 by fbenneto          #+#    #+#             */
/*   Updated: 2018/02/24 10:59:47 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALCULATOR_H
# define CALCULATOR_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

enum	e_type
{
	NOT,
	SUM,
	FACTOR,
	INT,
	PTH,
	KWD,
};

typedef struct	s_token
{
	int				type;
	char			value[65];
	struct s_token	*next;
}				t_token;

typedef struct	s_tree
{
	int				type;
	t_token			*token;
	char			*val;
	int				nb;
	char			*opt;
	struct s_tree	*low;
	struct s_tree	*high;
}				t_tree;

/*
** Print
*/
void	ft_print_lexem(t_token *lexem);
void	ft_printf_ast(t_tree *head);
/*
** Input
*/
char	*ft_read_input();
/*
** Lexer
*/
t_token	*ft_create_token(void);
t_token	*ft_lexer();
void	ft_clean_lexem(t_token **headref);
void	ft_free_lexer();
void	ft_tf_opt_lexem(t_token **headref);
/*
** Parser
*/
void	cut_input(t_token *input, t_token **i_l, t_token **i_r, int index);
t_tree	*parser_tree(t_token **head);
t_tree	*parser_tree_2(t_token **head);
int		parse_sum(t_token **head);
int		parse_factor(t_token **head);
int		parse_product(t_token **head);
int		parse_pth(t_token **head);
/*
** Tree
*/
void	ft_ttree_free(t_tree **head);
t_tree	*ft_ttre_create(int type, char *value, char *isneg);
/*
** ft_type
*/
int		ft_isdigits(int c);
int		ft_isspaces(int c);
#endif
