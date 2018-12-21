files: compile

SRCS= srcs/C/banque.c

OBJ= banque.o

NAME= banque

compile:
	gcc -c $(SRCS)
	gcc $(OBJ) -o $(NAME)
	./$(NAME)

clear:
	rm $(OBJ) $(NAME)

re: clean compile
