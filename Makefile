CXX = g++-12
CXXFLAGS = -g -std=c++2a -DUSE_MAKEFILE
TARGET = a.out
SOURCES = main.cc

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET) core *.o

.PHONY: clean
