#include <iostream>
#include <amqpGhFixed/AMQPcpp.h>
#include "Weirdo.hpp"

using namespace std;
class amqpMNGR
{
private:
    AMQP amqp;
    AMQPQueue * qu2 ;

    public : 
        amqpMNGR();
        ~amqpMNGR();
        void StartConsuming(Weirdo  *weirdGuy);
        


};

