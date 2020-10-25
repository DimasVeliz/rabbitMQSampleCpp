#include <iostream>

using namespace std;

class pervasiveObj
{
private:
    int id;    
    double height;
    double width;
    string class_name;

public:
    pervasiveObj(/* args */);
    ~pervasiveObj();
    
    //setters
    void set_id(int id);
    void set_className(string class_name);
    void set_height(double h);
    void set_width(double w);


    //getters
    int get_id();
    string get_className();
    double get_height();
    double get_width();

};
