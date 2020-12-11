//Contact book
#include<bits/stdc++.h>
using namespace std;

//contact list
typedef struct Node{
	string name;
	int number;
	Node* next;
}node;

//contact category
typedef struct category{
	string type;
	category* next;
	Node* head;
}cat;

bool addcategory(string type);
bool addcontact(string type,string name,int number);
bool search(string type,string name);
bool showall(string type);
bool deletecontact(string type,string name);

cat* catheader = NULL;

int main()
{
	int choice,number;
	string type,name;

	cout<<"\n**********Contact Book********\n";
	do{
		cout<<"\n1.Create a category\n2.Add a contact\n3.Search for Contact\n4.Show all\n5.Delete contact\n";
		cout<<"6.Exit\nEnter the choice : ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the category : ";
				cin>>type;
				if(addcategory(type)) cout<<"--sucesfully added--\n";
				else cout<<"could be added\n";
				break;
			case 2:
				cout<<"Enter the category : ";
				cin>>type;
				cout<<"Enter the name : ";
				cin>>name;
				cout<<"Enter the number : ";
				cin>>number;
				if(addcontact(type,name,number)) cout<<"--sucesfully added--\n";
				else cout<<"--could be added--\n";
				break;
			case 3:
				cout<<"Enter the category for search: ";
				cin>>type;
				cout<<"Enter the name for search : ";
				cin>>name;
				if(!search(type,name)) cout<<"--Not present--\n";
				break;
			case 4:
				cout<<"Enter the category : ";
				cin>>type;
				if(!showall(type)) cout<<"--No contact present--";
				break;
			case 5:
				cout<<"Enter the category for deletion: ";
				cin>>type;
				cout<<"Enter the name for deletion : ";
				cin>>name;
				if(!deletecontact(type,name)) cout<<"--Not Found--\n";	
				else cout<<"sucesfully deleted\n";			
				break;
			case 6:
				break;
			default: 
				cout<<"--Wrong Choice--\n";
		}
	}while(choice!=6);
	return 0;
}

bool addcategory(string type){
	cat* temp = new cat;
	temp->type=type;
	temp->next=NULL;
	temp->head=NULL;
	if(catheader==NULL) catheader=temp;
	else{
		cat* cur=catheader;
		while(cur->next!=NULL) cur=cur->next;
		cur->next=temp;
	}
	return true;
}
bool addcontact(string type,string name,int number){
	node* temp=new node;
	temp->number=number;
	temp->name=name;
	temp->next=NULL;
	cat* catcur = catheader;
	while(catcur!=NULL and catcur->type!=type) catcur=catcur->next;
	if(catcur==NULL) return false;
	node* nodecur = catcur->head;
	if(nodecur==NULL) catcur->head=temp;
	else{
		while(nodecur->next!=NULL) nodecur=nodecur->next;
		nodecur->next=temp;
	}
	return true;
}
bool search(string type,string name){
	cat* catcur = catheader;
	while(catcur!=NULL and catcur->type!=type) catcur=catcur->next;
	if(catcur==NULL) return false;
	node* nodecur = catcur->head;
	while(nodecur!=NULL and nodecur->name!=name) nodecur=nodecur->next;
	if(nodecur==NULL) return false;
	cout<<"Name : "<<nodecur->name<<"\nContact No : "<<nodecur->number<<endl;
	return true;
}
bool showall(string type){
	cat* catcur = catheader;
	while(catcur!=NULL and catcur->type!=type) catcur=catcur->next;
	if(catcur==NULL) return false;
	node* nodecur = catcur->head;
	if(nodecur==NULL) return false;
	int counter=0;
	while(nodecur!=NULL){
		cout<<"\n#"<<++counter<<"\nName : "<<nodecur->name<<"\nContact no :"<<nodecur->number;
		nodecur=nodecur->next;
	}
	cout<<endl;
	return true;
}
bool deletecontact(string type,string name){
	cat* catcur = catheader;
	while(catcur!=NULL and catcur->type!=type) catcur=catcur->next;
	if(catcur==NULL || catcur->head==NULL) return false;
	if(catcur->head->name==name) catcur->head=NULL;
	else{
		node* prev = catcur->head;
		node* curnode=prev->next;
		while(curnode!=NULL and curnode->name!=name){
			prev=curnode;
			curnode=curnode->next;
		}
		if(curnode==NULL) return false;
		prev->next=curnode->next;
	}
	return true;
}