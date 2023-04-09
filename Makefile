NAME = ft_printf.a
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
HEADERS = ../
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc

all: $(NAME)

%.o: %.c $(HEADERS)
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