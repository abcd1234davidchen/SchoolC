#include<iostream>
#include<vector>

using namespace std;

struct country{
    int n;
    string s;
};

int main(){
    int times;
    cin>>times;
    string flush;
    getline(cin,flush);
    vector <country> vec;
    for(int j=0;j<times;j++){
        string ipt;
        getline(cin,ipt);
        string ctn;
        
        for(int i=0;i<ipt.size();i++){
            if(ipt[i]==' '){
                break;
            }
            else{
                ctn+=ipt[i];
            }
        }

        bool found = false;
        for(size_t i=0;i<vec.size();i++){
            if(vec[i].s==ctn){
                vec[i].n+=1;
                found = true;
                break;
            }
        }
        if(!found){
            country add;
            add.n = 1;
            add.s = ctn;
            vec.push_back(add);
        }
    }


    for(size_t i=0;i<vec.size();i++){
        for(size_t j=0;j<i;j++){
            if(vec[i].s<vec[j].s){
                swap(vec[i],vec[j]);
            }
        }
    }
    
    for(size_t i=0;i<vec.size();i++){
        cout<<vec[i].s<<" "<<vec[i].n<<endl;
    }

}
