CXX = g++
CXXFLAGS = -std=c++11 -O3
TARGET = simd_example

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) main.cpp

run:
	./$(TARGET)

# Generate assembly code with comments
asm:
	$(CXX) $(CXXFLAGS) -S -fverbose-asm -o main.s main.cpp

clean:
	rm -f $(TARGET) main.s
