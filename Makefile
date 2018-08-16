all:
	g++ -c memtrace.cpp -o memtrace.o -g -DMEMTRACE -Wall -Wextra
	g++ dstring.cpp -c -g -Wall -Wextra -Werror -pedantic -DMEMTRACE
	g++ dstring_main.cpp dstring.o memtrace.o -o test.exe -g -Wall -Wextra -Werror -pedantic -DMEMTRACE