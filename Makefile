NAME		=	libft.a

CC			=	cc

CFLAGS		=	-c -Wall -Wextra -Werror

SRCS 		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strdup.c \
				ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c


BONUS_SRCS	=	ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstsize_bonus.c \
				ft_lstadd_front_bonus.c ft_lstdelone_bonus.c \
				ft_lstlast_bonus.c ft_lstmap_bonus.c \
				ft_lstiter_bonus.c ft_lstnew_bonus.c \

HEADER		=	libft.h

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

BONUS_OBJS	=	$(patsubst %.c,%.o,$(BONUS_SRCS))

all: $(SRCS) $(NAME)

bonus: $(BONUS_OBJS)
	ar rc $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(HEADER) $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re