/**********************************
** Program Filename: fileAdder.cpp
** Author: Reuben Youngblom
** Date: October 12th 2016
** Description: this program take input in the form of a filename. If filename is not there, program returns an error
by verifying input file in an 'if' loop. If file is found, program reads numbers, verifying each number with a while
loop. So long as numbers are present, program adds them via an accumulator. Program then writes total to an output
file called "sum.txt" and closes input and output files.
** Input: User specifies a filename
** Output: Program returns file (sum.txt) with sum of numbers contained in the file
**********************************/

#include <iostream>		//header
#include <fstream>
#include <string>
using namespace std;

int main ()			//main function
{

ifstream inputFile; //creates inout stream
string userFile;	//creates string to hold user-generated filename
double accumulator = 0.0;	//creates accumulator to keep running total of sum

cout << "Hello! Please type the name of the file you would like to open:" << endl;	//prompts user to specify filename
cin >> userFile;   //accepts user filename and sets to userFile string

inputFile.open (userFile.c_str());  //opens user file

if (inputFile)  //checks file: if inputFile is true, program continues
{
	double number;  //creates number as changable variable
	while (inputFile >> number)   //while loop: While numbers still exist in input file, run while loop.
		{
		accumulator += number;  //each loop iteration adds next number to running total in "accumulator"
		}


	ofstream outputFile;  //creates output stream
	outputFile.open ("sum.txt");   //creates file sum.txt

	cout << "writing..." << endl;    //lets user know file is writing
//	cout << accumulator << endl;    //used this line to test and visually see if correct output was being written to sum.txt
	
    outputFile << accumulator << endl;   //  writes total sum to output file (sum.txt)
    cout << "Success!" << endl;  //tells user that file writing is done
	outputFile.close ();   //closes input and output files
	inputFile.close ();
}

else   //what will happen if above "if" loop fails (i.e. if there's an error opening input file)
	{
		cout << "Could Not Access File..." << endl;  //prints error message
	}

return 0;
}

