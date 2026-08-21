#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;
    ListNode(int data){
        this->data=data;
        this->next=NULL;
    }
};

void solve(ListNode* temp1,ListNode*& temp2){
    if(temp1==NULL)return;
    solve(temp1->next,temp2);
    temp2->next=new ListNode(temp1->data);
    temp2=temp2->next;
}
void reverseLinkList(ListNode* head,ListNode* dummy){
   ListNode* temp1=head;
   ListNode* temp2=dummy;
   solve(temp1,temp2);
}

int main(){
    ListNode* head=new ListNode(0);
    cout<<"enter n.."<<endl;
    int n;
    cin>>n;
    ListNode* temp=head;
    
    for(int i=0;i<n;i++){
        temp->next=new ListNode(i+1);    
        temp=temp->next;
    }
    
    cout<<"original Link list->"<<endl;
    ListNode* temp1=head;
    while(temp1!=NULL){
        cout<<temp1->data;
        temp1=temp1->next;
    }
    
    ListNode* dummy=new ListNode(-1);
    reverseLinkList(head,dummy);
    cout<<"\nreverse link list..."<<endl;
    ListNode* temp2=dummy->next;
    while(temp2!=nullptr){
        cout<<temp2->data;
        temp2=temp2->next;
    }
    
    return 0;
}
