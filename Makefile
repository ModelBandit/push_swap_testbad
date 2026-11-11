NAME = push_swap
ARCHIVE = push_swap.a
LIBFTDIR = libft/
LIBFTC = ft_atoi.c ft_isdigit.c ft_memset.c ft_strnstr.c ft_bzero.c \
ft_isprint.c ft_strchr.c ft_strrchr.c ft_calloc.c ft_memchr.c \
ft_strlcat.c ft_tolower.c ft_isalnum.c ft_memcmp.c ft_strlcpy.c \
ft_toupper.c ft_isalpha.c ft_memcpy.c ft_strlen.c ft_isascii.c \
ft_memmove.c ft_strncmp.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

LIBFT = $(addprefix $(LIBFTDIR), $(LIBFTC))

PUSHSWAP = other_lib/my_list.c\
util.c

OBJECT = $(PUSHSWAP:.c=.o)
ALL_OBJECT = $(LIBFT:.c=.o) $(PUSHSWAP:.c=.o) 

CC = cc
WARN = -Wall -Wextra -Werror

all: $(ARCHIVE) $(NAME)

visual: $(ARCHIVE)
	$(CC) $(WARN) UI_main.c $(PUSHSWAP) $(ARCHIVE) visualize.out

$(NAME):
	$(CC) $(WARN) main.c $(PUSHSWAP) $(ARCHIVE) -o $(NAME)

$(ARCHIVE): $(OBJECT)
	$(MAKE) -C $(LIBFTDIR) libft.a
	ar rcs $(ARCHIVE) $(ALL_OBJECT)
	
%.o: %.c my_std.h my_list.h
	$(CC) $(WARN) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFTDIR) clean
	rm -f $(OBJECT)

fclean: clean
	$(MAKE) -C $(LIBFTDIR) fclean
	rm -f $(ARCHIVE)
	rm -f a.out


re: fclean all
	$(MAKE) -C $(LIBFTDIR) re
.PHONY: all clean fclean re visual