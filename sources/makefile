TARGET=DNA_ANALAYZER
SOURCES=$(wildcard *.cpp)
OBJS=$(SOURCES:.cpp=.o)

CC=g++
CFLAGS= -c -pedantic -Wall -Wconversion  -g
CXXFLAGS=$(CFLAGS)
LDFLAGS= -g

.PHONY: clean run gdb
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)


clean:
	rm -f $(OBJS) $(TARGET) .depends
run:$(TARGET)
	./$(TARGET)

gdb: $(TARGET)
	gdb -q ./$(TARGET)
