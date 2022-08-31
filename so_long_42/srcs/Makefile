# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 13:53:50 by mbertin           #+#    #+#              #
#    Updated: 2022/08/30 15:15:47 by mbertin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
LIBFT		=	../include/libft.a

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

SRCS		=	so_long.c		\
				check_map.c		\
				check_asset.c	\
				init_game.c	\
				move_player.c	\
				check_move_player.c	\
				end_of_game.c	\

OBJS		= 	${SRCS:.c=.o}

# Targets

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

$(NAME): 		$(OBJS)
				@echo "Compiling libft..."
				@echo "libft compiled successfully."
				@echo "Compiling $(NAME) sources"
				@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
#				@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
				@echo "Done !"

all: 			$(NAME)

# Removes objects
clean:
				@echo "Removing $(NAME) objects..."
				@$(RM) $(OBJS)
				@echo "Removing libft objects..."
				@echo "$(NAME) objects successfully deleted."
				@echo "libft objects successfully deleted."

# Removes objects and executable
fclean: 		clean
				@echo "Removing $(NAME) program..."
				@$(RM) $(NAME)
				@echo "Removing libft archive..."
#				@$(RM) $(LIBFT)
				@echo "Executable(s) and archive(s) successfully deleted."

# Removes objects and executable then remakes all
re: 			fclean all

.PHONY:			all clean fclean bonus re
