#include "worker.h"
#include <string>
#include <iostream>
int Worker::num_worker = 0;
Worker::Worker() {                            //警告：你不可以改动这个函数！
	this->id = num_worker;
	num_worker++;
	this->name = new std::string("default_string");

}
Worker::~Worker() {                           //警告：你不可以改动这个函数！
	delete this->name;
}
Worker::Worker(std::string* input_name) {
	/*TODO 实现一个构造函数。
	Worker的名字应该被分配在堆(Heap)上*/

	this->id = num_worker;
	num_worker++;
	this->name = input_name;

}

int Worker::get_id() {
	/*TODO 实现一个get函数。
	返回该worker的id*/
	return this->id;
}
std::string *Worker::get_name() {
	/*TODO 实现一个get函数。
	返回该worker的Name*/
	return this->name;
}

int Worker::print() {
	std::cout << "Worker [" << this->id << "] with name [" << *(this->name) << "]\n";
	return 0;
}
