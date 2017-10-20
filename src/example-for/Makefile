CC=gcc-4.8
CXX=g++-4.8

all: main

main: for-constructor png pdf
	@echo "Ver os arquivos .omplower e .ompexp"

for-constructor:
	# static
	${CC} -fopenmp -fdump-tree-ompexp example-for-constructor-static.c -o example-for-constructor-static.exe
	${CC} -fopenmp -fdump-tree-ompexp-graph example-for-constructor-static.c
	
	# -fno-asynchronous-unwind-tables retira Call Frame Information .cfi_startproc, .cfi_endproc
	${CC} -fopenmp example-for-constructor-static.c -fno-asynchronous-unwind-tables -S -o example-for-constructor-static.s

	# static with chunk.
	${CC} -fopenmp -fdump-tree-ompexp example-for-constructor-static-with-chunk.c -o example-for-constructor-static-with-chunk.exe
	${CC} -fopenmp -fdump-tree-ompexp-graph example-for-constructor-static-with-chunk.c
	
	# -fno-asynchronous-unwind-tables retira Call Frame Information .cfi_startproc, .cfi_endproc
	${CC} -fopenmp example-for-constructor-static-with-chunk.c -fno-asynchronous-unwind-tables -S -o example-for-constructor-static-with-chunk.s

	# dynamic.
	${CC} -fopenmp -fdump-tree-ompexp example-for-constructor-dynamic.c -o example-for-constructor-dynamic.exe
	${CC} -fopenmp -fdump-tree-ompexp-graph example-for-constructor-dynamic.c
	
	# -fno-asynchronous-unwind-tables retira Call Frame Information .cfi_startproc, .cfi_endproc
	${CC} -fopenmp example-for-constructor-dynamic.c -fno-asynchronous-unwind-tables -S -o example-for-constructor-dynamic.s

clean:
	find . -type f \( ! \( -iname "*.c" -or -iname "Makefile" -or -iname "*.ompexp" -or -iname "dump2dot" -or -iname "*.sh" \) \) -delete

png:
	../scripts/gen-png.sh

pdf:
	../scripts/gen-pdf.sh