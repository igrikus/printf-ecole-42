NAME = libftprintf.a

SOURCE = srcs\ft_printf.c srcs\parse_int.c srcs\util_for_parse.c srcs\util_for_parse2.c

OBJ = $(patsubst %.c,%.o,$(SOURCE))

D_FILES = $(patsubst %.c,%.d,$(SOURCE))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	ar rcs $(NAME) $?

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -MD

include $(wildcard $(D_FILES))

clean:
#	@make clean -C libft
	@rm -f $(OBJ) $(D_FILES)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
