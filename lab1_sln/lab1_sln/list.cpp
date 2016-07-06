#include "list.h"
#include "worker.h"
#include <string>
#include <iostream>
#include <cstdlib>
/*提示：这里的data是一个指向指针的指针。
在操作指针前请三思！
如果你不知道的话：malloc的功能和 new 类似，
这里使用malloc是为了方便空间不足时进行扩展。
不用担心，扩展函数已为你写好。
－－前一位实习生
*/
List::~List() {
	for (int i = 0; i < length; i++) {
		delete *(data + i);
	}
	free(data);
}
/*
TODO 实现insert函数：在数组内插入新的worker。
如果数组满了呼叫expand()，返回 1
其他情况执行插入，返回 0
*/
int List::insert(Worker *new_worker) {//正常
	int expanded = 0;
	if (length == size) {
		expand();
		expanded = 1;
	}
	data[length] = new_worker;
	length++;
	return expanded;

}

//TODO get 函数的功能不言自明。你可以自行处理非法输入，但是绝不能容许内测错误。
Worker *List::get(int index) {//正常
	return data[index];
}

//TODO
Worker *List::remove(int index) {//找到问题了
	if (index<0 || index >= length) {
		return NULL;
	}
	Worker * removed_worker = data[index];
	for (int i = index; i < length - 1; i++) {
		data[i] = data[i + 1];
	}
	length--;
	return removed_worker;
}

/*预警：以下内容不许修改。*/
List::List(int input_size) {                   //警告：你不可以改动这个函数！
	size = input_size;
	length = 0;
	data = (Worker **)calloc(sizeof(Worker *), input_size);
}
void List::expand() {                          //警告：你不可以改动这个函数！
	size = size * 2;
	data = (Worker **)realloc(data, sizeof(Worker *) * size);
	return;
}
void List::print() {                           //警告：你不可以改动这个函数！
	std::cout << "Current List:\n";
	for (int i = 0; i < length; i++) {
		std::cout << "[" << i << "] ";
		(*(data + i))->print();
	}
	std::cout << "Current List Ends\n";
}
