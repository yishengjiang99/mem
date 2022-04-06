all: bin test

clean:
	rm -f bin/*

bin: clean
	gcc src/mem_test.c src/mem.c -o bin/unit_test && \
	gcc src/grepsort.c src/mem.c src/sort.c -o bin/grepsort

test: bin
	echo "abc\n123\nefc\n123\n123\n345\n566\0aaaafff" | bin/grepsort > res.txt && \
	ls -l | bin/grepsort >>  res.txt && \
	cat Makefile |bin/grepsort >>  res.txt

unit_test: bin
	echo "abcde\n" | bin/unit_test 5 && \
	echo "12345\n" | bin/unit_test 5