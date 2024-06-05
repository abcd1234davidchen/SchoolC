#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string generalSuits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
string generalValues[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};


class card{
    private:
        int suit;
        int value;
    public:
        card(int s, int v){
            suit = s;
            value = v;
        }
        string getSuit(){
            return generalSuits[suit];
        }
        int getPoint()const{
            return suit*13+value;
        }
        string getValue(){
            return generalValues[value];
        }
        int getValueint(){
            return value+1;
        }
        void display(){
            cout<<getValue()<<" of "<<getSuit()<<endl;
        }
        void setCard(int s, int v){
            suit = s;
            value = v;
        }
        void setSuit(int s){
            suit = s;
        }
        void setValue(int v){
            value = v;
        }
        bool operator<(const card& d)const{
            return getPoint() < d.getPoint();
        }
};

class deck{
    protected:
        vector<card> cards;
    public:
        deck(){
            for(int i=0; i<4; i++){
                for(int j=0; j<13; j++){
                    card temp(i,j);
                    cards.push_back(temp);
                }
            }
        }
        void display(){
            for(size_t i=0; i<cards.size(); i++){
                cards[i].display();
            }
        }
        int cardAdd(){
            int total = 0;
            for(size_t i=0; i<cards.size(); i++){
                total+=cards[i].getValueint();
            }
            return total;
        }
        void shuffle(){
            for(size_t i=0; i<cards.size(); i++){
                size_t random = rand() % cards.size();
                card temp = cards[i];
                cards[i] = cards[random];
                cards[random] = temp;
            }
        }
        card deal(){
            card temp = cards.back();
            cards.pop_back();
            return temp;
        }
        void sort(){
            std::sort(cards.begin(), cards.end());
        }
};

class hand : public deck{
    public:
        hand(){
            cards.clear();
        }
        void addCard(card c){
            cards.push_back(c);
        }
};

int main(){
    srand(time(0));
    deck d;
    d.shuffle();
    hand host;
    hand a;

    host.addCard(d.deal());
    a.addCard(d.deal());
    host.addCard(d.deal());
    a.addCard(d.deal());

    a.display();
    cout<<"continue?"<<endl;
    host.display();
    cout<<"HOST"<<endl;
    string s;
    cin>>s;
    if(s=="yes"){
        a.addCard(d.deal());
        cout<<"You have"<<endl;
        a.display();
    }
    if(a.cardAdd()>21){
        cout<<"Bust"<<endl;
    }
    else{
        //host.display();
        while(host.cardAdd()<17){
            host.addCard(d.deal());
        }
        host.display();
        if(host.cardAdd()>21){
            cout<<"You win"<<endl;
        }
        else if(host.cardAdd()>a.cardAdd()){
            cout<<"You lose"<<endl;
        }
        else{
            cout<<"You win"<<endl;
        }
    }
}
