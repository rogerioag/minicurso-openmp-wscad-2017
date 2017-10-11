CC=gcc-4.8
CXX=g++-4.8

all: main

main: example-sections png pdf
	@echo "Ver os arquivos .omplower e .ompexp"

example-sections:
	${CC} -fopenmp -fdump-tree-ompexp example-sections.c -o example-sections.exe
	${CC} -fopenmp -fdump-tree-ompexp-graph example-sections.c
	
	# -fno-asynchronous-unwind-tables retira Call Frame Information .cfi_startproc, .cfi_endproc
	${CC} -fopenmp example-sections.c -fno-asynchronous-unwind-tables -S -o example-sections.s	

clean:
	find . -type f \( ! \( -iname "*.c" -or -iname "Makefile" -or -iname "*.ompexp" -or -iname "dump2dot" -or -iname "*.sh" \) \) -delete

png:
	../scripts/gen-png.sh

pdf:
	../scripts/gen-pdf.sh