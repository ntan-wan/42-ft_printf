NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER_PATH = includes/

SRCS_PATH = srcs/

OBJS_PATH = $(SRCS_PATH)objs/

SRCS = ft_printf.c \
	is_format_specifier.c \

OBJS = $(patsubst %.c, %.o, $(SRCS))

SRCS_PREFIXED = $(addprefix $(SRCS_PATH), $(SRCS))

OBJS_PREFIXED = $(addprefix $(OBJS_PATH), $(OBJS))

LIBFT_DIR = libft

LIB = libft.a

all : $(NAME)

$(NAME) : $(LIB) $(OBJS_PREFIXED)

$(LIB) :
	@make -C $(LIBFT_DIR)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c -I$(HEADER_PATH) $< -o $@

clean :
	@rm -rf $(OBJS_PATH)
	@echo "\033[31mremoved: obj files (libftprintft.a)"

fclean : clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "removed: libftprintf.a"
	@echo "\033[32mcleaning all done!"

re : fclean all

test :
	$(CC) $(CCFLAGS) main.c $(NAME)
