#CC=/home/rogerio/gcc-6.2.0/bin/gcc -I /home/rogerio/gcc-6.2.0/include -L /home/rogerio/gcc-6.2.0/lib -L /home/rogerio/gcc-6.2.0/lib64
#CXX=/home/rogerio/gcc-6.2.0/bin/g++ -I /home/rogerio/gcc-6.2.0/include -L /home/rogerio/gcc-6.2.0/lib -L /home/rogerio/gcc-6.2.0/lib64

#CC=${HOME}/offload/wrk/install/bin/gcc -I ${HOME}/offload/wrk/install/include -L ${HOME}/offload/wrk/install/lib -L ${HOME}/offload/wrk/install/lib64 -L ${HOME}/offload/wrk/install/nvptx-none/lib
#CXX=${HOME}/offload/wrk/install/bin/g++ -I ${HOME}/offload/wrk/install/include -L ${HOME}/offload/wrk/install/lib -L ${HOME}/offload/wrk/install/lib64 -L ${HOME}/offload/wrk/install/nvptx-none/lib

CC=${HOME}/offload/wrk/install/bin/x86_64-pc-linux-gnu-gcc
CXX=${HOME}/offload/wrk/install/bin/x86_64-pc-linux-gnu-g++

# /home/rogerio/offload/wrk/install/bin/x86_64-pc-linux-gnu-gcc -v -fopenmp -foffload=nvptx-none example-target.c -o example-target.exe

all:	example-target ompexp-example-target ompexp-graph-example-target

example-target:	example-target.c
	${CC} -fopenmp -foffload=nvptx-none="-v" example-target.c -o example-target.exe
	${CC} -fopenmp -foffload=nvptx-none example-target.c -S -o example-target.S
	#${CC} -fopenacc example-target.c -o example-target-acc.exe
	
ompexp-example-target:
	# Generate the expanded OpenMP code.
	${CC} -fopenmp -foffload=nvptx-none -fdump-tree-all example-target.c -o example-target.exe
	#${CC} -fopenacc -fdump-tree-all example-target.c -o example-target.exe
	
ompexp-graph-example-target:
	# Generate the graph of expanded OpenMP code.
	${CC} -fopenmp -foffload=nvptx-none -fdump-tree-all-graph example-target.c -o example-target.exe
	#${CC}  -fopenacc -fdump-tree-all-graph example-target.c -o example-target.exe
	
	../scripts/gen-png.sh
	../scripts/gen-pdf.sh

clean:
	rm *.o *.exe
