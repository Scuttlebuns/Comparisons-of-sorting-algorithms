#Forces use of g++ 12 for compilation
CXX = g++-12 
#disables g++ and forces use of make, prompting error in main.cc
CXXFLAGS = -g -std=c++2a -DUSE_MAKEFILE
TARGET = a.out
SOURCES = main.cc

#compilation targets
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

#removed .o files after making as well as when using make clean scraps a.out
clean:
	rm -f $(TARGET) core *.o

.PHONY: clean
