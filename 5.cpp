#include<iostream>
#include<string>
using namespace std;

template<class stuff>
class Total{
	stuff tings;
	stuff total;
	
public:
	
	stuff add(int size){
		for(int i=0; i<size;i++){
			cout<<"give thing " <<i+1 <<" : "; cin>>tings;
			total += tings;
		}
		return total;
	}
};

int main(){
	int size;
	
	double Dresult;
	char Cresult;
	string Sresult;
	
	cout<<"enter size: "; cin>>size;
	
	Total<double> foo;
	Dresult = foo.add(size);
	cout<<"Total: " <<Dresult <<endl;
	
	Total<string> foo1;
	Sresult = foo1.add(size);
	cout<<"Total: " <<Sresult <<endl;
	
	Total<char> foo2;
	Cresult = foo2.add(size);
	cout<<"Total: " <<Cresult <<endl;
	
	return 0;
}
