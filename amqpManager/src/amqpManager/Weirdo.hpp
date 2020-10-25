#include "amqpGhFixed/AMQPcpp.h"
#include "pervasiveObj.hpp"

class Weirdo
{
private:
    /* data */
   
    void UpdatePervasiveObj( char * data);
    vector<pervasiveObj> ParseData(char * data);
public:
    Weirdo(/* args */);
    ~Weirdo();
    int OnMessage33(AMQPMessage *message);
    std::vector <pervasiveObj> objetosRecibidos;    

};

