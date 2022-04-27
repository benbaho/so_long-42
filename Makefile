CC			= gcc
MINILIBX	= Mlx/libmlx.a
FLAGS		= -Wall -Wextra -Werror
LFLAGS		= -framework OpenGL -framework AppKit
NAME		= so_long
SRCS 		= so_long.c converto.c create_map.c initmap.c split.c keys.c so_long_utilts.c
OBJS		= $(SRCS:.c=.o)
PRINTF		= printf/libftprintf.a
LIBFT		= libft/libft.a

all: $(NAME)

$(NAME): $(MINILIBX) $(OBJS) $(PRINTF) $(LIBFT)
	$(CC) $(LFLAGS) $(FLAGS) $(OBJS) -o $(NAME) ./printf/libftprintf.a ./libft/libft.a Mlx/libmlx.a

$(MINILIBX):
	make -C Mlx

$(PRINTF):
	make -C printf

$(LIBFT):
	make -C libft

re: fclean all

norm : 
	norminette *.c
	norminette *.h

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	@make clean -C Mlx
	@make fclean -C printf
	@make fclean -C libft

.PHONY: clean run fclean re all norm
