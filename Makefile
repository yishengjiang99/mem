all: test_gsort

clean:
	rm -f build/*.o

build: clean
	gcc src/mem_test.c src/mem.c -o unit_test.o && \
	gcc src/grepsort.c src/mem.c src/sort.c -o grepsort.o

test_gsort: build
	echo "abc\n123\nefc\n123\n123\n345\n566\0aaaafff" |./grepsort.o > res.txt

unit_test: build
	echo "abcde\n" | ./memt.o 5
	echo "12345\n" | ./memt.o 4