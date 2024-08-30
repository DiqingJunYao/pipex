/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:19:00 by dyao              #+#    #+#             */
/*   Updated: 2024/07/27 19:02:45 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_second_child(char *cmd2, char *read_in_file, int fdpipe, char **envp)
{
	int		mark;
	int		fd;
	char	*temp;
	char	**argv;

	mark = 0;
	fd = 0;
	dup2(fdpipe, STDIN_FILENO);
	argv = ft_split(cmd2, ' ');
	temp = ft_get_evn(envp, "PATH", argv[0]);
	fd = open(read_in_file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	dup2(fd, STDOUT_FILENO);
	mark = execve(temp, argv, envp);
	if (mark)
	{
		error_msg(mark);
		free (temp);
		exit (EXIT_FAILURE);
	}
	close(fd);
	close (fdpipe);
	exit (EXIT_FAILURE);
}
