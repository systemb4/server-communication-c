main:
	gcc server.c -o server
	gcc client.c -o client
clean:
	rm -f server
	rm -f client
