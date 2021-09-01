all: test

serv: 
	clang server.c -o serv && ./serv

client: 
	clang main.c -o test && ./test 32057  "porco velho" 