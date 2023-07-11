/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgrandin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:11:35 by dgrandin          #+#    #+#             */
/*   Updated: 2023/06/21 16:11:36 by dgrandin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	if_pipe(int *fd_in, int *fd_out)
{
	if (access("pipe.txt", F_OK) == 0)
		*fd_in = get_left_file(0, "pipe.txt");
	else
		*fd_in = 1;
	*fd_out = open("pipe.txt", O_RDWR | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR);
}

void	if_not_pipe(int *fd_in, int *fd_out)
{
	if (access("pipe.txt", F_OK) == 0)
		*fd_in = open("pipe.txt", O_RDONLY);
	else
		*fd_in = 1;
	*fd_out = 1;
}

void	red_d_left(int *fd_in, t_redirect *red)
{
	if (*fd_in != 0 && *fd_in != 1)
		close(*fd_in);
	*fd_in = open("temp_redirection_file.txt", O_WRONLY | O_CREAT | O_APPEND,
			S_IRUSR | S_IWUSR);
	write(*fd_in, &red->d_left[0], ft_strlen(red->d_left));
	close(*fd_in);
	*fd_in = open("temp_redirection_file.txt", O_RDONLY);
}

void	red_right(int *fd_out, t_redirect *red, int i)
{
	int	temp_fd;

	if (*fd_out != 0 && *fd_out != 1)
		close(*fd_out);
	if (ft_strcmp(red->right[i], red->last_right) == 0)
		*fd_out = open(red->last_right, O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR);
	else
	{
		temp_fd = open(red->right[i], O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR);
		close(temp_fd);
	}
	i++;
}

void	red_double_right(int *fd_out, t_redirect *red, int i)
{
	int	temp_fd;

	if (*fd_out != 0 && *fd_out != 1)
		close(*fd_out);
	if (ft_strcmp(red->double_right[i], red->last_right) == 0)
		*fd_out = open(red->last_right, O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR);
	else
	{
		temp_fd = open(red->double_right[i], O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR);
		close(temp_fd);
	}
	i++;
}
