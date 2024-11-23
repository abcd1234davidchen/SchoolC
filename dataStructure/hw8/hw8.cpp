#include <iostream>
#include <vector>
#include <map>
using namespace std;

class node{
    friend class hfmTree;
    private:
        char symbol;
        int freq;
        bool real;
        node* left;
        node* right;
    public:
        node(char sb,int f,bool rl=false,node* l = NULL,node* r = NULL){
            symbol=sb;
            freq=f;
            real=rl;
            left=l;
            right=r;
        }
        node* operator+ (node& other){
            node* rt=new node(' ',freq+other.freq,false);
            if(symbol>other.symbol){
                rt->left=this;
                rt->right=&other;
            }
            else{
                rt->right=this;
                rt->left=&other;
            }
            return rt;
        }
};

class hfmTree{
    private:
        node* head;
        vector<node*> vec;
        map<char,int> mp;
    public:
        hfmTree(){
            head = NULL;
        }

        void in(char c){
            mp[c]+=1;
        }
        void in(char c,int f){
            mp[c]=f;
        }

        static bool compare(const node* a, const node* b){
            return a->freq < b->freq;
        }
        void toTree(){
            //mp to vec
            for(auto& one:mp){
                vec.push_back(new node(one.first,one.second,true));
            }
            //sort vec
            sort(vec.begin(), vec.end(), compare);
            //put nodes together until one
            while(vec.size()>1){
                vec.push_back(*(vec[0])+ *(vec[1]));
                vec.erase(vec.begin());
                vec.erase(vec.begin());
                sort(vec.begin(),vec.end(),compare);
            }
            //point head to the only thing
            head=vec[0];
        }

        void printTree(node* root=NULL, string indent = "", bool last = true) {
            if(root==NULL){
                root=head;
            }
            if (root != nullptr) {
                cout << indent;
                if (last) {
                    cout << "R----";
                    indent += "     ";
                } else {
                    cout << "L----";
                    indent += "|    ";
                }
                cout << root->symbol << "(" << root->freq << ")" << endl;
                if(root->left!=NULL)printTree(root->left, indent, false);
                if(root->right!=NULL)printTree(root->right, indent, true);
            }
        }

};

int main(){
    hfmTree tree;
    tree.in('A', 3);
    tree.in('B', 2);
    tree.in('C', 3);
    tree.in('D', 1);

    tree.toTree();
    tree.printTree();

    return 0;
}