#include <iostream>

#include "GoodsList.h"


// Goods:

Goods::Goods(string name, int nums) {
	this->name = name;
	this->nums = nums;
}

void Goods::show() {
	cout << name << "," << nums;
}


// GoodsList:

GoodsList::GoodsList() {
	list = new Node;
	list->goods = new Goods;
	list->next = NULL;
}

void GoodsList::insert(Goods* goods) {
	Node* aft = list->next, * beg = list;

	for (; aft != NULL; beg = aft, aft = aft->next) {
		if (goods->getName() == aft->goods->getName()) {
			aft->goods->addNum(goods->getNum());
			break;
		}
	}
	if (aft == NULL) {
		Node* p = new Node;
		p->next = NULL;
		p->goods = new Goods;
		*p->goods = *goods;

		beg->next = p;
		list->goods->addNum(1);
	}
}


void GoodsList::remove(string name, int nums) {
	Node* aft = list->next, * beg = list;

	for (; aft != NULL; beg = aft, aft = aft->next) {
		if (aft->goods->getName() == name) {
			if (aft->goods->getNum() > nums)
				aft->goods->addNum(-nums);
			else if (aft->goods->getNum() == nums) {
				// del
				beg->next = aft->next;
				aft->next = NULL;
				delete aft;

				list->goods->addNum(-1);
			}
			else {
				cout << "Not enough goods!" << endl;
			}
			break;
		}
	}
	if (aft == NULL) {
		cout << "Not enough goods!" << endl;
	}
}
void GoodsList::show() {
	for (Node* i = list->next; i != NULL; i = i->next) {
		if (i->goods->getNum() != 0) {
			if (i != list->next)
				cout << " ";
			cout << i->goods->getName() << "," << i->goods->getNum();
		}
	}

	cout << endl;
}

void GoodsList::sort() {
	int n = list->goods->getNum();
	Node* arr = new Node[n + 10];
	Node* beg = list->next;

	for (int i = 1; beg != NULL && i <= n; beg = beg->next, ++i) {
		if (beg->goods->getNum() != 0)
			arr[i] = *beg;
	}
	
	for (int i = 1; i <= n; ++i) {
		int maxInd = i;
		for (int k = i + 1; k <= n; ++k) {
			if (arr[maxInd].goods->getNum() < arr[k].goods->getNum()) {
				maxInd = k;
			}
		}
		if (maxInd != i) {
			Node tmp = arr[maxInd];
			arr[maxInd] = arr[i];
			arr[i] = tmp;
		}
	}

	Node* aft = list->next, * bef = list->next, * pHead = NULL, * pGene = NULL;
	if (bef->next == NULL) {
		delete[]bef;
	}
	else {
		aft = bef->next;
		while (aft != NULL) {
			bef->next = NULL;
			delete[]bef;
			bef = aft;
			aft = aft->next;
		}
	}
	
	list->next = NULL;
	
	for (int i = 1; i <= n; ++i) {
		// cout << arr[i].goods->getName() << " ";
		if (i == 1) {
			pHead = new Node;
			*pHead = arr[i];
			pHead->next = NULL;
			pGene = pHead;
		}
		else {
			pGene->next = new Node;
			*pGene->next = arr[i];
			pGene = pGene->next;
			pGene->next = NULL;
		}
	}

	// cout << endl;

	list->next = pHead;
	
	delete[]arr;
}
int GoodsList::count() {
	int num = 0;
	for (Node* beg = list->next; beg != NULL; beg = beg->next) {
		++num;
	}
	return num;
}

void GoodsList::clear() {
	Node* bef = list->next, * aft = list->next;
	if (bef->next == NULL) {
		delete[]bef;
	}
	else {
		aft = bef->next;
		while (aft != NULL) {
			bef->next = NULL;
			delete[]bef;
			bef = aft;
			aft = aft->next;
		}
	}
	list->goods->addNum(-list->goods->getNum());
	list->next = NULL;
}
