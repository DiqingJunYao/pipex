# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dyao <dyao@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 13:34:59 by dyao              #+#    #+#              #
#    Updated: 2024/07/27 19:07:51 by dyao             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        =   ./error_msg.c \
				./ft_first_child.c \
				./ft_second_child.c \
				./ft_strjoin.c \
				./ft_strlen.c \
				./ft_split.c \
				./ft_get_path_own.c \
				./main.c

LIBFTDIR	= 	libft/

LIBFTOBJS	= 	libft.a

OBJS		= 	$(SRCS:.c=.o)

CC			= 	cc

RM			= 	rm -f

CCFLAGS		= 	-Wall -Werror -Wextra -I.

NAME		= 	pipex.a

all:			libft_build $(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CCFLAGS) $(SRCS) -o pipex
				cp $(LIBFTDIR)$(LIBFTOBJS) $(NAME)
				ar rcs $(NAME) $(OBJS)

libft_build:
				$(MAKE) -C $(LIBFTDIR)

clean:
				$(RM) $(OBJS)
				$(RM) pipex
				cd $(LIBFTDIR) && $(MAKE) clean

fclean:			clean
				$(RM) $(NAME)
				cd $(LIBFTDIR) && $(MAKE) fclean

re:				fclean all

.PHONY:			all clean fclean re $(LIBFTDIR)
