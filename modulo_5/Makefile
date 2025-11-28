CXX = g++
CXXFLAGS = -std=c++17
TARGET = memoria_sim

# SystemC installed via Homebrew
SYSTEMC_INC = /opt/homebrew/include
SYSTEMC_LIB = /opt/homebrew/lib

INCDIR = -I $(SYSTEMC_INC)
LIBDIR = -L $(SYSTEMC_LIB)
LIBS = -lsystemc -lm

SRCS = memoria_tb.cpp

all:
	$(CXX) $(CXXFLAGS) $(SRCS) $(INCDIR) $(LIBDIR) $(LIBS) -o $(TARGET)

clean:
	rm -f $(TARGET) *.vcd

run: all
	./$(TARGET)
