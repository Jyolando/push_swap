# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By:  <>                                        +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2022/01/14 12:24:07 by                   #+#    #+#             #
#   Updated: 202#   Updated: 2022/01/14 22:26:02 by                  ###   ########.fr       #                                                              #
# ************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

SRCS = srcs/main.c \
		srcs/operations/ft_pa_pb.c srcs/operations/ft_ra_rb_rr.c \
		srcs/operations/ft_rra_rrb_rrr.c srcs/operations/ft_sa_sb_ss.c \
		srcs/utils/error.c srcs/utils/ft_parse_atoi.c srcs/utils/ft_stacks.c \
		srcs/utils/print.c srcs/utils/ft_check_sorted.c \
		srcs/utils/find_min.c srcs/sort/minisort.c srcs/sort/fullsort.c \
		srcs/sort/utils/push_to_b.c srcs/sort/utils/push_to_a.c\
		libs/Libft/ft_isdigit.c

OBJ = ${SRCS:.c=.o}

BONUS_SRCS = bonus/checker.c  bonus/utils.c \
		libs/get_next_line/get_next_line.c \
		libs/get_next_line/get_next_line_utils.c \
		srcs/utils/print.c \
		srcs/utils/ft_check_sorted.c \
		srcs/utils/ft_stacks.c srcs/utils/error.c \
		srcs/operations/ft_pa_pb.c srcs/operations/ft_ra_rb_rr.c \
		srcs/operations/ft_rra_rrb_rrr.c srcs/operations/ft_sa_sb_ss.c \
		srcs/utils/ft_parse_atoi.c libs/Libft/ft_isdigit.c

BONUS_OBJ = ${BONUS_SRCS:.c=.o}

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -Wall -Werror -Wextra $(OBJ) -I ./includes/ -o $(NAME)

bonus: $(BONUS_OBJ)
	$(CC) -Wall -Werror -Wextra $(BONUS_OBJ) -I ./includes/ -o $(BONUS_NAME)

clean:
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all
