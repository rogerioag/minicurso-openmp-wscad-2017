CC=gcc-4.8
CXX=g++-4.8

all: main

main: example-sections-reduction png pdf
	@echo "Ver os arquivos .omplower e .ompexp"

example-sections-reduction:
	${CC} -fopenmp -fdump-tree-ompexp example-sections-reduction.c -o example-sections-reduction.exe
	${CC} -fopenmp -fdump-tree-ompexp-graph example-sections-reduction.c
	
	# -fno-asynchronous-unwind-tables retira Call Frame Information .cfi_startproc, .cfi_endproc
	${CC} -fopenmp example-sections-reduction.c -fno-asynchronous-unwind-tables -S -o example-sections-reduction.s	

clean:
	find . -type f \( ! \( -iname "*.c" -or -iname "Makefile" -or -iname "*.ompexp" -or -iname "dump2dot" -or -iname "*.sh" \) \) -delete

png:
	../scripts/gen-png.sh

pdf:
	../scripts/gen-pdf.sh