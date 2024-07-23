/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irsander <irsander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:15:42 by irsander          #+#    #+#             */
/*   Updated: 2024/07/23 16:11:44 by irsander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (true);
	return (false);
}

static void pipe_syntax_check(char *input)
{
	int i;
	
	if (ft_strnstr(input, "||", ft_strlen(input)))
		ft_error("Consecutive pipes found");
	if (input[0] == '|')
		ft_error("Leading pipe found");
	i = 0;
	while (input[i])
	{
		if (input[i] == '|')
		{
			i++;
			while (input[i] && ft_isspace(input[i]) == true)
				i++;
			if (input[i] == '\0' || input[i] == '|')
				ft_error("Empty command between pipes");
		}
		i++;
	}
	//trailing pipes error necessary?
}

static void quote_syntax_check(char *input)
{
	int i;
	char quote;
	
	i = 0;
	quote = '\0';
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '\"')
		{
			if (quote == '\0') 
				quote = input[i];
			else if (quote == input[i])
				quote = '\0';
		}
		i++;
	}
	if (quote != '\0')
		ft_error("unclosed quote found");
}

// static void redirection_syntax_check(input)
// {
	
// }

void	lexer(char *input)
{
	// char **input_split_on_pipes;
	// char **input_split_on_spaces;
	// int		i;
	// int		y;

	//first check input
	// - Consecutive Pipes ('||') or empty commands between pipes (cmd | | cmd2) or leading pipes ( | cmd)-> error
	pipe_syntax_check(input); //fix exit status
	// - Unclosed single quotes (') or double (") quotes -> error
	quote_syntax_check(input); //fix exit status
	// - valid redirection syntax. (< << > >>) should be followed by valid filenames and not consecutive ( >> >> ) -> error
	// redirection_syntax_check(input);
	// - \ and ; not required -> error ///// is '&' required?
	// - ensure that all parentheses used for grouping commands are balanced and correctly nested
	// - Ensure that environment variables (e.g., $HOME) are properly formatted and do not have syntax errors.
	
	//split on pipes
	// input_split_on_pipes = ft_split(input, '|');
	// if (!input_split_on_pipes)
	// 	ft_error("Wasn't able to split on pipes");
	// i = 0;
	// y = 0;
	// while (input_split_on_pipes[y])
	// {
		//split on spaces for every string in 2d array
	// }
}