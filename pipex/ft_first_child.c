/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_child.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:33:33 by dyao              #+#    #+#             */
/*   Updated: 2024/07/27 19:03:24 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_child(int fd, char *cmd1, int fdpipe, char **envp)
{
	int		mark;
	char	*temp;
	char	**argv;

	mark = 0;
	dup2(fd, STDIN_FILENO);
	close(fd);
	argv = ft_split(cmd1, ' ');
	temp = ft_get_evn(envp, "PATH", argv[0]);
	dup2(fdpipe, STDOUT_FILENO);
	mark = execve(temp, argv, envp);
	if (mark)
	{
		error_msg(mark);
		free (temp);
		exit (EXIT_FAILURE);
	}
	close(fdpipe);
	exit (EXIT_FAILURE);
}
