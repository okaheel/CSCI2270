#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	bool primenumber[1000];

	int iterations = 0;

	for(int alltrue = 0; alltrue < 1000; alltrue++){
		primenumber[alltrue] = true;
	}

	for (int i = 2; i <1000; i++){ //number that we are checking 
		for (int j = (i+1); j < 1000; j++){ //number that we are checking against
			if( j%i == 0){
				primenumber[j] = false; // 
			}
		}
	}

	for (int x = 0; x < 1000; x++){
		//cout << x << " is prime: " << primenumber[x] << endl;
	}

	//fuction to read and store all numbers
	string input;

	ifstream myfile( "input.txt" );
	if (myfile) {
		while (getline(myfile, input)){
			bool status;
			int inputint = stoi(input);
			status = primenumber[inputint];
			if ( status == 0){
				cout << "The number " << inputint << " is not prime" <<endl;
			} else {
				cout << "The number " << inputint << " is prime" <<endl;
			}
		}
	} 

}
