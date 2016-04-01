#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;


 // Definition for singly-linked list with a random pointer.
  class RandomListNode {
      public:
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  };

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return nullptr;

        unordered_map<RandomListNode *, RandomListNode *> mapping;
        auto itr = head;
        auto newHead = new RandomListNode(head->label);
        auto newItr = newHead;

        while(itr){

            mapping[itr] = newItr;
            if(itr->next)
            newItr->next = new RandomListNode(itr->next->label);

            itr = itr->next;
            newItr = newItr->next;
        }
        itr = head;
        newItr = newHead;

        while(itr){

            if(itr->random)
                newItr->random = mapping[itr->random];

            itr = itr->next;
            newItr = newItr->next;
        }


        return newHead;
    }
};

int main() {

    Solution s;
    RandomListNode * node[10];
    for(int i = 0 ;i < 10; ++i)
        node[i] = new RandomListNode(i);

    for(int i = 0 ;i < 10; ++i){
        if(i + 1 < 10)
            node[i]->next = node[i + 1];
        node[i]->random = node[rand() % 10];
    }

    auto newlist = s.copyRandomList(node[0]);
    auto itr = node[0];
    while(itr){
        cout<<itr->label;
        if(itr->random)
            cout<<":"<<itr->random->label<<" ";
        itr = itr->next;
    }
    cout<<endl;

itr = newlist;
while(itr){
        cout<<itr->label;
        if(itr->random)
            cout<<":"<<itr->random->label<<" ";
        itr = itr->next;
    }

	getchar();
}
