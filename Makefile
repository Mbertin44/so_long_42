# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 13:53:50 by mbertin           #+#    #+#              #
#    Updated: 2023/05/17 10:36:54 by mbertin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
LIBFT_PATH	=	libft
MLX_PATH	=	mlx
LIBFT		=	libft/libft.a

CC		=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM		=	rm -f

SRCS		=		so_long.c		\
				check_map.c		\
				check_asset.c	\
				init_game.c	\
				move_player.c	\
				check_move_player.c	\
				end_of_game.c	\
				check_move_villain.c	\
				move_villain.c	\
				key_identification.c	\

OBJS		= 	${SRCS:.c=.o}

.c.o:
				@$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

$(NAME): 		$(OBJS)
				@echo "Compiling libft..."
				@$(MAKE) -C $(LIBFT_PATH) &> /dev/null
				@echo "libft compiled successfully."
				@echo "Compiling mlx..."
				@$(MAKE) -C $(MLX_PATH) &> /dev/null
				@echo "mlx compiled successfully."
				@echo "Compiling $(NAME) sources"
				@$(CC) $(OBJS) $(LIBFT) $(CFLAGS) mlx/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)
				@echo "Done !"

all: 			$(NAME)

# Removes objects
clean:
				@echo "Removing $(NAME) objects..."
				@$(RM) $(OBJS)
				@echo "Removing libft objects..."
				@make clean -C $(LIBFT_PATH)
				@echo "Removing mlx objects..."
				@make clean -C $(MLX_PATH)
				@echo "$(NAME) objects successfully deleted."
				@echo "libft objects successfully deleted."
				@echo "mlx objects successfully deleted."

# Removes objects and executable
fclean: 		clean
				@echo "Removing $(NAME) program..."
				@$(RM) $(NAME)
				@echo "Removing libft archive..."
				@$(RM) $(LIBFT)
				@echo "Executable(s) and archive(s) successfully deleted."

# Removes objects and executable then remakes all
re: 			fclean all

.PHONY:			all clean fclean bonus re
