CC = gcc
<<<<<<< HEAD
CFLAGS = -O3 -Wall -Werror -fPIC //O3 compile with the highest level of optimization, fpic (essential for shared libs)
LDFLAGS = -shared -lm //create shared obj

all: libkernel.so //will build into libkernel.so, create shared obj 

libkernel.so: kernel.c //connects w kernel file
	$(CC) $(CFLAGS) kernel.c -o libkernel.so $(LDFLAGS)
=======
CFLAGS = -O3 -Wall -Werror -fPIC 
LDFLAGS = -shared -lm 

all: libkernel.so 

libkernel.so: kernel.c 
	$(CC) $(CFLAGS) $(LDFLAGS) -o libkernel.so kernel.c
>>>>>>> 8cbee78 (fire emoji)

clean:
	rm -f libkernel.so