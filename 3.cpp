#include<iostream>
using namespace std;

template<class stuff>
stuff minimum(stuff a, stuff b){
	if(a<b){
		return a;
	}
	else{
		return b;
	}
}

template<class stuff>
stuff maximum(stuff c, stuff d){
	if(c>d){
		return c;
	}
	else{
		return d;
	}
}

int main(){
	double a= 10, b= 3, big, small;
	
	small = minimum(a,b);
	big = maximum(a,b);
	
	cout<<"bigger num: " <<big <<endl
		<<"smaller num: " <<small;
	
	return 0;
}
