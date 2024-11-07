#include <iostream>
using namespace std;

struct node{
    int co;
    int ex;
    node* next;
    node(int c,int e,node* n = nullptr){
        co=c;
        ex=e;
        next=n;
    }
};

class poly{
    private:
        node* head;
    public:
        poly(){
            head = nullptr;
        }

        void extend(int c,int e){
            if(c==0) return;
            if(head==nullptr){
                head = new node(c,e);
            }
            else if(head->ex<e){
                head = new node(c,e,head);
                return;
            }
            else if(head->ex==e){
                head->co+=c;
                if(head->co == 0){
                    node* remove = head;
                    head = head->next;
                    delete remove;
                }
                return;
            }
            else{
                node* temp=head;
                while(temp->next!=nullptr){
                    if(e>temp->next->ex){
                        temp->next=new node(c,e,temp->next);
                        return;
                    }
                    else if(e==temp->next->ex){
                        temp->next->co+=c;
                        if(temp->next->co == 0){
                            node* remove = temp->next;
                            temp->next = temp->next->next;
                            delete remove;
                        }
                        return;
                    }
                    else temp=temp->next;
                }
                temp->next = new node(c,e);
            }
        }

        poly operator+ (const poly& other){
            poly rt;
            node* temp = head;
            while(temp!=nullptr){
                rt.extend(temp->co,temp->ex);
                temp=temp->next;
            }
            temp=other.head;
            while(temp!=nullptr){
                rt.extend(temp->co,temp->ex);
                temp=temp->next;
            }
            return rt;
        }

        poly operator* (const poly& other){
            poly rt;
            node* temp = head;
            while(temp!=nullptr){
                node* othertemp = other.head;
                while(othertemp!=nullptr){
                    rt.extend(temp->co*othertemp->co,temp->ex+othertemp->ex);
                    othertemp=othertemp->next;
                }
                temp=temp->next;
            }
            return rt;
        }

        void print(){
            node* temp = head;
            if(temp==nullptr) cout<<"0 0";
            else
                while(temp != nullptr){
                    cout << temp->co << " " << temp->ex;
                    if(temp->next != nullptr) cout << endl;
                    temp = temp->next;
                }
            cout << endl;
        }
};

int main(){
    int cases=1;
    while(1){
        cout<<"case"<<cases<<endl;
        poly a,b,c,d;
        int inC,inE;
        int aN;
        cin>>aN;
        for(int i=0;i<aN;i++){
            cin>>inC>>inE;
            a.extend(inC,inE);
        }
        cout<<"A"<<endl;
        a.print();
        int bN;
        cin>>bN;
        if(aN==0&&bN==0){
            break;
        }
        for(int i=0;i<bN;i++){
            cin>>inC>>inE;
            b.extend(inC,inE);
        }
        cout<<"B"<<endl;
        b.print();
        c=a+b;
        cout<<"C"<<endl;
        c.print();
        cout<<"D"<<endl;
        d=a*b;
        d.print();
        cases++;
    }
}