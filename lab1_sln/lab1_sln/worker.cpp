#include "worker.h"
#include <string>
#include <iostream>
int Worker::num_worker = 0;
Worker::Worker() {                            //���棺�㲻���ԸĶ����������
	this->id = num_worker;
	num_worker++;
	this->name = new std::string("default_string");

}
Worker::~Worker() {                           //���棺�㲻���ԸĶ����������
	delete this->name;
}
Worker::Worker(std::string* input_name) {
	/*TODO ʵ��һ�����캯����
	Worker������Ӧ�ñ������ڶ�(Heap)��*/

	this->id = num_worker;
	num_worker++;
	this->name = input_name;

}

int Worker::get_id() {
	/*TODO ʵ��һ��get������
	���ظ�worker��id*/
	return this->id;
}
std::string *Worker::get_name() {
	/*TODO ʵ��һ��get������
	���ظ�worker��Name*/
	return this->name;
}

int Worker::print() {
	std::cout << "Worker [" << this->id << "] with name [" << *(this->name) << "]\n";
	return 0;
}
