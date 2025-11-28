CXX = g++
TARGET = logic_gates
SYSTEMC_HOME = /usr/local/systemc

INCDIR = -I $(SYSTEMC_HOME)/include
LIBDIR = -L $(SYSTEMC_HOME)/lib-linux
LIBS = -lsystemc -lm

SRCS = main.cpp

all:
	$(CXX) $(SRCS) $(INCDIR) $(LIBDIR) $(LIBS) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)