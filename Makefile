CXX = g++
CXXFLAGS = -std=c++11 -O3
TARGET = simd_example

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)
