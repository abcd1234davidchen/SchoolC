#include<iostream>
#include<vector>
using namespace std;

class trivia{
    private:
        string question;
        string answer;
        int reward;
    public:
        trivia(string ques,string ans,int rew):question(ques),answer(ans),reward(rew){}
        int play(){
            string answered;
            cout<<question;
            cin>>answered;
            if(answer==answered) return reward;
            return 0;
        }
};

int main(){
    srand(time(0));
    int money=0;
    vector<trivia> trivias;
    trivias.push_back(trivia("one","two",5));
    trivias.push_back(trivia("three","four",5));
    trivias.push_back(trivia("five","six",5));
    trivias.push_back(trivia("seven","eight",5));
    trivias.push_back(trivia("nine","ten",5));

    money+=trivias[rand()%5].play();
    money+=trivias[rand()%5].play();
    cout<<money;
}
