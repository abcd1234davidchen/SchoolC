#include<iostream>

using namespace std;

class payment{
	private:
		float amount;
	public:
		payment(){
			amount=0;
		}
		payment(float n){
			amount=n;
		}
		float getPay(){
			return amount;
		}
		void setPay(float n){
			amount=n;
		}
		void paymentDetail(){
			cout<<"payment amount is "<<amount<<endl;
		}
};

class CashPayment: public payment{
	public:
		CashPayment(float a):payment(a){}
		void paymentDetails(){
			cout<<"The cash ";
			payment::paymentDetail();
		}
};

class CreditCardPayment: public payment{
	private:
		string name;
		string date;
		string num;	
	public:
		CreditCardPayment(float a,string na,string d,string nu):payment(a),name(na),date(d),num(nu){}
		void paymentDetails(){
			cout<<"The credit card ";
			payment::paymentDetail();
			cout<<"Name on card "<<name<<endl;
			cout<<"Expiration date "<<date<<endl;
			cout<<"Credit card number "<<num<<endl;
		}
};

int main(){
	// Create several test classes and invoke the paymentDetails method
	CashPayment cash1(50.5), cash2(20.45);
	CreditCardPayment credit1(10.5, "Fred", "10/5/2010", "123456789");
	CreditCardPayment credit2(100, "Barney", "11/15/2009", "987654321");
	cout << "Cash 1 details:" << endl;
	cash1.paymentDetails();
	cout << endl;
	cout << "Cash 2 details: " << endl;
	cash2.paymentDetails();
	cout << endl;
	cout << "Credit 1 details:" << endl;
	credit1.paymentDetails();
	cout << endl;
	cout << "Credit 2 details:" << endl;
	credit2.paymentDetails();
	cout << endl;
	return 0;
}