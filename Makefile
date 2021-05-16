NAME = libftprintf.a

SOURCE = srcs/ft_printf.c srcs/parse_int.c srcs/util_for_parse.c srcs/util_for_parse2.c srcs/util_for_list.c

LIBFT_SOURCE    = libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memccpy.c libft/ft_memmove.c libft/ft_strlen.c\
			libft/ft_memchr.c libft/ft_memcmp.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c\
			libft/ft_isprint.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c\
			libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_strnstr.c libft/ft_strdup.c libft/ft_calloc.c libft/ft_atoi.c\
			libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c\
			libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_lstnew.c\
			libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c libft/ft_lstadd_back.c\
			libft/ft_lstdelone.c libft/ft_lstclear.c libft/ft_lstiter.c libft/ft_lstmap.c

LIBFT_OBJ = ${LIBFT_SOURCE:.c=.o}

OBJ = $(patsubst %.c,%.o,$(SOURCE))

D_FILES = $(patsubst %.c,%.d,$(SOURCE))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make bonus -C libft
	ar rcs $(NAME) $?

%.o: %.c
	gcc $(FLAGS) -c $< -o $@ -MD

exec: $(OBJ) $(LIBFT_OBJ)
	gcc -g $(SOURCE) $(LIBFT_SOURCE) -o ft_printf.out

include $(wildcard $(D_FILES))

clean:
	@make clean -C libft
	@rm -f $(OBJ) $(D_FILES)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
