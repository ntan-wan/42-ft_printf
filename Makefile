NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER_PATH = includes/

SRCS_PATH = srcs/

OBJS_PATH = $(SRCS_PATH)objs/

SRCS = ft_printf.c \
	fmt_init.c \
	fmt_update.c \
	fmt_operation.c \
	fmt_update_flags.c \
	print_c.c \
	print_s.c \
	print_ptr.c \
	print_decimal.c \
	print_hexa.c \
	print_unsi.c \
	print_percent.c \
	print_space.c \

OBJS = $(patsubst %.c, %.o, $(SRCS))

SRCS_PREFIXED = $(addprefix $(SRCS_PATH), $(SRCS))

OBJS_PREFIXED = $(addprefix $(OBJS_PATH), $(OBJS))

LIBFT_DIR = libft/

LIBFT_OBJS = $(LIBFT_DIR)objs/*.o

LIB = libft.a

all : $(NAME)

$(NAME) : $(LIB) $(OBJS_PREFIXED)
	@ar rcs $(NAME) $(OBJS_PREFIXED) $(LIBFT_OBJS)
	@echo "\033[32mlibftprintf.a Done!"

$(LIB) :
	@make bonus -C $(LIBFT_DIR)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c -I$(HEADER_PATH) $< -o $@

bonus : $(NAME)

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
