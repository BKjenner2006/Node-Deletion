CC = g++

delNode.exe : delNode.o
	$(CC) -o delNode.exe delNode.o

delNode.o : delNode.cc
	$(CC) -c delNode.cc

clean:
	rm *.o  *.exe
