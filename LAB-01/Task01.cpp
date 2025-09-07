#include<iostream>

using namespace std;

class BankAccount{
	double balance;
	public:
		BankAccount(){
			balance= 0.0;
			cout<< "Default Constructor"<<endl;
		}
		BankAccount(double bal){
			balance= bal;
			cout<< "Parametrized Constructor Called!"<<endl;
		}
		BankAccount(const BankAccount &obj1){
			balance= obj1.balance;
			
		}
		void deductBalance(double amnt){
			if(amnt<=balance){
				balance-=amnt;
				cout<< "Balance: $ "<<balance<<endl;
			}
			else{
				cout<< "Insufficiant Balance"<<endl;
			}
			cout<< "Copy Constructor Called!"<<endl;
		}
		void displayBalance(){
			cout<< " Account 2 Balance: $ "<<balance<<endl;
		}
};
int main(){
	BankAccount acc1;
	BankAccount acc2(1000.0);
	BankAccount acc3(acc2);
	acc3.deductBalance(200.0);
	acc2.displayBalance();
}
