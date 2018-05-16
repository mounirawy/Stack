#include <iostream>
#include "List.h"

using namespace std;

template <class T>
class Stack{
private:
    List<T> l;
    int s;
public:
    Stack(){
    s=0;
    }
    Stack(T value,int initsize){
    List<T> l1(value,initsize);
    l=l1;
    s = initsize;
    }
    void push(T value){
      l.push_back(value);
      s++;
    }
    void pop(){
    typename List<T>::Iterator it = l.end();
    it--;
    l.erase(it);
    s--;
    }
    T &top(){
    typename List<T>::Iterator it = l.end();
    it--;
    return *it;
    }
    int size(){
    return s;
    }
    ~Stack(){
    typename List<T>::Iterator it=l.begin();
    typename List<T>::Iterator it2=l.end();
    while(it!=it2){
        typename List<T>::Iterator itemp = it;
        delete itemp.inode;
        it++;
    }
    delete it2.inode;
    }

};

int main()
{
    Stack<int> s(2,13);
//    s.push(4);
//    s.push(5);
//    s.push(12);
//    s.push(41);
//    s.push(0);
//    cout<<s.top();
//    s.pop();
//    cout<<s.top();
//        cout<<s.top();
       cout<<endl<<s.size()<<endl;
cout<<s.top()<<endl;
s.pop();
cout<<s.top()<<endl;






    return 0;
}
