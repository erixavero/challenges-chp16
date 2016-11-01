#include<iostream>
#include<string>

using namespace std;

class Date{
	int day= 1;
	int month= 1;
	int year= 1970;
	
	string monthName[12]= {"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
	"JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
	
public:
	date(int day, int month, int year);
	void printFirstForm();
	void printSecondForm();
	void printThirdForm();
	
	void setMonth(int m);
	void setDay(int d);
	void setYear(int y);
	
	class InvalidDay{};
	class InvalidMonth{};
};

	Date::date(int day, int month, int year){
		this->day = day;
		this->month = month;
		this->year = year; 
	}
	
	void Date::setDay(int d){
		if(d<=0 || d>31){
			throw InvalidDay();
		}
		else{
			day = d;
		}
	}
	
	void Date::setMonth(int m){
		if(m<=0 || m>12){
			throw InvalidMonth();
		}
		else{
		month = m;
		}
	}
	
	void Date::setYear(int y){
		year = y;
	}

	void Date::printFirstForm() {
	cout<<month <<" / " <<day <<" / " <<year;
}

	void Date::printSecondForm(){
		cout<<monthName[month-1] <<" " <<day <<", " <<year;
	}
	
	void Date::printThirdForm(){
		cout<<day <<" " <<monthName[month-1] <<" " <<year;
	}

int main() {
	
	Date newDate;
/*	
	newDate.date(23, 2, 2006);
	newDate.printFirstForm();
	cout<<endl;
	newDate.printSecondForm();
	cout<<endl;
	newDate.printThirdForm();
*/
	try
	{
	newDate.setDay(43);
	newDate.setMonth(2);
	newDate.setYear(2014);
	
	newDate.printFirstForm();
	cout<<endl;
	newDate.printSecondForm();
	cout<<endl;
	newDate.printThirdForm();
	}
	
	catch(Date::InvalidMonth){
		cout<< "Invalid month";
	}
	catch(Date::InvalidDay){
		cout<< "Invalid day";
	}
	
	return 0;
}
