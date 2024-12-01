//Author: 陳展皝 B123245006
//Date: Nov. 23, 2024
//Purpose: Compress and decompress file with huffman

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

class node{
    friend class toHfmTree;
    public:
        char symbol;
        int freq;
        bool real;
        node* left;
        node* right;

        node(char sb,int f,bool rl=false,node* l = NULL,node* r = NULL){
            symbol=sb;
            freq=f;
            real=rl;
            left=l;
            right=r;
        }
        node* operator+ (node& other){
            node* rt=new node(' ',freq+other.freq,false);
            if(symbol<other.symbol){
                rt->left=this;
                rt->right=&other;
            }
            else{
                rt->right=this;
                rt->left=&other;
            }
            rt->symbol=rt->left->symbol;
            return rt;
        }
};
void setbit(unsigned char& c,char bitvalue){
    c = static_cast<unsigned char>(c << 1);
    c|=(bitvalue=='0')?0:1;
}
void toBinary(map<char,string>& stringMap,node* root=NULL, string current = "") {
    if (root != nullptr) {
        if (root->right==NULL&&root->left==NULL){
            stringMap[root->symbol]=current;
            return;
        }
        if (root->right!=NULL){
            toBinary(stringMap,root->right,current+"1");
        }
        if(root->left!=NULL){
            toBinary(stringMap,root->left,current+"0");
        }
    }
}
static bool compare(const node* a, const node* b){
    return (a->freq!=b->freq)?a->freq < b->freq:a->symbol < b->symbol;
}
void compress(string inFileName,string outFileName){

    //input file to convert into binary

    //to store current use
    vector<node*> vec;
    //to store usage of each char
    map<char,int> freqMap;
    //to store each char binary
    map<char,string> stringMap;
    //input file
    ifstream inFile(inFileName,ios::binary);
    //go through file
    char c;
    while(inFile.get(c)){
        freqMap[c]+=1;
    }
    inFile.close();
    //push each into vector
    for(auto& one:freqMap){
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
    //store the only element in vec
    node* head;
    head=vec[0];
    //transform into binary
    toBinary(stringMap,head,"");

    //change to binary

    //reopen file
    inFile.open(inFileName,ios::binary);
    //file to output
    ofstream outFile(outFileName,ios::binary);
    string uncompress;
    while(inFile.get(c)){
        uncompress+=stringMap[c];
    }
    outFile<<uncompress.size()<<" "<<stringMap.size()<<endl;

    for(auto& one:stringMap){
        outFile<<one.first<<static_cast<unsigned char>(one.second.size())<<one.second;
    }
    outFile<<endl;
    unsigned char push='\0';
    int count=0;
    for(char one:uncompress){
        count+=1;
        setbit(push,one);
        if(count == 8){
            count = 0;
            outFile<<push;
            push = '\0';
        }
    }
    if(uncompress.size()%8!=0){
        for(size_t i=0;i<8-uncompress.size()%8;i++){
            setbit(push,'0');
        }
        outFile<<push;
    }

    inFile.close();
    outFile.close();
}

void decompress(string inFileName,string outFileName){
    map<string,char> charMap;
    size_t ogLen;
    string compressed;
    string uncompressed;
    ifstream inFile(inFileName,ios::binary);
    inFile>>ogLen;
    int mapSize;
    inFile>>mapSize;
    char c;
    char s;
    int sSize;
    char temp;
    string encode;
    //buffer
    inFile.get(c);
    for(int i=0;i<mapSize;i++){
        inFile.get(c);
        inFile.get(s);
        sSize=static_cast<int>(s);
        for(int j=0;j<sSize;j++){
            inFile.get(temp);
            encode+=temp;
        }
        charMap[encode]=c;
        encode.clear();
    }
    //buffer
    inFile.get(c);
    char ch;
    while(inFile.get(ch)){
        for(int i = 7; i >= 0; i--){
            compressed += ((ch & (1 << i)) ? '1' : '0');
        }
    }
    if(compressed.length() > ogLen){
        compressed = compressed.substr(0, ogLen);
    }
    string current_code;
    for(char bit : compressed){
        current_code += bit;
        auto it = charMap.find(current_code);
        if(it != charMap.end()){
            uncompressed += it->second;
            current_code.clear();
        }
    }
    ofstream out(outFileName,ios::binary);
    out<<uncompressed;
}

int main(int argc, char* argv[]) {
    if (argc == 6) {
        string mode = argv[1];
        string first = argv[2];
        string firstFileName = argv[3];
        string second = argv[4];
        string secondFileName = argv[5];

        if (mode == "-c") {
            if(first=="-i"&&second=="-o") compress(firstFileName, secondFileName);
            else if(first=="-o"&&second=="-i") compress(secondFileName, firstFileName);
            cout << "File compressed successfully." << endl;
        } else if (mode == "-u") {
            if(first=="-i"&&second=="-o") decompress(firstFileName, secondFileName);
            else if(first=="-o"&&second=="-i") decompress(secondFileName, firstFileName);
            cout << "File decompressed successfully." << endl;
        } else {
            cout << "Invalid mode. Use -c for compression and -u for decompression." << endl;
            return 1;
        }
    }
    else if(argc==4){
        string mode = argv[1];
        string firstName = argv[2];
        string secondName = argv[3];

        if(mode=="-c"){
            compress(firstName,secondName);
            cout<<"SUCCESS"<<endl;
        }
        else if(mode=="-u"){
            decompress(firstName,secondName);
            cout<<"SUCCESS"<<endl;
        }
        else{
            cout<<"INVALID"<<endl;
        }

    }
    else{
        cout << "Usage: " << argv[0] << " -c|-u -i<input_file> -o<output_file>" << endl;
        return 1;
    }

    return 0;
}