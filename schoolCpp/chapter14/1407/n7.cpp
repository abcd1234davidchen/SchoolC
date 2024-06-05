#include <iostream>
#include <cstring>
using namespace std;
class Document{
	private:
		string text;
		
	public:
		Document(){
			text="";
		}
		Document(string t){
			text=t;
		}
		
		Document(Document &other){
			text=other.text;
		}
		
		string getText()const{
			return text;
		}
		
		void setText(string t){
			text=t;
		}
		
		Document operator=(Document &other){
            if(this==&other){
                return *this;
            }
			Document temp(other);
			return temp;
		}
};

class Email:public Document{
	private:
		string sender,recipient,title;
	public:
		Email():Document(){
			sender="";
			recipient="";
			title="";
		}
		
		Email(string text,string s,string r,string t):Document(text){
			sender=s;
			recipient=r;
			title=t;
		}
		
		Email(const Email &other){
            *this=other;
		}
		
		void setSender(string s){
			sender=s;
		}
		
		void setRecipient(string r){
			recipient=r;
		}
		
		void setTitle(string t){
			title=t;
		}
		
		string getSender(){
			return sender;
		}
		
		string getRecipient(){
			return recipient;
		}
		
		string getTitle(){
			return title;
		}
		
        Email& operator=(const Email &other){
            if (this != &other) { // 避免自我賦值
                // 假設 setText, sender, recipient, title 是 Email 類別的屬性或方法
                setText(other.getText());
                sender = other.sender;
                recipient = other.recipient;
                title = other.title;
            }
            return *this;
        }
};
bool ContainsKeyword(Document& docObject, string keyword) {
    if (docObject.getText().find(keyword) != string::npos)
        return true;
    return false;
}


int main(){
	Email email1("This is the body of the email.", "alice@example.com", "bob@example.com", "Meeting Schedule");
    Email email2(email1);
    cout << "Email 1 contains 'body': " << (ContainsKeyword(email1, "body") ? "Yes" : "No") << endl;
    cout << "Email 2 contains 'body': " << (ContainsKeyword(email2, "body") ? "Yes" : "No") << endl;
    return 0;
}
