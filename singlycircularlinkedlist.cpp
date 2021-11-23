
class node{
        public:
        int data;
        node* next;
        node(int x){
                data=x;
                next=this;
        }
};


void addnode(node **head,int pos){
        int data;
        int count=1;
        node *q;

        q=*head;
        cout<<"enter data to insert"<<endl;
        cin>>data;
        node *temp=new node(data);

        if(*head==NULL){
                *head=temp;
                temp->next=*head;
        }else if(pos==1){
                while(q->next!=*head){
                        q=q->next;
                }
                temp->next=*head;
                *head=temp;
                q->next=temp;
        }else{
                node *p=*head;
                while(count!=pos-1 && p->next!=*head){
                        count++;
                        p=p->next;
                }
                if(count==pos-1){
                        temp->next=p->next;
                        p->next=temp;
                }else{
                        p->next=temp;
                        temp->next=*head;
                }
        }
}


void deletenode(node **head,int pos){
        node *p,*q;
        q=*head;
        if(*head==NULL){
                cout<<"empty list\n";
        }else if(pos==1){
                q=*head;
                while(q->next!=*head)q=q->next;
                p=*head;
                *head=p->next;
                q->next=*head;
                delete(p);
        }else{
                p=*head;
                for(int i=2;i<=pos;i++){
                        q=q->next;
                }
                for(int i=2;i<pos;i++){
                        p=p->next;
                }
                p->next=q->next;
                delete(q);
        }
}


void reverselist(node **head){
        node *prev, *cur, *next ,*last;
        if(*head==NULL){
                cout<<"empty list"<<endl;
        }else{
                last=*head;
                prev=*head;
                cur=(*head)->next;
                *head=(*head)->next;


                while(*head!=last){
                        *head=(*head)->next;
                        cur->next=prev;
                        prev=cur;
                        cur=*head;
                }
                cur->next=prev;
                *head=prev;
        }

}



void createlist(node** head,int num){
        node *p,*temp;
        for(int i=1;i<=num;i++){
                int data;
                cout<<"enter the value of data: ";
                cin>>data;
                cout<<"\n";
                node *temp=new node(data);
                if(*head==NULL){
                        *head=temp;
                }else{
                        p=*head;
                        while(p->next!=*head) p=p->next;
                        p->next=temp;
                        temp->next=*head;
                }
        }
}


void traverselist(node **head){
        if(*head==NULL){
                cout<<"no node present"<<endl;
        }else{

                node *p;
                p=*head;
                while(p->next!=*head){
                        cout<<p->data<<endl;
                        p=p->next;
                }
                cout<<p->data<<endl;
        }
}


int main(){
        node *head=NULL;
        int options,num;
        while(1){
                cout<<"1.) createnode\n2.) traversenode\n3.)addnode\n4.)deletenode\n5.)reverselinkedlist\n6.)exit"<<endl;
                cin>>options;

                switch(options){
                        case 1:
                                cout<<"enter the no of nodes to be created\n"<<endl;
                                cin>>num;
                                createlist(&head,num);
                                break;
                        case 2:
                                traverselist(&head);
                                cout<<"list traversed"<<endl;
                                break;
                        case 3:
                                int pos;
                                cout<<"enter the pos where you want to add node"<<endl;
                                cin>>pos;
                                addnode(&head,pos);
                                break;
                        case 4:
                                int pos1;
                                cout<<"enter the position of node to be deleted"<<endl;
                                cin>>pos1;
                                deletenode(&head,pos1);
                                cout<<"node deleted"<<endl;
                                break;

                        case 5:
                                reverselist(&head);
                                break;

                        case 6:
                                return 0;
                        default:
                                cout<<"no matching option"<<endl;
                                break;
                }
        }
        return 0;
}



