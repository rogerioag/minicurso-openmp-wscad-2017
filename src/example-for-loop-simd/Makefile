CC=/home/rogerio/gcc-6.2.0/bin/gcc -I /home/rogerio/gcc-6.2.0/include -L /home/rogerio/gcc-6.2.0/lib -L /home/rogerio/gcc-6.2.0/lib64
CXX=/home/rogerio/gcc-6.2.0/bin/g++ -I /home/rogerio/gcc-6.2.0/include -L /home/rogerio/gcc-6.2.0/lib -L /home/rogerio/gcc-6.2.0/lib64

all: main

main: example-for-loop-simd png pdf
	@echo "Ver os arquivos .omplower e .ompexp"

example-for-loop-simd:
	${CC} -fopenmp -fdump-tree-ompexp example-for-loop-simd.c -o example-for-loop-simd.exe -O0
	${CC} -fopenmp -fdump-tree-ompexp-graph example-for-loop-simd.c -O0
	
	# -fno-asynchronous-unwind-tables retira Call Frame Information .cfi_startproc, .cfi_endproc
	${CC} -fopenmp example-for-loop-simd.c -fno-asynchronous-unwind-tables -S -o example-for-loop-simd.s	

clean:
	find . -type f \( ! \( -iname "*.c" -or -iname "Makefile" -or -iname "*.ompexp" -or -iname "dump2dot" -or -iname "*.sh" \) \) -delete

png:
	# ../scripts/gen-png.sh

pdf:
	../scripts/gen-pdf.sh
