#include<iostream>
using namespace std;

void purchase(char flavour[][15],int quantity[],int bought[],bool& cont){
    string oneItem;
    int quan,itemNum=-1;
    cin>>oneItem;
    if(oneItem!="-1"){
        cin>>quan;
        for(int i=0;i<5;i++){
            if(flavour[i]==oneItem){
                itemNum=i;
            }
        }
        if(itemNum!=-1){
            if(quantity[itemNum]>=quan){
                quantity[itemNum]-=quan;
                bought[itemNum]+=quan;
            }
            else{
                cout<<"NOT ENOUGH"<<endl;
            }
        }
    }
    else cont=false;
    
}

bool outOfStock(int quantity[]){
    for(int i=0;i<5;i++){
        if(quantity[i]!=0){
            return false;
        }
    }
    return true;
}

void render(char flavor[][15],int quan[]){
    for(int i=0;i<5;i++){
        cout<<flavor[i]<<" "<<quan[i]<<endl;   
    }
}

int main(){
    char flavor[5][15]={"Chocolate","Vanilla","Strawberry","Raspberry","Butterscotch"};
    int quantity[5]={20,15,15,20,20};
    int bought[5]={0};
    bool cont=true;
    render(flavor,quantity);
    cout<<endl;
    while(!outOfStock(quantity)&&cont){
        purchase(flavor,quantity,bought,cont);
        cout<<endl<<"Left"<<endl;
        render(flavor,quantity);
        cout<<endl;
    }
    cout<<"Bought"<<endl;
    render(flavor,bought);
    
}
