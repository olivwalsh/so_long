RED = "\033[1;31m"
GREEN = "\033[1;32m"
RESET = "\033[m"

NAME 		= so_long
BONUS 		= so_long_bonus
MINILIBX 	= $(INCDIR)minilibx-linux/libmlx_Linux.a

CC 			= cc
CFLAGS		= -Wall -Wextra -Werror

OBJDIR 		= objs/
SRCDIR		= srcs/
INCDIR		= inc/
BONUS_DIR	= $(SRCDIR)bonus/

SRCS		= utils/get_next_line.c utils/get_next_line_utils.c utils/ft_itoa.c \
			  main.c parse.c init.c display.c moves.c utils.c exit.c
BONUS_SRCS 	= $(SRCS:.c=_bonus.c)

OBJ 		= $(addprefix ${OBJDIR}, ${SRCS:.c=.o})
BONUS_OBJ 	= $(addprefix ${OBJDIR}, ${BONUS_SRCS:.c=.o})

INC 		= -I./${INCDIR} -I./minilibx-linux
MLX 		= -L./${INCDIR}minilibx-linux -lmlx
MLXLIBX 	= -lXext -lX11 -lm -lz 

all: $(NAME) 

bonus: ${BONUS}

$(OBJDIR)%.o : $(SRCDIR)%.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(MEM) $(INC) -c $< -o $@

$(OBJDIR)%.o : $(BONUS_DIR)%.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) $(MEM) $(INC) -c $< -o $@

$(NAME) : $(OBJ) $(MINILIBX)
	@echo -n "Compiling so_long"
	@$(CC) $(CFLAGS) $(MEM) $(INC) $(OBJ) $(MINILIBX) $(MLXLIBX) -o $@
	@echo ${GREEN}"\t\tOK"${RESET}

${BONUS} : $(BONUS_OBJ) $(MINILIBX)
	@echo -n "Compiling so_long -- BONUS"
	@$(CC) $(CFLAGS) $(MEM) $(INC) $(BONUS_OBJ) $(MINILIBX) $(MLXLIBX) -o $@
	@echo ${GREEN}"\tOK"${RESET}

$(MINILIBX) :
	@echo -n "Compiling minilibx"
	@make -s -C${INCDIR}minilibx-linux > /dev/null 2>&1
	@echo ${GREEN}"\t\tOK"${RESET}

clean :
	rm -rf $(OBJDIR)
	@make clean -s -C${INCDIR}/minilibx-linux

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all
	make all

.PHONY: all clean fclean re bonus