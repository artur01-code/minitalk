LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c\
		case_pro.c\
		case_u.c\
		case_xup.c\
		case_c.c\
		case_p.c\
		case_s.c\
		case_x.c\
		case_d.c\
		ft_unsigneditoa.c\
		hex.c

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp $(LIBFT) $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft 
	rm -f $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all