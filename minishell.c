/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:44:23 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/21 14:49:23 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**environ;

char	*get_abs_path2(char *path, char **cmd, char *bin)
{
	char	**path_split;
	int		i;

	path_split = NULL;
	i = -1;
	path_split = ft_split(path, ':');
	free(path);
	path = NULL;
	while (path_split[++i])
	{
		bin = (char *)ft_calloc(sizeof(char),
				(ft_strlen(path_split[i]) + 1 + ft_strlen(cmd[0]) + 1));
		if (bin == NULL)
			break ;
		ft_strlcat(bin, path_split[i],
			ft_strlen(bin) + ft_strlen(path_split[i]) + 1);
		ft_strlcat(bin, "/", ft_strlen(bin) + 2);
		ft_strlcat(bin, cmd[0], ft_strlen(bin) + ft_strlen(cmd[0]) + 1);
		if (access(bin, F_OK) == 0)
			break ;
		free(bin);
		bin = NULL;
	}
	free_array(path_split);
	return (bin);
}

char	*ft_get_path(void)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strncmp(environ[i], "PATH", 4) == 0)
		{
			j = 0;
			path = malloc(sizeof(*path) * (ft_strlen(environ[i]) - 4));
			if (!path)
				return (NULL);
			while (environ[i][j + 5])
			{
				path[j] = environ[i][4 + j];
				j++;
			}
			path[j] = '\0';
			return (path);
		}
		i++;
	}
	return (NULL);
}

char	*get_abs_path(char **cmd)
{
	char	*path;
	char	*bin;

	bin = NULL;
	path = ft_get_path();
	if (path != NULL)
	{
		bin = get_abs_path2(path, cmd, bin);
		return (bin);
	}
	else
		return (NULL);
}

int	minishell(char *str, t_struct *la_struct, char **cmd)
{
	int			error;

	if (str == NULL)
	{
		free_array(environ);
		exit(0);
	}
	if (str)
	{
		if (str_is_good(str))
			add_history(str);
	}
	cmd = ft_parse(str, la_struct);
	if (cmd != NULL)
	{
		if (cmd[0] && check_str_cwa(cmd) == 1)
			exprt("cat=0");
		error = manage_split(cmd);
		free(cmd);
		if (error == 404)
			return (1);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_struct	la_struct;
	char		*str;
	char		**cmd;
	int			fin;

	(void)ac;
	(void)av;
	if (setenviron(env) == 1)
		return (1);
	cmd = NULL;
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, SIG_IGN);
	while (42)
	{
		str = readline("Minishell> ");
		fin = minishell(str, &la_struct, cmd);
		if (fin == 1)
			break ;
	}
	free_array(environ);
	return (0);
}
