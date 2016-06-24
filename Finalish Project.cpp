#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

void enterSugar();
void calcHemo();
void calcSugar();
void reviewSugar();
void onlineInfo();

using namespace std;
int main(int argc, char *argv[]) 

{

	int userAnswer = 0;
	int sugar;
	int sumSugar;
	int hemoglobin;



	do
	{
		cout << "Please choose what you would like to do." << endl << endl;
		cout << "1: Enter blood sugar." << endl;
		cout << "2: Calculate hemoglobin A1C." << endl;
		cout << "3: Calculate average blood sugar for all your entries." << endl;
		cout << "4: Review your blood sugar entries." << endl;
		cout << "5: To get more information online." << endl;
		cout << "(-1 to stop the program)" << endl;


		cin >> userAnswer;
		cin.ignore(100, '\n');
		cout << endl;

		if(userAnswer == 1)
		{
			enterSugar();
		}
		else if (userAnswer == 2)
		{
			calcHemo();
		}
		else if(userAnswer == 3)
		{
			calcSugar();
		}
		else if(userAnswer == 4)
		{
			reviewSugar();
		}
		else if(userAnswer == 5)
		{
			onlineInfo();
		}
		else
			cout << "What you entered is not of the above choices." << endl;
			



	} while(userAnswer != -1);




	return 0;
}

void enterSugar() //*****Start of enterSugar function*****
{
	//variables
	int sugar;
	int userAnswer;
	ofstream outFile;
	
	cout << "(-1 to go back to the previous menu.)" << endl;
	cout << "Enter blood sugar." << endl;
	
	while(userAnswer != -1)
	{
		outFile.open("bloodsugar.txt", ios::app);
		if(outFile.is_open())
		{
			cout << "Blood Sugar: ";
			cin >> sugar;
			if(sugar == -1)
			{
				userAnswer = -1;
				outFile.close();
			} // end if
			outFile << sugar << endl;
			cout << "Added " << sugar << " to your blood sugar file." << endl << endl;
		}// end if
		else
		cout << "File could not be opened." << endl;
		
		cout << "(-1 to go back to the previous menu.)" << endl;
		cout << "Enter blood sugar." << endl;
		outFile.close();
	} //end while
	
}//*****End of enterSugar function*****




void calcHemo()//*****Start of calcHemo function*****
{
	//variables for calcHemo function
	double hemoglobin = 0.0;
	int sugar = 0;
	int userAnswer = 0;
	int x = 0;
	ifstream inFile;
	
	
	cout << setprecision(2) << fixed;
	cout << "(-1 to go back to the previous menu.)" << endl;
	cout << "(2 to calculate your Hemoglobin A1C: ";
	cin >> userAnswer;
	
	if (userAnswer != -1 && userAnswer == 2)
	{
		inFile.open("bloodsugar.txt", ios::in);		
		if(inFile.is_open())
		{
						
			while (!inFile.eof())
			{
				inFile >> sugar;
				hemoglobin = hemoglobin + sugar;
				x = x + 1;
			}
			hemoglobin = (hemoglobin - sugar) / (x -1);
			if(hemoglobin <= 126)
			{
				cout << "Your approximate hemoglobin A1C is 6% or lower" << endl;
			}
			else if(hemoglobin > 126 && hemoglobin <= 154)
			{
				cout << "Your approximate hemoglobin A1C is 7%" << endl;
			}
			else if(hemoglobin > 154 && hemoglobin <= 183)
			{
				cout << "Your approximate hemoaglobin A1C is 8%" << endl;
			}
			else if(hemoglobin > 183 && hemoglobin <= 212)
			{
				cout << "Your approximate hemoglobin A1C is 9%" << endl;
			}
			else if(hemoglobin > 212 && hemoglobin <= 240)
			{
				cout << "Your approximate hemoglobin A1C is 10%" << endl;
			}
			else if(hemoglobin > 240 && hemoglobin <= 269)
			{
				cout << "Your approximate hemoglobin A1C is 11%" << endl;
			}
			else if(hemoglobin > 269 && hemoglobin <= 298)
			{
				cout << "Your approximate hemoglobin A1C is 12%" << endl;
			}
		}//end if
		else
			cout << "File could not be opened." << endl;
			cout << endl;			
			cout << "(-1 to go back to previous menu.)" << endl;
			cin >> userAnswer;
			inFile.close();
			
	}// end if
}//*****End of calcHemo function*****


