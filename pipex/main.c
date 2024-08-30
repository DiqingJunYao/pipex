/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:38:36 by dyao              #+#    #+#             */
/*   Updated: 2024/07/27 18:59:48 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_check_argv(int argc)
{
	if (argc != 5)
	{
		write(2, "You have to input everything correct!", 38);
		exit (EXIT_FAILURE);
	}
}

static int	ft_open_file(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0777);
	if (fd == -1)
	{
		perror("Failed to open file");
		return (1);
	}
	return (fd);
}

static void	ft_wait_pid(pid_t pid_first, pid_t pid_second)
{
	int	status;
	int	i;

	i = waitpid(pid_first, &status, 0);
	if (i == -1)
	{
		perror("Error waiting for first process");
		exit (EXIT_FAILURE);
	}
	if (!(WIFEXITED(status)))
		perror("First process did not exit normally!");
	i = waitpid(pid_second, &status, 0);
	if (i == -1)
	{
		perror("Error waiting for second process");
		exit (EXIT_FAILURE);
	}
	if (!(WIFEXITED(status)))
		perror("Second process did not exit normally!");
}

int	main(int argc, char **argv, char **envp)
{
	int		mark;
	int		fd;
	int		fdpipe[2];
	pid_t	pid_first;
	pid_t	pid_second;

	mark = 0;
	ft_check_argv(argc);
	mark = pipe(fdpipe);
	if (mark != 0)
		error_msg(mark);
	fd = ft_open_file(argv[1]);
	pid_first = fork();
	if (pid_first == 0)
		ft_first_child(fd, argv[2], fdpipe[1], envp);
	else if (pid_first > 0)
	{
		close(fdpipe[1]);
		pid_second = fork();
		if (pid_second == 0)
			ft_second_child(argv[3], argv[4], fdpipe[0], envp);
		else if (pid_second > 0)
			ft_wait_pid(pid_first, pid_second);
	}
	return (0);
}
