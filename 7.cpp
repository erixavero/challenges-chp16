#include<iostream>
using namespace std;

class TestScores{
	double scores[];
	int size;
	double total;
	
public:
	
	TestScores(){};
	
	TestScores(double scores[], int size){
		this->size = size;
		
		for(int i=0; i<size; i++){
			this->scores[i] = scores[i];
		}
	}
	
	class InvalidScore{};
	
	double setScores(double scores[]){
		if(*scores<0 || *scores>100){
			throw InvalidScore();
		}
		else{
			for(int i=0; i<size; i++){
			this->scores[i] = scores[i];
		}
		}
	}
	
	double countTotal(){
		for(int i=0; i<size;i++){
			total += scores[i];
		}
		return total;
	}
	
	double getAvg(){
		return total/size;
	}
};

int main(){
	double scores[5];
	for(int i=0; i<5; i++){
		cout<<"Insert test score " <<i+1 <<": "; cin>>scores[i];
	}
	try{
	TestScores student(scores, 5);
	student.countTotal();
	cout<<"Average score: " <<student.getAvg();
	} 
	catch (TestScores::InvalidScore){
		cout<<"Invalid score";
	}
	
	return 0;
}
