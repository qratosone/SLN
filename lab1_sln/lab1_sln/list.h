#pragma once
#include "worker.h"
class List {
	//This is a class of List. As you can see it is actually a vector of workers.
	/*���� List �࣬��Ҳ���Ѿ������ˣ�����ʵ��һ�� Worker �����Ա�*/
private:
	int size, length;
	Worker **data;
	/*
	��ʾ�������data��һ��ָ��ָ���ָ�롣
	�ڲ���ָ��ǰ����˼��
	*/
public:
	List(int input_size);
	~List();
	int insert(Worker *new_worker);
	Worker *remove(int index);
	void expand();
	Worker *get(int index);
	void print();
};
