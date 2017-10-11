CC=gcc-4.8
CXX=g++-4.8
#LIB_HOOKOMP_PATH=$(PWD)/..
LIB_HOOKOMP_PATH=/dados/Dropbox/doutorado/producao/publications/minicurso-openmp-wscad-2017/mc-openmp-wscad-2017-texto/src/simple-omp-hook

all: clean main

main: 
	LD_LIBRARY_PATH=$(PWD):$(LD_LIBRARY_PATH) export LD_LIBRARY_PATH
	cp ${LIB_HOOKOMP_PATH}/libhookomp.so .
	
	# ${CXX} -L ${LIB_HOOKOMP_PATH} parallel-region-with-tasks.c -o parallel-region-with-tasks.exe -lhookomp -fopenmp -lgomp

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c prepostfunctions.c

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -c parallel-region-with-tasks.c -lhookomp -fopenmp
	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} -fdump-tree-ompexp parallel-region-with-tasks.c -fopenmp

	${CC} -I ${LIB_HOOKOMP_PATH} -L ${LIB_HOOKOMP_PATH} parallel-region-with-tasks.o prepostfunctions.o -o parallel-region-with-tasks.exe -lhookomp -fopenmp
	
	@echo "*****Use: LD_PRELOAD=./libhookomp.so ./parallel-region-with-tasks.exe"
	
clean:
	rm -rf *.o *.so *.exe

