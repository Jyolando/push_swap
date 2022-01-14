# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By:  <>                                        +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2022/01/14 12:24:07 by                   #+#    #+#             #
#   Updated: 202#   Updated: 2022/01/14 22:13:03 by                  ###   ########.fr       #                                                              #
# ************************************************************************** #

NAME = push_swap

SRCS = srcs/main.c \
		srcs/operations/ft_pa_pb.c srcs/operations/ft_ra_rb_rr.c \
		srcs/operations/ft_rra_rrb_rrr.c srcs/operations/ft_sa_sb_ss.c \
		srcs/utils/error.c srcs/utils/ft_parse_atoi.c srcs/utils/ft_stacks.c \
		srcs/utils/init.c srcs/utils/print.c \
		libs/Libft/ft_isdigit.c

OBJ = ${SRCS:.c=.o}

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -Wall -Werror -Wextra $(OBJ) -I ./includes/ -o $(NAME)

clean:
	rm -rf $(OBJ) $(NAME)