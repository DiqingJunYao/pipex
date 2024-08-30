/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:32:35 by dyao              #+#    #+#             */
/*   Updated: 2024/07/27 15:47:09 by dyao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	error_msg(int errnub);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_get_evn(char **evnp, char *keyword, char *cmd);
void	ft_first_child(int fd, char *cmd1, int fdpipe, char **envp);
void	ft_second_child(char *cmd2,
			char *read_in_file, int fdpipe, char **envp);

#endif