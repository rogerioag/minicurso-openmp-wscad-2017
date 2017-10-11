#CC=/home/rogerio/gcc-6.2.0/bin/gcc -I /home/rogerio/gcc-6.2.0/include -L /home/rogerio/gcc-6.2.0/lib -L /home/rogerio/gcc-6.2.0/lib64
#CXX=/home/rogerio/gcc-6.2.0/bin/g++ -I /home/rogerio/gcc-6.2.0/include -L /home/rogerio/gcc-6.2.0/lib -L /home/rogerio/gcc-6.2.0/lib64

CC=gcc-4.9
CXX=gcc-4.9

all: main

main: example-simd png pdf
	@echo "Ver os arquivos .omplower e .ompexp"

example-simd:
	${CC} -fopenmp -fdump-tree-all example-simd.c -o example-simd.exe
	${CC} -fopenmp -fdump-tree-all-graph example-simd.c
	
	# -fno-asynchronous-unwind-tables retira Call Frame Information .cfi_startproc, .cfi_endproc
	${CC} -fopenmp example-simd.c -fno-asynchronous-unwind-tables -S -o example-simd.s	

clean:
	find . -type f \( ! \( -iname "*.c" -or -iname "Makefile" -or -iname "*.ompexp" -or -iname "dump2dot" -or -iname "*.sh" \) \) -delete

png:
	# ../scripts/gen-png.sh

pdf:
	../scripts/gen-pdf.sh
