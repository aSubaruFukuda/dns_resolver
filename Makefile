PROGRAM = dnsres
OBJS    = dnsres.o
SRCS    = $(OBJS:%.o=%.c)
CC      = gcc
CFLAGS  = -g -Wall
LDFLAGS  =

$(PROGRAM):$(OBJS)
	$(CC) $(CFLAGS) $(LDLIBS) -o $(PROGRAM) $(OBJS) $(LDLIBS)

clean:
	rm *.o $(PROGRAM)
