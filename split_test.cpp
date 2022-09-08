#include "split.h"
#include <iostream>
using namespace std;

int main(){
    Node *test = new Node(1,nullptr);
    Node *odd = nullptr;
    Node *even = nullptr;

    Node *iterator = test;
    for(int i = 2; i < 20; i++){
        iterator->next = new Node(i,nullptr);
        iterator = iterator->next;
    }

    split(test, odd, even);

    while(even!=nullptr){
        cout << even->value << endl;
        iterator = even;
        even = even->next;
        delete iterator;
    }
    
    while(odd!=nullptr){
        cout << odd->value << endl;
        iterator = odd;
        odd = odd->next;
        delete iterator;
    }
    return 0;
    
}