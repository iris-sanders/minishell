/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irsander <irsander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:15:42 by irsander          #+#    #+#             */
/*   Updated: 2024/07/12 18:07:37 by irsander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer(char *input)
{
	char **input_split_on_pipes;
	char **input_split_on_spaces;
	int		i;
	int		y;

	//first check input
	// - Consecutive Pipes ('||') or empty commands between pipes (cmd | | cmd2) or leading pipes ( | cmd)-> error
	// - Unclosed single quotes (') or double (") quotes -> error
	// - valid redirection syntax. (< << > >>) should be followed by valid filenames and not consecutive ( >> >> ) -> error
	// - \ and ; not required -> error ///// is '&' required?
	// - ensure that all parentheses used for grouping commands are balanced and correctly nested
	// - Ensure that environment variables (e.g., $HOME) are properly formatted and do not have syntax errors.
	
	//split on pipes
	input_split_on_pipes = ft_split(input, '|');
	if (!input_split_on_pipes)
		ft_error("Wasn't able to split on pipes");
	i = 0;
	y = 0;
	while (input_split_on_pipes[y])
	{
		//split on spaces for every string in 2d array
	}
}