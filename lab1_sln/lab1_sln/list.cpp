#include "list.h"
#include "worker.h"
#include <string>
#include <iostream>
#include <cstdlib>
/*��ʾ�������data��һ��ָ��ָ���ָ�롣
�ڲ���ָ��ǰ����˼��
����㲻֪���Ļ���malloc�Ĺ��ܺ� new ���ƣ�
����ʹ��malloc��Ϊ�˷���ռ䲻��ʱ������չ��
���õ��ģ���չ������Ϊ��д�á�
����ǰһλʵϰ��
*/
List::~List() {
	for (int i = 0; i < length; i++) {
		delete *(data + i);
	}
	free(data);
}
/*
TODO ʵ��insert�������������ڲ����µ�worker��
����������˺���expand()������ 1
�������ִ�в��룬���� 0
*/
int List::insert(Worker *new_worker) {//����
	int expanded = 0;
	if (length == size) {
		expand();
		expanded = 1;
	}
	data[length] = new_worker;
	length++;
	return expanded;

}

//TODO get �����Ĺ��ܲ�����������������д���Ƿ����룬���Ǿ����������ڲ����
Worker *List::get(int index) {//����
	return data[index];
}

//TODO
Worker *List::remove(int index) {//�ҵ�������
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

/*Ԥ�����������ݲ����޸ġ�*/
List::List(int input_size) {                   //���棺�㲻���ԸĶ����������
	size = input_size;
	length = 0;
	data = (Worker **)calloc(sizeof(Worker *), input_size);
}
void List::expand() {                          //���棺�㲻���ԸĶ����������
	size = size * 2;
	data = (Worker **)realloc(data, sizeof(Worker *) * size);
	return;
}
void List::print() {                           //���棺�㲻���ԸĶ����������
	std::cout << "Current List:\n";
	for (int i = 0; i < length; i++) {
		std::cout << "[" << i << "] ";
		(*(data + i))->print();
	}
	std::cout << "Current List Ends\n";
}
