test:
	g++ -v
	g++ test.cpp -std=c++11 -O3
	gdb -batch -ex 'disas main' a.out
