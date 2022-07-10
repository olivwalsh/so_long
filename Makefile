RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[m"

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRC =	srcs/main.c \
		srcs/parse_map.c \
		srcs/parse_utils.c \
		srcs/init_map.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/moves.c \
		srcs/win_events.c 

OBJDIR = objs

INCDIR = inc

OBJ = $(addprefix ${OBJDIR}/,${SRC:.c=.o})

INC = -I./${INCDIR} -I./minilibx-linux

MLX = -L./${INCDIR}/minilibx-linux -lmlx

MLXLIBX = -lXext -lX11 -lm -lz 

all: $(NAME) 

$(NAME): $(OBJ) minilibx
	$(CC) $(CFLAGS) $(INC) $(OBJ) $(MLX) $(MLXLIBX) -o $@

${OBJDIR}/%.o : %.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

minilibx:
	@echo -n "Compiling minilibx"
	@make -s -C${INCDIR}/minilibx-linux > /dev/null 2>&1
	@echo ${GREEN}"\tOK"${RESET}

clean :
	rm -rf $(OBJDIR)
	@make clean -s -C${INCDIR}/minilibx-linux

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus minilibx