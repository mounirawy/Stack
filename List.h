#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

//make it private

template <class T>
class List{
public:
struct node{
T value;
node *pre,*next;
};
class Iterator{
public:
    node *inode;
    friend class List;
public:
    Iterator(){
    }
    Iterator operator++(int){
      Iterator it = *this;
      (*this).inode = (*this).inode->next;
      return it;
    }
    Iterator operator--(int){
     Iterator it=*this;
     (*this).inode = (*this).inode->pre;
     return it;
    }
    T &operator*(){
    return (*this).inode->value;
    }
    bool operator!=(Iterator it){
    if((*this).inode != it.inode){
        return true;
    }
    return false;
    }
    bool operator==(Iterator it){
    if((*this).inode == it.inode){
        return true;
    }
    return false;
    }
    };
public:
    node *head,*tail,*dummy;
    int s;
public:
    List(){
        head=NULL;
        tail=NULL;
        dummy = new node;
        s = 0;
    }
    List(T value,int initsize){
        s = 0;
        head=NULL;
        tail=NULL;
        dummy=new node;
       while(initsize!=0){
        push_back(value);
        initsize--;
       }
    }
    Iterator begin(){
        Iterator it;
        it.inode = head;
        return it;}

    Iterator end(){
        if(head==NULL){
           Iterator it;
           it.inode = tail;
           return it;
        }
        Iterator it;
        tail->next = dummy;
        dummy->pre = tail;
        dummy->next = NULL;
        it.inode = dummy;
        return it;}

    void insert(T value,Iterator &pos){
       node *temp = new node;
       temp->value = value;
       Iterator it = (*this).begin();
       Iterator it2 = (*this).end();
       if(head==NULL){
        head = tail = temp;
        head->pre = NULL;
        head->next = NULL;
        s++;
        pos.inode=head;
        return;
       }
       if(pos==it){
         temp->next = head;
         head->pre = temp;
         temp->pre = NULL;
         head = temp;
         pos.inode = head;
         s++;
       return;
       }
       if(pos.inode==tail){
           tail->pre->next = temp;
           temp->pre = tail->pre;
           temp->next = tail;
           tail->pre = temp;
            s++;
            pos.inode = tail->pre;
           return;
       }
       it++;
       while(it!=it2){
        if(it==pos){
           it.inode->pre->next = temp;
           temp->pre = it.inode->pre;
           temp->next = it.inode;
           it.inode->pre = temp;
           s++;
           pos.inode = temp;
           return;
        }
        it++;
       }
       cout<<"there's no a position such like that"<<endl;
    }

    Iterator erase(Iterator pos){
    if(pos.inode==head &&  size()==1){
        head = tail = NULL;
        s--;
        pos.inode = NULL;
        return pos;
    }
    if(pos.inode==head){
        head = head->next;
        delete head->pre;
        head->pre = NULL;
        s--;
        pos.inode = NULL;
        return pos;
    }
    if(pos.inode==tail){
        tail = tail->pre;
        delete tail->next;
        tail->next = NULL;
        pos.inode = tail;
        s--;
        return pos;
    }
    node *temp = head;
    while(temp!=tail->next){
       if(temp==pos.inode){
           temp->pre->next = temp->next;
           temp->next->pre = temp->pre;
           pos.inode = temp->pre;
           delete temp;
           s--;
           return pos;
       }
      temp = temp->next;
    }
    cout <<"this position is out of range"<<endl;
    }


    void push_back(int value)
    {
         node *temp = new node;
         temp->value = value;
         temp->pre = temp->next = NULL;
         if(head==NULL){
               head = tail = temp;
               s++;
               return;
         }
         tail->next = temp;
         temp->pre = tail;
         tail = temp;
         s++;
    }

    int size(){
      return s;
    }

     void printlist(){
      node *temp = head;
      Iterator it = (*this).end();
      while(temp!=it.inode){
        cout <<temp->value<<"   ";
        temp=temp->next;
      }
      cout<<endl;
    }
    void printreversly(){
    node *temp = tail;
    while(temp!=NULL){
        cout<<temp->value<<"   ";
        temp = temp->pre;
    }
    cout<<endl;
    }

    List &operator=(List<T> li){
        Iterator beg = li.begin();
        Iterator End = li.end();
        while(beg!=End){
             push_back(beg.inode->value);
             beg++;
        }
        return *this;
    }
//    ~List(){
//       node *headtemp = head;
//       node *tailtemp = tail;
//       while(headtemp!=tailtemp){
//        node *temp =headtemp;
//        delete temp;
//        headtemp = headtemp->next;
//       }
//       delete tailtemp;
//       delete tail->next;
//    }
};

#endif // LIST_H_INCLUDED
