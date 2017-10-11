CC=gcc-4.8
CXX=g++-4.8
#LIB_HOOKOMP_PATH=$(PWD)/..
LIB_HOOKOMP_PATH=/dados/Dropbox/doutorado/producao/publications/minicurso-erad-sp-2016/src/simple-omp-hook

all: clean main

main: 
	LD_LIBRARY_PATH=$(PWD):$(LD_LIBRARY_PATH) export LD_LIBRARY_PATH
	cp ../libhookomp.so .
	
	# ${CXX} -L ${LIB_HOOKOMP_PATH} parallel-region-with-multiple-loops.c -o parallel-region-with-multiple-loops.exe -lhookomp -fopenmp -lgomp

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c prepostfunctions.c

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c parallel-region-with-multiple-loops.c -lhookomp -fopenmp
	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -fdump-tree-ompexp parallel-region-with-multiple-loops.c -fopenmp

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} parallel-region-with-multiple-loops.o prepostfunctions.o -o parallel-region-with-multiple-loops.exe -lhookomp -fopenmp
	
	@echo "*****Use: LD_PRELOAD=./libhookomp.so ./vectoradd-omp-for-runtime-offloading-gpu-without-hook.exe"
	
clean:
	rm -rf *.o *.so *.exe

