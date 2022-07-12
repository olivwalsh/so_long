RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[m"

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror 

# make TMEM=1 will compile with fsanitize flag
ifeq ($(TMEM), 1)
MEM = -fsanitize=address
endif

# make DEBUG will add -g flag
ifeq ($(DEBUG), 1)
CFLAGS += -g
endif

SRC =	srcs/main.c \
		srcs/utils/get_next_line.c srcs/utils/get_next_line_utils.c \
		srcs/utils/ft_printf.c srcs/utils/ft_itoa.c srcs/utils/ft_putchar.c srcs/utils/ft_puthex.c srcs/utils/ft_putstr.c \
		srcs/parse_map.c \
		srcs/parse_utils.c \
		srcs/init_map.c \
		srcs/moves.c \
		srcs/win_events.c  \
		srcs/so_long_utils.c

OBJDIR = objs

INCDIR = inc

OBJ = $(addprefix ${OBJDIR}/,${SRC:.c=.o})

INC = -I./${INCDIR} -I./minilibx-linux

MLX = -L./${INCDIR}/minilibx-linux -lmlx

MLXLIBX = -lXext -lX11 -lm -lz 

all: $(NAME) 

$(NAME): $(OBJ) minilibx
	$(CC) $(CFLAGS) $(MEM) $(INC) $(OBJ) $(MLX) $(MLXLIBX) -o $@

${OBJDIR}/%.o : %.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(MEM) $(INC) -c $< -o $@

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

.PHONY: all clean fclean re bonus minilibx ft_printf