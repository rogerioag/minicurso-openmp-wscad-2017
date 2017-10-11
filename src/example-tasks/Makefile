CC=gcc-4.8
CXX=gcc-4.8

all: main

main: example-tasks png pdf
	@echo "Ver os arquivos .omplower e .ompexp"

example-tasks:
	${CC} -fopenmp -fdump-tree-ompexp example-tasks.c -o example-tasks.exe
	${CC} -fopenmp -fdump-tree-ompexp-graph example-tasks.c
	
	# -fno-asynchronous-unwind-tables retira Call Frame Information .cfi_startproc, .cfi_endproc
	${CC} -fopenmp example-tasks.c -fno-asynchronous-unwind-tables -S -o example-tasks.s	

clean:
	find . -type f \( ! \( -iname "*.c" -or -iname "Makefile" -or -iname "*.ompexp" -or -iname "dump2dot" -or -iname "*.sh" \) \) -delete

png:
	../scripts/gen-png.sh

pdf:
	../scripts/gen-pdf.sh