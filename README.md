# rabbitMQSampleCpp

# The following script is an executable written in C++ that implements rabbitmq to receive messages in the command line, using cmake 3.18

## It uses MODIFIED versions of the rabbitmq-c library as well as a c++ wrapper obtained and bug-fixed from:
https://github.com/alanxz/rabbitmq-c

https://github.com/akalend/amqpcpp

# Requirements to install in Ubuntu 18.04
```
$ sudo apt-get install openssl
$ sudo apt-get install libssl-dev
$ sudo apt-get install libpopt-dev
$ sudo apt-get install -y xmlto
$ sudo apt-get install doxygen
```
# To compile it, from the root directory:
```
$ cd amqpGhFixed/rabbitmq-c
$ sudo make install
$ cd ../../
$ mkdir build && cd build
$ cmake ..
$ make
```

# Once compiled To execute it, and within the build folder:
```
$ cd pervasive-exec-rabbitmq
$ ./pervasive-exec-rabbitmq
```

