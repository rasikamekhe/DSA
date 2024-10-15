/* Department of Computer Engineering has student's club named 'Pinnacle Club'.
Students of second, third and final year of department can be granted membership on
request. Similarly one may cancel the membership of club. First node is reserved for
president of club and last node is reserved for secretary of club. Write C++ program to
maintain club member‘s information using singly linked list. Store student PRN and
Name. Write functions to:
a)Add and delete the members as well as president or even secretary.
b)Compute total number of members of club
c)Display members
d)Two linked lists exists for two divisions. Concatenate two lists. */

#include<iostream>
#include<string.h> 
using
namespace std;
class node{
public: 
char name[50];
int PRN; 
node*next;
};
class SLL{
node*head, *last;
node*temp, *temp1;
public:
int count;
void create(){
int ch, data;
char str[50];
do{
if(head==NULL){
temp=new node;
cout<<"\nEnter PRN and name of the PRESIDENT: ";
cin>>temp->PRN>>temp->name;

temp->next=NULL;
head=temp;
temp=new node;
cout<<"\nEnter PRN and name of the SECRETARY: ";
cin>>temp->PRN>>temp->name;
temp->next=NULL;
last=temp;
head->next=last;
count=count+2;
}
else{
temp1=head;
while(temp1->next!=last)
temp1=temp1->next;
temp=new node;
cout<<"\nEnter PRN and name for MEMBER: ";
cin>>temp->PRN>>temp->name;
temp->next=NULL;
temp1->next=temp;
temp->next=last;
count++;
}
cout<<"\nDo you want to add more members? Press 1 for yes, else press 0: ";
cin>>ch;
}while(ch==1);

}
void display(){
if(head==NULL){
cout<<"\nCREATE A LINKED LIST FIRST!!!!"<<endl;
}
else{
temp=head;
cout<<"\nPRESIDENT OF CLUB IS: ";
cout<<temp->PRN<<" "<<temp->name;
temp=temp->next;
cout<<"\nAll the MEMBERS of the club are: \n";
while(temp->next!=NULL){
cout<<temp->PRN<<" "<<temp->name<<"\n";
temp=temp->next;
}
cout<<"\nSECRETARY OF THE CLUB IS: ";
cout<<temp->PRN<<" "<<temp->name<<"\n";
}
}
void search(){
int key, flag=0;
if(head==NULL){
cout<<"\nCREATE A LINKED LIST FIRST!!!!";
}
else{

temp=head;
cout<<"\nEnter the PRN of the student you want to search: ";
cin>>key;
while(temp!=NULL){
if(key==temp->PRN){
cout<<"\nFOUND!!!"<<endl;
flag=1;
break;
}
temp=temp->next;
}
if(flag==0)
cout<<"\nNOT FOUND!!!!"<<endl;
}
}
void addmembers(){
int c;
if(head==NULL){
cout<<"\nCREATE A LINKED LIST FIRST!!!!";
create();
}
else{
cout<<"\n.............MENU FOR ADDING MEMBERS.............";
cout<<"\n1.Add the PRESIDENT"; cout<<"\n2.Add the
SECRETARY";

cout<<"\n3.Add the MEMBER";
cout<<"\nEnter your choice: ";
cin>>c;
switch(c){
case 1:
temp=new node;
cout<<"\nEnter the PRN and name of the PRESIDENT: ";
cin>>temp->PRN>>temp->name;
temp->next=NULL;
temp->next=head;
head=temp;
break;
case 2:
temp=new node;
cout<<"\nEnter PRN and name of the SECREATRY: ";
cin>>temp->PRN>>temp->name;
temp->next=NULL;
last->next=temp;
last=temp;
break;
case 3:
create();
break;
default:
cout<<"\nINVALID CHOICE!!!"<<endl;

break;
}
}
}
void deletenode(){
int c;
if(head==NULL){
cout<<"\nCREATE A LINKED LIST FIRST!!!";
create();
}
else{
cout<<"\n......MENU FOR DELETION........";
cout<<"\n1.Delete the president";
cout<<"\n2.Delete the secretary";
cout<<"\n3. Delete the member of the club";
cout<<"\nEnter your choice: ";
cin>>c;
switch(c){
case 1:
if(head==last){
head=last=NULL;
}
else{
temp=head;
head=head->next;

delete temp;
}
break;
case 2:
if(head==last){
head=last=NULL;
}
else{
temp=head;
while(temp->next!=last)
temp=temp->next;
delete last;
temp->next=NULL;
last=temp;
}
break;
case 3:
if(head==last){
head=last=NULL;
}
else{

}
default:
cout<<"\nINVALID CHOICE!!!!";

break;
}
}
}
SLL(){
count=0;
head=NULL;
last=NULL;
}
};

int main(){
int ch, op;
SLL obj;
do{
cout<<"\n.....MAIN MENU......";
cout<<"\n1. Creat a list";
cout<<"\n2. Display the list";
cout<<"\n3. Search from the list";
cout<<"\n4. Display total memeber of pinnacle club: ";
cout<<"\n5. Insert a memeber";
cout<<"\n6. Delete a member";
cout<<"\nEnter your choice: ";
cin>>ch;
switch(ch){

case 1:
obj.create();
break;
case 2:
obj.display();
break;
case 3:
obj.search();
break;
case 4:
cout<<"\nTotal memeber of the pinnacle club are: "<<obj.count-2;
break;
case 5:
obj.addmembers();
break;
case 6:
obj.deletenode();
break;
default:
cout<<"\nINVALID CHOICE!!!!";
break;

}
cout<<"\nDo you want to perform again? press 1 for yes else press 0: ";
cin>>op;
}while(op==1);

}
return 0;
