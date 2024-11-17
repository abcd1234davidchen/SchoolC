#include <iostream>
#include <iomanip>
using namespace std;

class node{
    friend class tree;
    private:
        int value;
        node* leftNode;
        node* rightNode;
    public:
        node(int v,node* lft=NULL,node* rht=NULL):value(v),leftNode(lft),rightNode(rht){};
};

class tree{
    private:
        node* head;
    public:
        tree(){head = NULL;}

        void insert(int n,node* current=NULL){
            if(head==NULL){
                head = new node(n);
                return;
            }
            if(current==NULL){
                current = head;
            }
            if(current->value<n){
                if(current->rightNode!=NULL){
                    insert(n,current->rightNode);
                }
                else{
                    current->rightNode = new node(n);
                }
            }
            else if(current->value>n){
                if(current->leftNode!=NULL){
                    insert(n,current->leftNode);
                }
                else{
                    current->leftNode = new node(n);
                }
            }
            else{
                remove(n);
            }
            return;
        }

        void remove(int n){
            if(head == NULL) return;

            node* prev = head;
            node* targ = head;
            while(targ->value!=n){
                prev=targ;
                if(targ->value>n){
                    targ=targ->leftNode;
                }
                else if(targ->value<n){
                    targ=targ->rightNode;
                }
            }

            if(targ->leftNode==NULL&&targ->rightNode==NULL){
                if(prev==targ){
                    head=NULL;
                }
                else if(prev->value>targ->value){
                    prev->leftNode=NULL;
                }
                else if(prev->value<targ->value){
                    prev->rightNode=NULL;
                }
                delete(targ);
            }
            else if(targ->leftNode==NULL){
                if(prev==targ) head = targ->rightNode;
                else if(prev->value>targ->value){
                    prev->leftNode=targ->rightNode;
                }
                else if(prev->value<targ->value){
                    prev->rightNode=targ->rightNode;
                }
                delete(targ);
            }
            else if(targ->rightNode==NULL){
                if(prev==targ) head = targ->leftNode;
                else if(prev->value>targ->value){
                    prev->leftNode=targ->leftNode;
                }
                else if(prev->value<targ->value){
                    prev->rightNode=targ->leftNode;
                }
                delete(targ);
            }
            else{
                node* rplm = targ->rightNode;
                while(rplm->leftNode!=NULL) rplm = rplm->leftNode;
                int rpmN = rplm->value;
                remove(rpmN);
                targ->value = rpmN;
            }
        }

        void print(node* current=NULL,int mode = 0){
            if(mode==0){cout<<"VALUE: ";}
            if(current==NULL) current=head;
            if(current->leftNode!=NULL) print(current->leftNode,(mode==0?1:mode));
            if(current!=NULL){
                if(mode==0||mode==1)cout<<setw(3)<<current->value;
                if(mode==2)cout<<setw(3)<<((current->leftNode!=NULL)?current->leftNode->value:0);
                if(mode==3)cout<<setw(3)<<((current->rightNode!=NULL)?current->rightNode->value:0);
            };
            if(current->rightNode!=NULL) print(current->rightNode,(mode==0?1:mode));
            if(mode==0) {
                cout<<endl;
                cout<<"LEFT : ";
                print(head,2);
                cout<<endl;
                cout<<"RIGHT: ";
                print(head,3);
            }
        }

};

int main() {
    int ipt;
    bool notFirst = false;
    while(cin>>ipt){
        if(notFirst) cout<<endl;
        notFirst = true;
        tree Tree;
        do{
            Tree.insert(ipt);
        }
        while(cin>>ipt,ipt!=-1);
        Tree.print();
        cout<<endl;
    }
    return 0;
}
