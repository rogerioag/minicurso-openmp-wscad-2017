CC=gcc-4.8
CXX=g++-4.8
LIB_HOOKOMP_PATH=$(PWD)

all: clean info libhookomp

# Step 1: Compiling with Position Independent Code
hookomp.o: hookomp.c
	${CXX} $(OPTIONS) -c -Werror -fpic hookomp.c 
	# ${CXX} $(OPTIONS) -c -Werror -Wno-write-strings -fpic prepostfunctions.c

# Step 2: Creating a shared library from an object file
libhookomp: hookomp.o
	LD_LIBRARY_PATH=$(PWD):$(LD_LIBRARY_PATH) export LD_LIBRARY_PATH
	${CXX} -L ${LIB_HOOKOMP_PATH} -shared hookomp.o -ldl -o libhookomp.so

# Step 3: Linking with a shared library
# As you can see, that was actually pretty easy. We have a shared library. 
# Let’s compile our main.c and link it with libfoo. We’ll call our final program “test.” 
# Note that the -lfoo option is not looking for foo.o, but libfoo.so. GCC assumes that all 
# libraries start with ‘lib’ and end with .so or .a (.so is for shared object or shared 
# libraries, and .a is for archive, or statically linked libraries).

clean:
	rm -rf *.o main-test *.so 

info:
	@echo "Use make OPTIONS=\"-DVERBOSE -DDEBUG\" to compile with messages."
