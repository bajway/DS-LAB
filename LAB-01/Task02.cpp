#include<iostream>
#include<string.h>
using namespace std;

class Exam{
	char* name;
	char* examDate;
	float score;
	public:
		Exam(const char* sName, const char* date, float s){
			name= new char[strlen(sName+1)];
			strcpy(name, sName);
			examDate= new char[strlen(date+1)];
			strcpy(examDate, date);
			score= s;
		}
		~Exam(){
			delete[] name;
			delete[] examDate;
		}
		void displayDetails(){
			cout<< "Student Name: "<<name<<endl;
			cout<< "Exam Date: "<< examDate<<endl;
			cout<< "Score Achieved: "<< score<<endl;
		}
	
};
int main(){
	Exam e("Laghari Pan Shop", "03/09/2025", 55.75);
	e.displayDetails();
}
