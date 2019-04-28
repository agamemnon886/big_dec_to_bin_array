TARGET1=dec_to_bin
TARGET2=hex_to_bin

all:
	gcc -Wall -g -fsanitize=address -pedantic -std=c99 -o $(TARGET1) $(TARGET1).c
	gcc -Wall -g -fsanitize=address -pedantic -std=c99 -o $(TARGET2) $(TARGET2).c

clean:
	rm -f $(TARGET1)
	rm -f $(TARGET2)
