#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;

class DNode {
public:
	DNode(int _key, int _val) :key(_key), val(_val) {};
	int val;
	int key;
	DNode * prev;
	DNode * next;
};

class LRUCache {
public:
	LRUCache(int _capacity) {
		this->capacity = _capacity;
		currentSize = 0;
		tail = nullptr;
		head = nullptr;
	}

	int get(int key) {
		if (mapping.count(key) > 0) {
			auto node = mapping[key];
			remove(node);
			setHead(node);
			return node->val;
		}
		else {
			return -1;
		}
	}

	void set(int key, int value) {
		if (mapping.count(key) > 0) {
			auto node = mapping[key];
			node->val = value;
			remove(node);
			setHead(node);
		}
		else {
			if (currentSize >= capacity) {
				mapping.erase(tail->key);
				auto deleted = tail;
				remove(tail);
				delete deleted;
			}

			auto newNode = new DNode(key, value);
			setHead(newNode);
			currentSize++;
			mapping[key] = newNode;


		}
	}
	void print() {
		auto itr = head;
		while (itr) {
			cout <<itr->key<<"->" <<itr->val<<" ";
			itr = itr->next;
		}
		cout << endl;
	}
private:

	void remove(DNode * node) {
		if (node->prev) {
			node->prev->next = node->next;
			if (node->next) {
				node->next->prev = node->prev;
			}
			else {
				tail = node->prev;
			}
		}
		else {
			if (node->next)
				node->next->prev = nullptr;
			else
				tail = nullptr;

			head = node->next;
		}

	}
	void setHead(DNode * node) {
		if (head)
			head->prev = node;

		node->prev = nullptr;
		node->next = head;
		head = node;
		if (!tail)
			tail = head;
	}
	DNode * head;
	DNode * tail;
	unordered_map<int, DNode *> mapping;
	int capacity, currentSize;

};

int main() {

	LRUCache cache(2);
	cache.set(2, 1);
	cache.set(1, 1);
	cache.print();
	cout << cache.get(2) << endl;
	cache.print();
	cache.set(4, 1);
	cache.print();
	cout << cache.get(1) << endl;
	cout << cache.get(2) << endl;
	getchar();
}
