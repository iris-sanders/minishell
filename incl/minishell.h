/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irsander <irsander@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:26:32 by irsander          #+#    #+#             */
/*   Updated: 2024/07/23 16:01:21 by irsander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "prompt.h"
# include "stdio.h"
# include "readline/readline.h"
# include "readline/history.h"
# include "stdbool.h"

//iris:
//lexer: 
 void	lexer(char *input);
 
//main:
void	ft_error(char *msg);

#endif