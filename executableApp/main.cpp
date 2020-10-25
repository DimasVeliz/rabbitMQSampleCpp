#include <iostream>
#include <amqpGhFixed/AMQPcpp.h>
#include <amqpManager/amqpMNGR.hpp>



using namespace std;



int main () {

	try {

		Weirdo *w= new Weirdo();
		amqpMNGR manager;
		manager.StartConsuming(w);

	} catch (AMQPException e) {
		std::cout << e.getMessage() << std::endl;
	}

	return 0;
}

