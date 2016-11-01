#include<iostream>
using namespace std;

template<class stuff>
stuff abs(stuff num){
	if(num<0){
		return -num;
	}
	else{
		return num;
	}
}

int main(){
	int a= -3;
	cout<<a <<endl
		<<abs(a);
	
	return 0;
}
