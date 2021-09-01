all: test

serv: 
	clang -fsanitize=address server.c -o serv && ./serv

client:
	clang main.c -o test && ./test 6445 😇 