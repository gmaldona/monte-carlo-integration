# Parallelized Numerical Integral Computation for Binghamton University CS 547.
# see: https://cs.binghamton.edu/~kchiu/cs447/assign/3/
#
# author: Gregory Maldonado
# email : gmaldonado@cs.binghamton.edu
# date  : 2024-04-30
# web   : https://cs.binghamton.edu/~gmaldonado/
#
# Graduate student @ Thomas J. Watson College of Engineering and Applied
# Sciences, Binghamton University.

CC     = g++
CFLAGS = -std=c++17 -Wall -Wextra -pedantic -g -O3
TARGET = integrate

.pre:
	mkdir -p build

all: $(TARGET)
	make .post
	$(RM) *.o

$(TARGET): $(TARGET).o
	$(CC) $(CFLAGS) -o build/$(TARGET) $(TARGET).cc -pthread -lstdc++

$(TARGET).o: .pre $(TARGET).cc $(TARGET).hh
	$(CC) $(CFLAGS) $(TARGET).cc -pthread -lstdc++

.post:
	chmod +x build/$(TARGET)

clean:
	$(RM) build/$(TARGET) *.out