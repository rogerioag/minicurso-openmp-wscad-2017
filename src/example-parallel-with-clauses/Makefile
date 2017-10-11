GCC := gcc-4.8

all:	omp-parallel-with-clauses ompexp-parallel-with-clauses ompexp-graph-parallel-with-clauses

omp-parallel-with-clauses:	example-parallel-with-clauses.c
	${GCC} -fopenmp example-parallel-with-clauses.c -o example-parallel-with-clauses.exe
	
ompexp-parallel-with-clauses:
	# Generate the expanded OpenMP code.
	${GCC} -fopenmp -fdump-tree-ompexp example-parallel-with-clauses.c -o example-parallel-with-clauses.exe
	
ompexp-graph-parallel-with-clauses:
	# Generate the graph of expanded OpenMP code.
	${GCC} -fopenmp -fdump-tree-ompexp-graph example-parallel-with-clauses.c -o example-parallel-with-clauses.exe
	
	../scripts/gen-png.sh
	../scripts/gen-pdf.sh

clean:
	rm *.o *.exe
