NAME = libft.a
SRC = ft_atoi.c	ft_itoa.c	ft_putnbr_fd.c	ft_strlcpy.c	ft_tolower.c \
	ft_bzero.c	ft_memchr.c	ft_putstr_fd.c	ft_strlen.c	ft_toupper.c \
	ft_calloc.c	ft_memcmp.c	ft_split.c	ft_strmapi.c \
	ft_isalnum.c	ft_memcpy.c	ft_strchr.c	ft_strncmp.c \
	ft_isalpha.c	ft_memmove.c	ft_strdup.c	ft_strnstr.c \
	ft_isascii.c	ft_memset.c	ft_striteri.c	ft_strrchr.c \
	ft_isdigit.c	ft_putchar_fd.c	ft_strjoin.c	ft_strtrim.c \
	ft_isprint.c	ft_putendl_fd.c	ft_strlcat.c	ft_substr.c

BNSSRC = ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c \
	ft_lstdelone.c	ft_lstiter.c	ft_lstlast.c \
	ft_lstmap.c	ft_lstnew.c	ft_lstsize.c
OBJ = $(SRC:.c=.o)
BNSOBJ = $(BNSSRC:.c=.o)
HEADERS = libft.h
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc

all: $(NAME)

%.o: %.c
	cc $(FLAGS) -c -I$(HEADERS) $< -o $@

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus:	$(OBJ) $(BNSOBJ)
	$(AR) $(NAME) $(OBJ) $(BNSOBJ)

clean:
	$(RM) -f $(OBJ) $(BNSOBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
