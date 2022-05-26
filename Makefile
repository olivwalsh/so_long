RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[m"

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

SRC =	srcs/so_long.c \
		srcs/parse_map.c

OBJDIR = objs

INCDIR = inc

OBJ = $(addprefix ${OBJDIR}/,${SRC:.c=.o})

INC = -I./${INCDIR} -I./${INCDIR}/minilibx-linux

MLX = -L./${INCDIR}/minilibx-linux -lmlx

MLXLIBX = -lXext -lX11 -lm -lz 

LIBFT = -L./${INCDIR}/libft -lft

all: $(NAME) 

$(NAME): $(OBJ) libft minilibx
	$(CC) $(CFLAGS) $(INC) -O3 $(OBJ) -o $@ $(MLX) $(LIBFT) $(MLXLIBX)

${OBJDIR}/%.o : %.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(INC) -O3 -c $< -o $@

libft:
	@echo -n "Compiling libft"
	@make -s -C${INCDIR}/libft
	@echo ${GREEN}"\t\tOK"${RESET}

minilibx:
	@echo -n "Compiling minilibx"
	@make -s -C${INCDIR}/minilibx-linux > /dev/null 2>&1
	@echo ${GREEN}"\tOK"${RESET}

clean :
	rm -rf $(OBJDIR)
	@make clean -s -C${INCDIR}/libft
	@make clean -s -C${INCDIR}/minilibx-linux

fclean: clean
	rm -f $(NAME)
	@make fclean -s -C${INCDIR}/libft

re: fclean all

.PHONY: all clean fclean re bonus libft minilibx