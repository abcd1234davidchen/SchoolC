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
        node(int v,node* lft=nullptr,node* rht=nullptr):value(v),leftNode(lft),rightNode(rht){};
};

class tree{
    private:
        node* head;
    public:
        tree(){head = nullptr;}

        void insert(int n,node* current=nullptr){
            if(head==nullptr){
                head = new node(n);
                return;
            }
            if(current==nullptr){
                current = head;
            }
            if(current->value<n){
                if(current->rightNode!=nullptr){
                    insert(n,current->rightNode);
                }
                else{
                    current->rightNode = new node(n);
                }
            }
            else if(current->value>n){
                if(current->leftNode!=nullptr){
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
            if(head == nullptr) return;

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

            if(targ->leftNode==nullptr&&targ->rightNode==nullptr){
                if(prev==targ){
                    head=nullptr;
                }
                else if(prev->value>targ->value){
                    prev->leftNode=nullptr;
                }
                else if(prev->value<targ->value){
                    prev->rightNode=nullptr;
                }
                delete(targ);
            }
            else if(targ->leftNode==nullptr){
                if(prev==targ) head = targ->rightNode;
                else if(prev->value>targ->value){
                    prev->leftNode=targ->rightNode;
                }
                else if(prev->value<targ->value){
                    prev->rightNode=targ->rightNode;
                }
                delete(targ);
            }
            else if(targ->rightNode==nullptr){
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
                while(rplm->leftNode!=nullptr) rplm = rplm->leftNode;
                int rpmN = rplm->value;
                remove(rpmN);
                targ->value = rpmN;
            }
        }

        void print(node* current=nullptr,int mode = 0){
            if(mode==0){cout<<"VALUE: ";}
            if(current==nullptr) current=head;
            if(current->leftNode!=nullptr) print(current->leftNode,(mode==0?1:mode));
            if(current!=nullptr){
                if(mode==0||mode==1)cout<<setw(3)<<current->value;
                if(mode==2)cout<<setw(3)<<((current->leftNode!=nullptr)?current->leftNode->value:0);
                if(mode==3)cout<<setw(3)<<((current->rightNode!=nullptr)?current->rightNode->value:0);
            };
            if(current->rightNode!=nullptr) print(current->rightNode,(mode==0?1:mode));
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
