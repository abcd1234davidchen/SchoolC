#include <iostream>
using namespace std;

struct node{
    int co;     //coefficent of node
    int ex;     //exponential of node
    node* next; //pointer to next
    node(int c,int e,node* n = NULL){   //constructor for node
        co=c;   //set co to c
        ex=e;   //set ex to e
        next=n; //set next to n
    }
};

class poly{
    private:
        node* head; //head to carry the whole polynominal
    public:
        poly(){     //constructor
            head = NULL;    //null head waiting for input
        }

        ~poly(){    //destructor
            node* current = head;
            while(current != nullptr){  //when not null
                node* nextNode = current->next; //remember next
                delete current;         //delete
                current = nextNode;     //move to next
            }
        }

        void extend(int c,int e){
            if(c==0) return;    //skip if coefficent is 0
            if(head==NULL){     //create a new poly if head is NULL
                head = new node(c,e);
            }
            else if(head->ex<e){    //case for the input being the new head
                head = new node(c,e,head);  //set head to be the new node
                return;
            }
            else if(head->ex==e){   //case for head adding coefficent
                head->co+=c;        //add to head
                if(head->co == 0){  //remove head if head is 0
                    node* remove = head;    //temp to remove
                    head = head->next;      //make head its next
                    delete remove;          //remove head
                }
                return;
            }
            else{                   //case for number to add into polynominal where is not head
                node* temp=head;
                while(temp->next!=NULL){
                    if(e>temp->next->ex){       //if the input is bigger than next of temp insert it
                        temp->next=new node(c,e,temp->next);    //make the next of temp to be the new node 
                        return;                                 //and make new node connect to the original next
                    }
                    else if(e==temp->next->ex){ //if the input is same with temp then add on
                        temp->next->co+=c;
                        if(temp->next->co == 0){    //if 0 remove it
                            node* remove = temp->next;
                            temp->next = temp->next->next;  //connect next to the next of next
                            delete remove;
                        }
                        return;
                    }
                    else temp=temp->next;       //move to next
                }
                temp->next = new node(c,e);     //add at the end of polynominal
            }
        }

        poly& operator=(poly other) {   //swap head to prevent rt being deleted and c d have no where to find
            swap(head, other.head);
            return *this;
        }

        poly operator+ (const poly& other){     //operator to do add
            poly rt;    //make a poly for return
            node* temp = head;
            while(temp!=NULL){  //add everything in this poly to rt
                rt.extend(temp->co,temp->ex);   //use extend to add node to poly
                temp=temp->next;    //move to next
            }
            temp=other.head;
            while(temp!=NULL){  //add everything from other to rt
                rt.extend(temp->co,temp->ex);   //use extend to add node to poly
                temp=temp->next;    //move to next
            }
            return rt;
        }

        poly operator* (const poly& other){
            poly rt;    //make poly to return
            node* temp = head;  //temp for this poly
            while(temp!=NULL){
                node* othertemp = other.head;   //temp for other poly
                while(othertemp!=NULL){
                    rt.extend(temp->co*othertemp->co,temp->ex+othertemp->ex);   //add new node into rt
                    othertemp=othertemp->next;  //move to next other temp
                }
                temp=temp->next;    //move to next temp
            }
            return rt;
        }

        void print(){
            node* temp = head;
            if(temp==NULL) cout<<"0 0"<<endl; //print 0 0 if 0
            else
                while(temp != NULL){
                    cout << temp->co << " " << temp->ex<<endl;    //move to next and print
                    temp = temp->next;      //move to next
                }
        }
};

int main(){
    int cases=1;
    while(1){
        poly A,B,C,D;
        int inC,inE;    //for input
        int aN;         //number of A
        cin>>aN;
        for(int i=0;i<aN;i++){
            cin>>inC>>inE;
            A.extend(inC,inE);  //input to A
        }
        int bN;         //number of B
        cin>>bN;
        if(aN==0&&bN==0){   //case to break
            break;
        }
        for(int i=0;i<bN;i++){
            cin>>inC>>inE;
            B.extend(inC,inE);  //input to B
        }
        cout<<"Case"<<cases<<":"<<endl;
        cout<<"ADD"<<endl;
        C=A+B;  //A+B
        C.print();
        cout<<"MULTIPLY"<<endl;
        D=A*B;  //A*B
        D.print();
        cases++;
    }
}
