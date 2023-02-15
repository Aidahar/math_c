CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
GCOV=-fprofile-arcs -ftest-coverage -fPIC
OS=$(shell uname)
ifeq (${OS}, Linux)
      TEST_FLAGS = -lcheck -pthread -lrt -lm -L. -ls21_math
else
      TEST_FLAGS =-lcheck
endif

all: s21_math.a

gcov_report: test
	gcov *.gcda
	gcovr --html-details -o report.html

test: s21_math.a
	gcc test.c -c
	$(CC) $(CFLAGS) $(TEST_FLAGS) ${GCOV} s21_math.a s21_math.c test.o -o test
	./test	

s21_math.a: s21_math.o
ifeq (${OS}, Linux)
	ar rc libs21_math.a *.o
	ranlib libs21_math.a
	cp libs21_math.a s21_math.a
	cp libs21_math.a ls21_math.a
else
	ar rc s21_math.a *.o
	ranlib s21_math.a
endif

s21_math.o: s21_math.c
	${CC} ${CFLAGS} -c s21_math.c

.PHONY: all clean rebuild

rebuild: clean s21_math.a

rebuild_test: clean test

clean:
	rm -rf *.o *.gch *.dSYM *.gcov *.gcda *.gcno *.a test *.css *.html