void calcSugar()//*****Start of calcSugar function*****
{
	//variables for calcSugar function
	double hemoglobin = 0.0;
	int sugar = 0;
	int userAnswer = 0;
	int x = 0;
	ifstream inFile;
	
	
	cout << setprecision(2) << fixed;
	cout << "(-1 to go back to the previous menu.)" << endl;
	cout << "(3 to calculate your average blood sugar.) ";
	cin >> userAnswer;
	
	if (userAnswer != -1 && userAnswer == 3)
	{
		inFile.open("bloodsugar.txt", ios::in);		
		if(inFile.is_open())
		{
						
			while (!inFile.eof())
			{
				inFile >> sugar;
				hemoglobin = hemoglobin + sugar;
				x = x + 1;
			}
			hemoglobin = (hemoglobin - sugar) / (x -1);
			cout << "Your average blood sugar is: " << hemoglobin << endl;
		}// end if
		else
			cout << "File could not be opened." << endl;
			cout << endl;			
			cout << "(-1 to go back to previous menu.)" << endl;
			cin >> userAnswer;
			inFile.close();
			
	}// end if
}//*****End of calcSugar function*****

void reviewSugar()//*****Start of reviewSugar function*****
{
	//variables for reviewSugar function
	int sugar = 0;
	int userAnswer = 0;
	ifstream inFile;
	
	cout << "(-1 to go back to the previous menu.)" << endl;
	cout << "(4 to review your blood sugar entries.)" << endl;
	cin >> userAnswer;
	
	if(userAnswer != -1 && userAnswer == 4)
	{
		inFile.open("bloodsugar.txt", ios::in);
		if(inFile.is_open())
		{
			while(!inFile.eof())
			{
				
				cout << sugar << endl;
				if(sugar == 0)
				{
					cout << "Start of list." << endl;
					cout << "--------------" << endl;
				}	// end if			
				inFile >> sugar;

			}
			cout << "--------------" << endl;
		}// end if
	}//end if
	else
		cout << "File could not be opened." << endl;
		cout << endl;
		cout << "(-1 to go back to previous menu.)" << endl;
		cin >> userAnswer;
		inFile.close();
}//*****End of reviewSugar function*****


void onlineInfo() //*****Start of onlineInfo function*****
{
	int userAnswer = 0;
	
	cout << "(-1 to go back to the previous menu." << endl << endl;
	cout << "All the websites on this list are classified as peer reviewed." << endl;
	cout << "This means all the information has been tested and re-tested and then posted as accurately as possible." << endl;
	cout << "Please make a choice on what information you want." << endl << endl;
	
	
	cout << "1: Blood Sugar." << endl;
	cout << "2: Hemoglobin A1C." << endl;
	cout << "3: Diet and exercise." << endl;
	cout << "4: Type 1 diabetes." << endl;
	cout << "5: Type 2 diabetes." << endl;
	
	cin >> userAnswer;
	
	
	while(userAnswer != -1)
	{
		if(userAnswer == 1)
		{
			cout << "For more information on blood sugar go to:" << endl;
			cout << "http://www.diabetes.org/living-with-diabetes/treatment-and-care/blood-glucose-control/" << endl;
		}
		else if(userAnswer == 2)
		{
			cout << "For more information on your hemoglobin A1C go to:" << endl;
			cout << "http://www.niddk.nih.gov/health-information/health-topics/diagnostic-tests/a1c-test-diabetes/Pages/index.aspx" << endl;
		}
		else if(userAnswer == 3)
		{
			cout << "For more information on diet and exercise as a diabetic go to:" << endl;
			cout << "http://www.diabetes.org/food-and-fitness/" << endl;
		}
		else if (userAnswer == 4)
		{
			cout << "For specific information on diabetes type 1 go to:" << endl;
			cout << "http://www.diabetes.org/diabetes-basics/type-1/" << endl;
		}
		else if(userAnswer == 5)
		{
			cout << "For specific information on diabetes type 2 go to:" << endl;
			cout << "http://www.diabetes.org/diabetes-basics/type-2/" << endl;
		}//end if
		else
			cout << "What you entered is not in our system, please type one of the following." << endl;
			cout << endl;
			cout << "(-1 to go back to the previous menu." << endl << endl;
			cout << "1: Blood Sugar." << endl;
			cout << "2: Hemoglobin A1C." << endl;
			cout << "3: Diet and exercise." << endl;
			cout << "4: Type 1 diabetes." << endl;
			cout << "5: Type 2 diabetes." << endl;
			
			cin >> userAnswer;
	}//end while
	
	
}//*****End of onlineInfo function*****