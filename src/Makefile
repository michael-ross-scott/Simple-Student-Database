CC=g++
EX=-std=c++11
OBJECTS=Database.o main.o
TARGET=main

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(EX)

%.o: %.cpp
	$(CC) -c $<
	
clean:
	$(RM) main *.o *.~
