#include "Weirdo.hpp"
#include "amqpGhFixed/AMQPcpp.h"
#include <rapidjson/document.h>


using namespace rapidjson;


Weirdo::Weirdo(/* args */)
{
    
}

Weirdo::~Weirdo()
{
}

int Weirdo::OnMessage33(AMQPMessage *message)
{
	uint32_t j = 0;
    char *data = message->getMessage(&j);
    if (data)
        {
            this->UpdatePervasiveObj(data);
            return 0;
        }

    return -1;	
}

void Weirdo::UpdatePervasiveObj( char * data){

    vector<pervasiveObj>newComers = ParseData(data);
    this->objetosRecibidos.insert(this->objetosRecibidos.end(),newComers.begin(),newComers.end());
    cout<<"La lista tiene ahora: "<<this->objetosRecibidos.size()<<endl;
    cout<<"..........."<<endl;

}

vector<pervasiveObj> Weirdo::ParseData(char * data){


    vector<pervasiveObj>answer;
    Document document;
    document.Parse(data);

    static const char *kTypeNames[] ={"Null", "False", "True", "Object", "Array", "String", "Number"};

    for (Value::ConstMemberIterator itr = document.MemberBegin(); itr != document.MemberEnd(); ++itr)
    {

        auto which = kTypeNames[itr->value.GetType()];
       
        if (which == "Array")
        {
            auto arreglo = itr->value.GetArray();
            cout<<"recibi: "<< arreglo.Size()<< " objetos desde el emisior \n{"<<endl;

            for (Value::ConstValueIterator itr2 = arreglo.Begin(); itr2 != arreglo.End(); ++itr2)
            {
                if (itr2->IsObject())
                {
                    auto objeto = itr2->GetObject();

                    pervasiveObj *p = new pervasiveObj();
                    for (auto itr3 = objeto.MemberBegin(); itr3 != objeto.MemberEnd(); ++itr3)
                    {
                        // cout<<"Las propiedades a listar son: "<<itr3->name.GetString()<<" "<<endl;

                        string propname = itr3->name.GetString();
                        if (propname == "class")
                        {
                            p->set_className(itr3->value.GetString());
                        }
                        if (propname == "objectid")
                        {
                            p->set_id(itr3->value.GetInt());
                        }
                        if (propname == "height")
                        {
                            p->set_height(itr3->value.GetDouble());
                        }
                        if (propname == "width")
                        {
                             p->set_width(itr3->value.GetDouble());
                        }
                    }

                    answer.push_back(*p);
                    cout << "id:" << p->get_id() << " "
                         << "class:" << p->get_className() << " "
                         << "height:" << p->get_height() << " "
                         << "width:" << p->get_width()<<endl;
                }
                
            }
            cout<<"}"<< endl;
            
        }

        
    }

    

    return answer;

}

