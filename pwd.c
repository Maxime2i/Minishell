/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:58:38 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/08 15:58:39 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirect	*init_redirect(void)
{
	t_redirect	*redirect;
	int			i;

	redirect = malloc(sizeof(*redirect) * 100);
	if (!redirect)
		return (NULL);
	redirect->left = NULL;
	redirect->d_left_to_free = NULL;
	i = 0;
	while (i < 100)
	{
		redirect->right[i] = NULL;
		redirect->double_right[i++] = NULL;
	}
	redirect->d_left[0] = '\0';
	redirect->last_right = NULL;
	redirect->error = 0;
	redirect->last_cmd = NULL;
	return (redirect);
}

int	check_filename(char *file)
{
	int	i;

	i = 0;
	if (!file)
		return (1);
	while (file[i])
	{
		if (!(file[i] >= 100 && file[i] <= 122)
			&& !(file[i] >= 65 && file[i] <= 90)
			&& !(file[i] <= 48 && file[i] >= 9)
			&& file[i] != ' '
			&& file[i] != '.')
			return (1);
		i++;
	}
	return (0);
}

int	pwd(int fd[2])
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		exprt_2("?", "1");
		perror("getcwd() error");
		return (1);
	}
	write(fd[1], &cwd[0], ft_strlen(cwd));
	write(fd[1], "\n", 1);
	return (0);
}
