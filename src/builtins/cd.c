/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavdiiev <tavdiiev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 21:07:52 by tavdiiev          #+#    #+#             */
/*   Updated: 2024/07/19 19:25:00 by tavdiiev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/minishell.h"

static void update_wd(t_data *data, char *wd)
{
	set_env(data, "OLDPWD", get_env_value(data->env, "PWD"));
	set_env(data, "PWD", wd);
	if (data->old_working_dir)
	{
		free_ptr(data->old_working_dir);
		data->old_working_dir = ft_strdup(data->working_dir);
	}
	if (data->working_dir)
	{
		free_ptr(data->working_dir);
		data->working_dir = ft_strdup(wd);
	}
	free_ptr(wd);
}

/*
*	chdir can sometimes set errno to ESTALE ("Stale file handle")
*	when a parent directory is removed on some systems. This is due
*	to the inode table entry being recycled. This is a fix to display
*	"no such file or directory" error instead.
*/
static	int	chdir_error_msg(char *path)
{
	if (errno == ESTALE)
		errno = ENOENT;
	error_msg_command("cd", path, strerror(errno), errno);
	return (EXIT_FAILURE);
}

static	int change_directory(t_data *data, char *path)
{
	char	*wd;
	char	*tmp;
	char	cwd[PATH_MAX];

	if (chdir(path) != 0)
		return (chdir_error_msg(path));
	wd = getcwd(cwd, PATH_MAX);
	if (!wd)
	{
		error_msg_command("cd: error retrieving current directory",
	"getcwd: cannot access parent directories",
	strerror(errno), errno);
		wd = ft_strjoin(data->working_dir, "/");
		tmp = wd;
		wd = ft_strjoin(tmp, path);
		free_ptr(tmp);
	}
	else
		wd = ft_strdup(cwd);
	update_wd(data, wd);
	return (EXIT_SUCCESS);
}

int	cd(t_data *data, char ** args)
{
	char	*path;

	if (!args || !args[1] || ft_strncmp(args[1], "--", 2) == 0)
	{
		path = get_env_value(data->env, "HOME");
		if (!path || path[0] == '\0' || path[0] == ' ')
		return (error_msg_command("cd", NULL, "HOME not set", EXIT_FAILURE));
			return (EXIT_FAILURE);
		return (!change_directory(data, path));
	}
		if (args[2])
			return (error_msg_command("cd", NULL, "too many arguments", EXIT_FAILURE));
		if (ft_strncmp(args[1], "-", 1) == 0)
		{
			path = get_env_value(data->env, "OLDPWD");
		if (!path)
			return (error_msg_command("cd", NULL, "OLDPWD not set", EXIT_FAILURE));
				return (EXIT_FAILURE);
		return (!change_directory(data, path));
		}
	return (!change_directory(data, args[1]));
}