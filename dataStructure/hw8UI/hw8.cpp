//Author: 陳展皝 B123245006
//Date: Nov. 23, 2024
//Purpose: Compress and decompress file with huffman

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip> 
using namespace std;

class node{
    public:
        char symbol;    //symbol of the char
        int freq;       //frequency of char
        bool real;      //real or not
        node* left;     //left node
        node* right;    //right node

        node(char sb,int f,bool rl=false,node* l = NULL,node* r = NULL){
            symbol=sb;  //constructor of node
            freq=f;
            real=rl;
            left=l;
            right=r;
        }

        node* operator+ (node& other){  //The operator for two node to add up
            node* rt=new node(' ',freq+other.freq,false);
            if(symbol<other.symbol){    //set the smaller node to be the left node
                rt->left=this;          //and the bigger node to be the right one
                rt->right=&other;
            }
            else{
                rt->right=this;
                rt->left=&other;
            }
            rt->symbol=rt->left->symbol;    //Set the symbol to be the smaller one
            return rt;
        }
};
void setbit(unsigned char& c,char bitvalue){    
    c = static_cast<unsigned char>(c << 1); //push back the char for one
    c|=(bitvalue=='0')?0:1;     //make LSB 0 or 1
}
void toBinary(map<char,string>& stringMap,node* root=NULL, string current = "") {
    if (root != nullptr) {  //check if root is NULL
        if (root->right==NULL&&root->left==NULL){
            stringMap[root->symbol]=current;    //If meet real node add to map
            return;
        }
        if (root->right!=NULL){
            toBinary(stringMap,root->right,current+"1");    //go left
        }
        if(root->left!=NULL){
            toBinary(stringMap,root->left,current+"0");     //go right
        }
    }
}
static bool compare(const node* a, const node* b){  //compare for custom sort
    return (a->freq!=b->freq)?a->freq < b->freq:a->symbol < b->symbol;
}
void compress(string inFileName,string outFileName){

    //input file to convert into binary

    vector<node*> vec; //to store current use
    map<char,int> freqMap;  //to store usage of each char
    map<char,string> stringMap; //to store each char binary
    ifstream inFile(inFileName,ios::binary);    //input file
    //go through file
    char c; //The char to go through
    int ogCharCount=0;  //count of character
    while(inFile.get(c)){   //Get char from file
        freqMap[c]+=1;      //add to frequency map
        ogCharCount+=1;     //add to count
    }
    inFile.close();
    for(auto& one:freqMap){ //push map to vector
        vec.push_back(new node(one.first,one.second,true));
    }
    sort(vec.begin(), vec.end(), compare);  //sort vec
    while(vec.size()>1){ //put nodes together until one
        vec.push_back(*(vec[0])+ *(vec[1])); //push back the combined node
        vec.erase(vec.begin()); //remove first two node
        vec.erase(vec.begin());
        sort(vec.begin(),vec.end(),compare);//sort it again
    }
    node* head;
    head=vec[0]; //store the only element in vec
    if(freqMap.size()==1){ //transform into binary
        toBinary(stringMap,head,"0");   //case of only one kind of element
    }
    else{
        toBinary(stringMap,head,"");
    }
    inFile.open(inFileName,ios::binary); //reopen file
    ofstream outFile(outFileName,ios::binary); //file to output
    string uncompress;  //the uncompressed string
    while(inFile.get(c)){   //Change the input to binary string
        uncompress+=stringMap[c];
    }
    int compressFull=static_cast<int>(uncompress.size())/8+(uncompress.size()%8!=0);  //the size of outputstring
    compressFull+=static_cast<int>(ceil(log10(ogCharCount)));       //size of og char count
    compressFull+=9;    //space and endl
    for(auto& one:stringMap){   //Add code map size
        compressFull+=2;    //char and size
        compressFull+=(one.second.size());  //the string
    }
    compressFull+=static_cast<int>(ceil(log10(uncompress.size()))); //The size of uncompressed
    compressFull+=static_cast<int>(ceil(log10(stringMap.size())));  //The size of string map
    compressFull+=static_cast<int>(ceil(log10(floor(ogCharCount*1.0/compressFull*100))));   //the size of ratio
    int compressFullLength=static_cast<int>(ceil(log10(compressFull))); //The size of compressed
    compressFull+=compressFullLength;
    if((static_cast<int>(ceil(log10(compressFull)))+compressFull)==compressFull)compressFull+=1; //Case of compressed size increase as the compressed size increase

    cout<<"Original Size "<<ogCharCount<<endl;  //Output the header file
    cout<<"Compressed Size "<<compressFull<<endl;
    cout<<setprecision(2)<<fixed<<"Ratio "<<ogCharCount*1.0/compressFull*100<<"%"<<endl;
    //Output the header to file
    outFile<<ogCharCount<<" "<<compressFull<<" "<<setprecision(2)<<fixed<<ogCharCount*1.0/compressFull*100<<" "<<uncompress.size()<<" "<<stringMap.size()<<endl;
    for(auto& one:stringMap){   //Output the map
        outFile<<one.first<<static_cast<unsigned char>(one.second.size())<<one.second;
        cout<<static_cast<int>(one.first)<<":"<<one.second<<endl;
    }
    outFile<<endl;
    unsigned char push='\0';
    int count=0;
    for(char one:uncompress){
        count+=1;
        setbit(push,one); //push 0/1 to LSB
        if(count == 8){   //when counter is 8
            count = 0;    //reset counter
            outFile<<push;//push to file
            push = '\0';  //reset to 0
        }
    }
    if(uncompress.size()%8!=0){ //push 0 to fill up
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
    size_t uncmp;   //uncompressed size
    size_t cpres;   //compressed size
    size_t ogLen;   //length of compressed string
    double ratio;   //ratio of compression
    string compressed;  //compressed string
    string uncompressed;    //uncompressed
    ifstream inFile(inFileName,ios::binary);//the file
    int mapSize;    //size of map
    inFile>>uncmp>>cpres>>ratio>>ogLen>>mapSize; //read the header
    cout<<"Original Size "<<uncmp<<endl; //output the header
    cout<<"Compressed Size "<<cpres<<endl;
    cout<<setprecision(2)<<fixed<<"Ratio "<<ratio<<"%"<<endl;
    char c; //the char
    char s; //the length of string
    int sSize; //convert s to int
    char temp; //temp to read
    string encode; //map of string
    inFile.get(c); //buffer
    for(int i=0;i<mapSize;i++){ //read map
        inFile.get(c);
        inFile.get(s);
        sSize=static_cast<int>(s);
        for(int j=0;j<sSize;j++){
            inFile.get(temp);
            encode+=temp;
        }
        charMap[encode]=c; //read char and map the string
        encode.clear(); //clear the string
    }
    inFile.get(c); //buffer
    char ch; //char
    while(inFile.get(ch)){  //read char from file
        for(int i = 7; i >= 0; i--){ //extract the char to 8 bit
            //push 1 to i position then do 'and' procedure
            compressed += ((ch & (1 << i)) ? '1' : '0');
        }
    }
    if(compressed.length() > ogLen){    //trim the length of string
        compressed = compressed.substr(0, ogLen);
    }
    string current_code; //string to compare
    for(char bit : compressed){
        current_code += bit; //add read to string
        auto it = charMap.find(current_code);   //try to find in map
        if(it != charMap.end()){ //if found
            uncompressed += it->second; //add to uncompressed
            current_code.clear(); //clean out current
        }
    }
    ofstream out(outFileName,ios::binary);  //Open a new file
    out<<uncompressed;  //output the uncompressed
    inFile.close();
    out.close();
}

int main(int argc, char* argv[]) {
    if (argc == 6) {    //behavior as requested
        string mode = argv[1];
        string first = argv[2];
        string firstFileName = argv[3];
        string second = argv[4];
        string secondFileName = argv[5];

        if (mode == "-c") { //compress
            if(first=="-i"&&second=="-o") compress(firstFileName, secondFileName);  //i for input o for output
            else if(first=="-o"&&second=="-i") compress(secondFileName, firstFileName); //ability to swap i/o
            cout << "File compressed successfully." << endl;
        } else if (mode == "-u") {  //decompress
            if(first=="-i"&&second=="-o") decompress(firstFileName, secondFileName); //i for input o for output
            else if(first=="-o"&&second=="-i") decompress(secondFileName, firstFileName);//ability to swap i/o
            cout << "File decompressed successfully." << endl;
        } else {    //faulty arguements
            cout << "Invalid mode. Use -c for compression and -u for decompression." << endl;
            return 1;
        }
    }
    else if(argc==4){   //shorter input with only -c and -u
        string mode = argv[1];
        string firstName = argv[2];
        string secondName = argv[3];

        if(mode=="-c"){
            compress(firstName,secondName);
            cout<<"COMPRESS SUCCESS"<<endl;
        }
        else if(mode=="-u"){
            decompress(firstName,secondName);
            cout<<"DECOMPRESS SUCCESS"<<endl;
        }
        else{
            cout<<"INVALID"<<endl;
        }

    }
    else{   //for debug use
        cout << "~~DEMO RUN~~" <<endl<<endl;
        compress("input.txt","ipt.txt");
        cout<<endl<<"COMPRESS SUCCESS"<<endl<<endl;
        decompress("ipt.txt","ipt2.txt");
        cout<<endl<<"DECOMPRESS SUCCESS"<<endl<<endl;
        cout << "Usage: " << argv[0] << " -c|-u -i <input_file> -o <output_file>" << endl;
        return 0;
    }

    return 0;
}