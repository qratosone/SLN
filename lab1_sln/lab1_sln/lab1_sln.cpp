// lab1_sln.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <csignal>
#include "list.h"
using namespace std;
int test1(int i);
int test2(int i);
int test3(int i);

void signalHandler(int signum)
{
	cout << "\nSegmentation Fault.\n";
	exit(signum);
}

int main() {
	signal(SIGSEGV, signalHandler);
	test1(1);
	test2(2);
	test3(3);
	return 1;
}

int test1(int i) {
	cout << "任务1 单元测试" << i << "\n";
	Worker *blah = new Worker();
	blah->print();
	Worker *blah2 = new Worker(new string("Blah2"));
	blah2->print();
	delete blah;
	delete blah2;
	return 0;
}

int test2(int i) {
	cout << "任务1 单元测试" << i << "\n";
	List *JSK = new List(3);
	for (int i = 0; i < 30; i++) {
		Worker *RnD = new Worker(new string("单元测试"));
		JSK->insert(RnD);

	}
	JSK->print();
	delete JSK;
	return 0;
}

int test3(int i) {
	cout << "任务1 单元测试" << i << "\n";
	List *JSK = new List(3);
	for (int i = 0; i < 30; i++) {
		Worker *RnD = new Worker(new string("RnD"));
		JSK->insert(RnD);
		//JSK->print();
	}
	for (int i = 0; i < 21; i += 10) {
		JSK->get(i)->print();
	}
	cout << "output finished" << endl;
	JSK->get(20)->print();
	JSK->remove(20);
	cout << "removed" << endl;
	JSK->print();
	delete JSK;
	return 0;
}
