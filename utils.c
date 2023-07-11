/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:10:05 by mlangloi          #+#    #+#             */
/*   Updated: 2023/06/30 20:10:07 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_red(t_redirect *red)
{
	int	i;

	if (red->left)
		free(red->left);
	red->left = NULL;
	if (red->d_left_to_free)
		free(red->d_left_to_free);
	ft_bzero(red->d_left, 65536);
	i = 0;
	while (i < 100)
	{
		if (red->right[i])
			free(red->right[i]);
		red->right[i++] = NULL;
	}
	i = 0;
	while (i < 100)
	{
		if (red->double_right[i])
			free(red->double_right[i]);
		red->double_right[i++] = NULL;
	}
	red->last_right = NULL;
	red->cmd = NULL;
	free(red);
}

void	handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		if (verif_cat() == 0)
			rl_redisplay();
		exprt("cat=1");
	}
}

int	get_left_file(int fd_in, char *file)
{
	char	*str;

	if (fd_in != 0 && fd_in != 1)
		close(fd_in);
	fd_in = open(file, O_RDONLY);
	if (fd_in == -1)
	{
		perror(file);
		return (-2);
	}
	str = get_str(fd_in);
	if (!str)
		return (-1);
	close(fd_in);
	fd_in = open("temp_redirection_file.txt", O_WRONLY | O_CREAT | O_APPEND,
			S_IRUSR | S_IWUSR);
	write(fd_in, &str[0], ft_strlen(str));
	close(fd_in);
	free(str);
	fd_in = open("temp_redirection_file.txt", O_RDONLY);
	return (fd_in);
}

void	ft_exit(char *str, t_token *token)
{
	if (token)
		free(token);
	if (str)
		free(str);
	if (environ)
		free_array(environ);
	exit(0);
}

int	verif_fleche(t_token *token)
{
	t_token	*token2;

	token2 = token;
	while (token)
	{
		if ((token->str[0] == '<' || token->str[0] == '>')
			&& (token->next == NULL
				|| token->next->str[0] == '<'
				|| token->next->str[0] == '>'))
		{
			ft_printf("Error : Problemes de chevrons.\n");
			ft_free_tokens(token2);
			return (1);
		}
		token = token->next;
	}
	return (0);
}
