RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[m"

NAME = so_long

CC = cc

MINILIBX = $(INCDIR)minilibx-linux/libmlx_Linux.a

CFLAGS = -Wall -Wextra -Werror

OBJDIR = objs/
SRCDIR = srcs/
INCDIR = inc/

# make TMEM=1 will compile with fsanitize flag
ifeq ($(TMEM), 1)
MEM = -fsanitize=address
endif

# make DEBUG will add -g flag
ifeq ($(DEBUG), 1)
CFLAGS += -g
endif

SRCS =	main.c \
		utils/get_next_line.c utils/get_next_line_utils.c \
		utils/ft_printf.c utils/ft_itoa.c utils/ft_putchar.c utils/ft_puthex.c utils/ft_putstr.c \
		parse_map.c parse_utils.c init_map.c \
		moves.c win_events.c so_long_utils.c

SRC = $(addprefix $(SRCDIR), $(SRCS))
OBJ = $(addprefix ${OBJDIR}, ${SRCS:.c=.o})

INC = -I./${INCDIR} -I./minilibx-linux

MLX = -L./${INCDIR}minilibx-linux -lmlx

MLXLIBX = -lXext -lX11 -lm -lz 

all: $(NAME) 

$(OBJDIR)%.o : $(SRCDIR)%.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(MEM) $(INC) -c $< -o $@

$(NAME): $(OBJ) $(MINILIBX)
	@echo -n "Compiling so_long"
	@$(CC) $(CFLAGS) $(MEM) $(INC) $(OBJ) $(MINILIBX) $(MLXLIBX) -o $@
	@echo ${GREEN}"\tOK"${RESET}

$(MINILIBX):
	@echo -n "Compiling minilibx"
	@make -s -C${INCDIR}minilibx-linux > /dev/null 2>&1
	@echo ${GREEN}"\tOK"${RESET}

clean :
	rm -rf $(OBJDIR)
	@make clean -s -C${INCDIR}/minilibx-linux

fclean: clean
	rm -f $(NAME)

re: fclean all
	make all

.PHONY: all clean fclean re bonus minilibx ft_printf