#pragma once
#include <string>
class Worker {
	/*
	This is a basic example of how class works in c++.
	It is designed to test if you know basic syntax of c++.
	����һ���ܼ򵥵�class������ⲿ�ֵ�Ŀ���Ǽ�����Ƿ���Ϥc++�����﷨.
	*/
private:
	int id;                               //unique id for each worker, aka Team in Huayeke
	std::string *name;                   //name of the worker                   
public:
	static int num_worker;              //keep track of the num of workers in action
	Worker();                          //default constructor
	~Worker();                        //destructor
	Worker(std::string* input_name); //construnct a new object with name input_name
	int get_id();
	std::string *get_name();
	int print();                  //print function
};
