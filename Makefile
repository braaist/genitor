all:
	g++ genitor.cpp matrix_funcs.cpp -O0 -g -fsanitize=address -pedantic-errors -lm -o genitor
