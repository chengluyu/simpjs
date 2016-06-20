CC = clang++
FLAGS = --std=c++11
OUTPUT_EXEC = test.out
OBJECTS = token.o main.o

token:
	$(CC) $(FLAGS) -c "../../src/token.cc" -o token.o

main:
	$(CC) $(FLAGS) -c test.cc -o main.o

clean_obj:
	rm *.o
	rm *.out

compile: token main
	$(CC) $(OBJECTS) -o $(OUTPUT_EXEC)

run_test: compile
	./test.out

test: run_test clean_obj

.PHONY: clean_obj compile run_test test