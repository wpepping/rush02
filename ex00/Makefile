NAME = rush-02

SRCS = main.c err0r_handling.c parse_number.c parse_number2.c parse_part.c read_dict.c search_dict.c strecat.c string_functions.c read_dict2.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	cc -o $(NAME) $(OBJS) $(CFLAGS)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
