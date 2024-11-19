//Author: 陳展皝 B123245006
//Date: Nov. 8, 2024
//Purpose: find numbers that appear odd times
#include <iostream>
#include <iomanip>
using namespace std;

class node{     //class for each node
    friend class tree;  //friend with tree
    private:
        int value;  //value of the node
        node* leftNode;     //node on left
        node* rightNode;    //node on right
    public:
        node(int v,node* lft=NULL,node* rht=NULL):value(v),leftNode(lft),rightNode(rht){};  //constructor for node
};

class tree{
    private:
        node* head;             //head node that connects others
    public:
        tree(){head = NULL;}    //constructor to set head to null

        void insert(int n,node* current=NULL){
            if(head==NULL){
                head = new node(n); //when head is null insert as head
                return;
            }
            if(current==NULL){
                current = head; //if current is null set to head
            }
            if(current->value<n){   //if the value is less than node
                if(current->rightNode!=NULL){   //recursive to right if possible
                    insert(n,current->rightNode);
                }
                else{
                    current->rightNode = new node(n);   //else set as new node at right
                }
            }
            else if(current->value>n){  //if the value is more than node
                if(current->leftNode!=NULL){    //recursive to left if possible
                    insert(n,current->leftNode);
                }
                else{
                    current->leftNode = new node(n);    //else set as new node at left
                }
            }
            else{
                remove(n);  //if the value is the same remove it
            }
            return;
        }

        void remove(int n){
            if(head == NULL) return;    //case of nothing in tree

            node* prev = head;          //previous node
            node* targ = head;          //the node that is the target to remove
            while(targ->value!=n){      //when the value is not n continue
                prev=targ;              //set previous to target
                if(targ->value>n){      //make target go find the next one based on value
                    targ=targ->leftNode;
                }
                else if(targ->value<n){
                    targ=targ->rightNode;
                }
            }

            if(targ->leftNode==NULL&&targ->rightNode==NULL){    //the target has no left and right node
                if(prev==targ){     //if both are the same value its the head
                    head=NULL;      //set to null to remove head
                }
                else if(prev->value>targ->value){
                    prev->leftNode=NULL;    //wipe the connection between previous and target
                }
                else if(prev->value<targ->value){
                    prev->rightNode=NULL;   //wipe the connection between previous and target
                }
                delete(targ);       //remove the target node
            }
            else if(targ->leftNode==NULL){  //if the target has only right node
                if(prev==targ) head = targ->rightNode;  //if head set head to right node
                else if(prev->value>targ->value){   //change the connection to connect prev to right node
                    prev->leftNode=targ->rightNode;
                }
                else if(prev->value<targ->value){   //change the connection to connect prev to right node
                    prev->rightNode=targ->rightNode;
                }
                delete(targ);
            }
            else if(targ->rightNode==NULL){ //if the target has only left node
                if(prev==targ) head = targ->leftNode;   //if head set head to right node
                else if(prev->value>targ->value){   //change the connection to connect prev to right node
                    prev->leftNode=targ->leftNode;
                }
                else if(prev->value<targ->value){   //change the connection to connect prev to right node
                    prev->rightNode=targ->leftNode;
                }
                delete(targ);
            }
            else{   //if the target has both right and left node
                node* rplm = targ->rightNode;   //find the inorder successor by going right first
                while(rplm->leftNode!=NULL) rplm = rplm->leftNode;  //go to the most left
                int rpmN = rplm->value; //keep track of the replacement
                remove(rpmN);   //use recurssion to remove the replacement
                targ->value = rpmN; //set the value of target to the replacement
            }
        }

        void print(node* current=NULL,int mode = 0){    //print function to with mode to switch
            if(mode==0){cout<<"node:";}   //if the mode is 0 print "node:"
            if(current==NULL) current=head; //if the current is head set to print head
            if(current->leftNode!=NULL) print(current->leftNode,(mode==0?1:mode));  //print left subtree and if the mode is 0 switch to 1
            if(current!=NULL){
                if(mode==0||mode==1)cout<<" "<<current->value;  //if 0 or 1 print current
                if(mode==2)cout<<" "<<((current->leftNode!=NULL)?current->leftNode->value:0);   //if mode is 2 print left
                if(mode==3)cout<<" "<<((current->rightNode!=NULL)?current->rightNode->value:0); //if mode is 3 print right
            };
            if(current->rightNode!=NULL) print(current->rightNode,(mode==0?1:mode));//print right subtree and if the mode is 0 switch to 1
            if(mode==0) {   //only if the mode is 0, which means that it is the one not in recursion
                cout<<endl;
                cout<<"left:";
                print(head,2);  //print left subtree
                cout<<endl;
                cout<<"right:";
                print(head,3);  //print right subtree
            }
        }

};

int main() {
    int ipt;    //int for input
    bool notFirst = false;  //to identify if it is first
    while(cin>>ipt){    //input and break point for EOF
        if(notFirst) cout<<endl;    //print endl between different output
        notFirst = true;
        tree Tree;  //set a new tree
        do{
            Tree.insert(ipt);   //input to tree
        }
        while(cin>>ipt,ipt!=-1);    //new ipt if not -1
        Tree.print();   //output the tree after tree ended
        cout<<endl; //a endl for new input
    }
}
