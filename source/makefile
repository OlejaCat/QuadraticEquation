CC=gcc

CFLAGS=-c -lm
FLAGS=-lm

all: base

base: main.o helpful_functions.o solve_quadratic.o unit_test.o user_interaction.o user_interface.o
	@$(CC) $(FLAGS) main.o helpful_functions.o solve_quadratic.o unit_test.o user_interaction.o user_interface.o -o solve

main.o: main.c
	@$(CC) $(CFLAGS) main.c

helpful_functions.o: helpful_functions.c
	@$(CC) $(CFLAGS) helpful_functions.c

solve_quadratic.o: solve_quadratic.c
	@$(CC) $(CFLAGS) solve_quadratic.c

unit_test.o: unit_test.c
	@$(CC) $(CFLAGS) unit_test.c

user_interaction.o: user_interaction.c
	@$(CC) $(CFLAGS) user_interaction.c

user_interface.o: user_interface.c
	@$(CC) $(CFLAGS) user_interface.c

clean:
	@rm -rf *.o solve
