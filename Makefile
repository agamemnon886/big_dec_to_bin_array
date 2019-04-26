TARGET=dec_to_bin

all:
	gcc -Wall -fsanitize=address -pedantic -std=c99 -o $(TARGET) $(TARGET).c

clean:
	rm -f $(TARGET)
