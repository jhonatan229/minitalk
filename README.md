# minitalk
This project is my first contact with signals and manipulating bit by bit. The objective of this project is send a message(String) from the X process(client) to process(server), with support of the [signals](https://man7.org/linux/man-pages/man7/signal.7.html).

## How works?!
After compile the project with make, is created two executable, the server and client. When you run the server, it print in the terminal the ID of the process, and waits for a signal in a infinite loop.  
With this PID (ID Process), we run the client passing the PID and the message that you want to send:  


```c
./client [PID] [MESSAGE]
```
The client will send a signal with the function **(kill)** with the bit of the character of the message, so it will send a signal bit by bit, if the bit is activate (1), so the signal will be send by the SIGUSR1, if the bit is not activate will be send by SIGUSR2.

> If you never see manipulating bit by bit, i recommend that you search for it, [read a blog that explain how it works.](http://c-for-dummies.com/blog/?p=1836)

This signals will be received by the server and store the value of the bit in a charactere if the bit is activate. after received all the message, the server will print the message on the terminal and send a signal to the client that means the message is receaved.

> **ATENTION: this project works with signals, and depending of the OS that you use, the signals might send wrong or lose some bits. I testED this project on Ubuntu and Mac OS, and works very well, so if you trying to run and not works as axpect, the problem must be your SO.**
