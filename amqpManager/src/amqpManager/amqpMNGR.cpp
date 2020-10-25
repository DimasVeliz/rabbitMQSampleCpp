#include <iostream>
#include <amqpGhFixed/AMQPcpp.h>
#include "amqpMNGR.hpp"
#include "rapidjson/document.h"
#include <functional>
using namespace std;
using namespace rapidjson;

int i = 0;

int onCancel(AMQPMessage *message)
{
    cout << "cancel tag=" << message->getDeliveryTag() << endl;
    return 0;
}

amqpMNGR::amqpMNGR()
{
}

amqpMNGR::~amqpMNGR()
{
}


void amqpMNGR::StartConsuming(Weirdo * weirdGuy)
{
      
    auto event=[&weirdGuy](AMQPMessage * message) {
                      
        return weirdGuy->OnMessage33(message);
    };
    

    AMQP amqpCopy("guest:guest@localhost:5672");

    this->amqp = amqpCopy;
    this->qu2 = amqp.createQueue("topic_logs");
    this->qu2->Declare();
    this->qu2->Bind("topic_logs", "event.info");

    this->qu2->setConsumerTag("");
    this->qu2->addEvent(AMQP_MESSAGE, event);
    this->qu2->addEvent(AMQP_CANCEL, onCancel);
    qu2->Consume(AMQP_NOACK); //
}


