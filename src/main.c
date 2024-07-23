/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irsander <irsander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:30:21 by irsander          #+#    #+#             */
/*   Updated: 2024/07/23 16:00:28 by irsander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(char *msg)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    char    *input;

    (void)argc;
    (void)argv;
    while (1)
    {
        input = readline(PROMPT);
        if (input == NULL)
            ft_error("Failed to read input");
        add_history(input);
        lexer(input);
        //parser
        //executor
        free(input);
    }
    return(0);
}