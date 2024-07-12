/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irsander <irsander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:15:42 by irsander          #+#    #+#             */
/*   Updated: 2024/07/12 17:45:57 by irsander         ###   ########.fr       */
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
	//split on pipes
	input_split_on_pipes = ft_split(input, '|');
	if (!input_split_on_pipes)
		ft_error("Wasn't able to split on pipes");
	//split on spaces call function for every string -> put into struct
	i = 0;
	y = 0;
	while (input_split_on_pipes[y])
	{
		//split the input splitted on the pipes now again but for the delimiter space
	}
}