#include <iostream>
#include "pervasiveObj.hpp"

using namespace std;

pervasiveObj::pervasiveObj(/* args */)
{
}

pervasiveObj::~pervasiveObj()
{
}


//setters
void pervasiveObj::set_id(int id)
{
    this->id=id;    
}
void pervasiveObj::set_className(string class_name)
{
    this->class_name=class_name;    
}
void pervasiveObj::set_height(double h)
{
    this->height=h;    
}
void pervasiveObj::set_width(double w)
{
    this->width=w;    
}


//getters implementation
int pervasiveObj::get_id(){
    return this->id;
}

string pervasiveObj::get_className(){
    return this->class_name;
}

double pervasiveObj::get_height(){
    return this->height;
}
double pervasiveObj::get_width(){
    return this->width;
}