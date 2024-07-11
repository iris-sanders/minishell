/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irsander <irsander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:30:21 by irsander          #+#    #+#             */
/*   Updated: 2024/07/11 23:49:10 by irsander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv)
{
    char    *command_line_input;

    (void)argc;
    (void)argv;
    while (1)
    {
        command_line_input = readline(PROMPT);
        ft_printf("%s", command_line_input);
    }
    return(0);
}