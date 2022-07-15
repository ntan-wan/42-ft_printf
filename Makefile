NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER_PATH = includes/

SRCS_PATH = srcs/

OBJS_PATH = $(SRCS_PATH)objs/

SRCS = ft_printf.c \
	flag_check_bonus.c \
	fmt_init.c \
	fmt_reset.c \
	fmt_update.c \
	fmt_update_bonus.c \
	fmt_operation.c \
	print_c.c \
	print_s.c \
	print_ptr.c \
	print_decimal.c \
	print_hexa_lower.c \
	print_hexa_upper.c \
	print_unsi.c \
	print_percent.c \
	ft_putnbr_base.c \
	check_flags.c 

OBJS = $(patsubst %.c, %.o, $(SRCS))

SRCS_PREFIXED = $(addprefix $(SRCS_PATH), $(SRCS))

OBJS_PREFIXED = $(addprefix $(OBJS_PATH), $(OBJS))

LIBFT_DIR = libft

LIB = libft.a

all : $(NAME)

$(NAME) : $(LIB) $(OBJS_PREFIXED)
	@ar rcs $(NAME) $(OBJS_PREFIXED)
	@echo "\033[32mlibftprintf.a created!"

$(LIB) :
	@make bonus -C $(LIBFT_DIR)

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
	$(CC) $(CCFLAGS) main.c $(NAME) ./libft/libft.a
