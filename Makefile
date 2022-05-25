NAME = so_long.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror 

SRC = so_long.c \
		parse_map.c \

OBJDIR = objs

OBJ = $(addprefix ${OBJDIR}/,${SRC:.c=.o})

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^

${OBJDIR}/%.o : %.c
	mkdir -p ${@D}
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus