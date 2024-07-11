#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node *prev;
        Node(int data, Node* prev,Node* next){
            this->data=data;
            this->prev=prev;
            this->next=next;
        }
        Node(int data){
            this->data=data;
            this->prev=NULL;
            this->next=NULL;
        }
};
Node* deleteNodeLast(Node* head){
    if(head==NULL||head->next==NULL){
        return nullptr;
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* last=tail->prev;
    last->next=NULL;
    tail->prev=NULL;
    delete(tail);
    return head;
}
Node* deleteNodeHead(Node* head){
    if(head==NULL||head->next==NULL){
        return nullptr;
    }
    Node* curr=head;
    head=head->next;
    head->prev=NULL;
    curr->next=NULL;
    delete(curr);
    return head;
}
Node* deleteNodeAtIndex(Node* head,int index){
    if(head==NULL||head->next==NULL&&head->prev==NULL){
        return nullptr;
    }
    if(index==1){
        Node* curr=head;
        head=head->next;
        head->prev=NULL;
        curr->next=NULL;
        delete(curr);
        return head;
    }
    int count=1;
    Node* back=head;
    Node* curr=head;
    while(curr){
        if(count==index){
            break;
        }
        count++;
        back=curr;
        curr=curr->next;
    }
    if(curr->next==NULL){
        Node* last=curr->prev;
        last->next=NULL;
        curr->prev=NULL;
        delete(curr);
    }else{
        Node* CurrNext=curr->next;
        back->next=CurrNext;
        CurrNext->prev=back;
        delete(curr);
    }
    return head;
}
void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main()
{
    
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    Node * head=new Node(arr[0]);
    Node* curr=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],curr,NULL);
        curr->next=temp;
        curr=temp;
    }
    cout<<"Before Delete"<<endl;
    print(head);
    cout<<endl;
    Node *AfterDeleteHead=deleteNodeHead(head);
    cout<<"After Delete Head"<<endl;
    print(AfterDeleteHead);
    cout<<endl;
    Node *AfterDeleteLast=deleteNodeLast(AfterDeleteHead);
    cout<<"After Delete Last"<<endl;
    print(AfterDeleteLast);
    cout<<endl;
    Node *AfterDeleteAtIndex=deleteNodeAtIndex(AfterDeleteLast,1);
    cout<<"After Delete At Index"<<endl;
    print(AfterDeleteAtIndex);
    return 0;
}
