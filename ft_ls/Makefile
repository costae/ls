NAME	= ft_ls

CC = gcc

SRC = main.c find.c func1.c free.c func2.c func3.c func4.c func5.c func6.c func7.c func8.c func9.c rec.c print1.c print2.c print3.c show.c

LIB = printfcic/libftprintf.a

OBJ = main.o find.o func1.o free.o func2.o func3.o func4.o func5.o func6.o func7.o func8.o func9.o rec.o print1.o print2.o print3.o show.o	

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
		$(CC) $(CFLAGS) $(SRC) -c $? $(SRC)
		$(CC) $(OBJ) $(LIB) -o $(NAME)

clean: 
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME) $(OBJ)

re: fclean all

.PHONY: clean
