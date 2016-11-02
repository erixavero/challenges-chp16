#include<iostream>
using namespace std;

class TestScores{
	double *aptr;
	int size;
	
public:
	
	TestScores(int size){
		this->size = size;
		aptr = new double [size];
		for(int i=0;i<size;i++){
			*(aptr + i) = 0;
		}
		
	};
	
	TestScores(TestScores &ting){
		this->size = ting.size;
		aptr = new double [size];
		for(int i=0; i<size; i++){
			*(aptr + i) = *(ting.aptr + i);
		}
	}
	
	class InvalidScore{};
	
	double setScores(TestScores &ting){
			for(int i=0; i<size; i++){
				if(*(ting.aptr + i)<0 || *(ting.aptr + i)>100){
					throw InvalidScore();
				}
				else{
				*(aptr + i) = *(ting.aptr + i);
				}
		}
		
	}
	
	double countAvg(){
		double total;
		for(int i=0; i<size; i++){
			total += *(aptr + i);
		}
		return total/size;
	}
	
	int operator[](int &arse){
		if(arse<0 || arse >= size){
			throw InvalidScore();
		}
		else{
			return aptr[arse];
		}
	}
};

int main(){
	int size= 5;
	double score;
	
	try{
	TestScores student(size);
	
	for(int i=0;i<size;i++){
		cout<<"Insert test score " <<i+1 <<": "; cin>>score;
		score = student[i];
	}
	
	cout<<"Average score: " <<student.countAvg();
	} 
	catch (TestScores::InvalidScore){
		cout<<"Invalid score";
	}
	
	return 0;
}
