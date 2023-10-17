//
//  main.cpp
//  FL1
//
//  Created by Michalis on 16.10.2023.
//

#include <iostream>
using namespace std;

struct Element
{
    char data;
    Element* next;
};
class List
{
    Element* head;
    Element* tail;
    int count;
public:
    List();
    ~List();
    void Add(char d);
    void Del();
    void DelAll();
    void Print();
    int GetCount();
    void AddinPos(char d, int c);
    void DelInPos(int c);
    char findUSElem(int c);
};
List::List()
{
    head=tail=NULL;
    count=0;
}
List::~List()
{
    DelAll();
}
int List::GetCount()
{
    return count;
}
void List::Add(char d)
{
    Element* temp=new Element;
    temp->data=d;
    temp->next=NULL;
    if (head!=NULL)
    {
        tail->next=temp;
        tail=temp;
    }
    else
    {
        head=tail=temp;
    }
    count++;
}
void List::Del()
{
    Element* temp=head;
    head=head->next;
    delete temp;
    count--;
}
void List::DelAll()
{
    while(head!=0)
    {
        Del();
    }
}
void List::Print()
{
    Element* temp=head;
    while(temp!=0)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<endl;
}
void List::AddinPos(char d, int c)
{
    if (c<0)
    {
        cout<<"Error!";
        cout<<endl;
    }
    else if(c==0)
    {
        Element* temp=head;
        Element* newtemp=new Element;
        newtemp->data=d;
        newtemp->next=temp;
        head=newtemp;
        count++;
    }
    else
    {
        int arrCount=0;//Предположим, что 1 элемент(head) находится в позиции 0
        Element* ptr=head;
        while(arrCount<c-1)
        {
            ptr=ptr->next;
            arrCount++;
        }
        
            Element* temp=ptr->next;
            Element* newtemp=new Element;
            newtemp->data=d;
            newtemp->next=temp;
            ptr->next=newtemp;
            count++;
    }
    
    
}
void List::DelInPos(int c)
{
    if (c<0)
    {
        cout<<"Error!";
        cout<<endl;
    }
    else if(c==0)
    {
        Del();
        count--;
    }
    else
    {
        int arrCount=0;//Предположим, что 1 элемент(head) находится в позиции 0
        Element* ptr=head;
        Element* temp;
        while(arrCount<c-1)
        {
            ptr=ptr->next;
            arrCount++;
        }
        temp=ptr;
        temp=temp->next;
        ptr->next=temp->next;
        delete temp;
        

        count--;
    }
    
}
char List::findUSElem(int c)
{
    int arrCount=0;//Предположим, что 1 элемент(head) находится в позиции 0
    Element* ptr=head;
    while(arrCount<c-1)
    {
        ptr=ptr->next;
        arrCount++;
    }
    return ptr->data;
}
int main() {
    
    List lst;
    char s[]="Hello world!!!";
    cout<<s<<endl;
    int len=(int)strlen(s);
    for (int i=0;i<len;i++)
    {
        lst.Add(s[i]);
    }
    lst.Print();
    lst.Del();
    lst.Del();
    lst.Del();
    lst.Print();
    lst.AddinPos('a', 0);
    lst.Print();
    lst.AddinPos('b', 5);
    lst.Print();
    lst.DelInPos(0);
    lst.Print();
    lst.DelInPos(4);
    lst.Print();
    char symInPos=lst.findUSElem(4);
    cout<<symInPos;
    cout<<endl;
    
    
    return 0;
}
