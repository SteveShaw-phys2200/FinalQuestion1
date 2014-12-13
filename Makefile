
GRAPH = gnuplot

CC = gcc
CFLAGS = -Wall -O3 
LFLAGS = -O3
LIBS = -lgsl -lm -lgslcblas

all: mc-se.png

mc-se: main.o mc_se.o
	${CC} $(LFLAGS) -o $@ $^ $(LIBS)

res: mc-se
	./mc-se > res

mc-se.png: me-se.gpl res
	$(GRAPH) me-se.gpl


clean:
	rm -f *.o *~ mc-se res

veryclean: clean
	rm -f mc-se.png 
