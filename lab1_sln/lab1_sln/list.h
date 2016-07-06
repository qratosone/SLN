#pragma once
#include "worker.h"
class List {
	//This is a class of List. As you can see it is actually a vector of workers.
	/*这是 List 类，你也许已经发现了，它其实是一个 Worker 的线性表*/
private:
	int size, length;
	Worker **data;
	/*
	提示：这里的data是一个指向指针的指针。
	在操作指针前请三思！
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
