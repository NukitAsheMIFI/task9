CXX = g++
CXXFLAGS = -Wall -Wextra  
TARGET = task9
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
$(TARGET): $(OBJS)
	$(CXX) $(CFLAGS) -o $(TARGET) $(OBJS)
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) 
