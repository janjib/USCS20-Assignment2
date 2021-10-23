#include <iostream>
#include <iomanip>
#include <windows.h> 
using namespace std;

// function prototyping
void displayInformation();
string getSeatLocation(char c);
void getTickets(float price, int numTicket,int boxTicket,int pavilionTicket,int fancyTicket,int lawnTicket);

int main()
{
	// variable declaration
	char location;
	int numTickets, numTickets2, numTickets3, controller,boxTicket = 0, pavilionTicket = 0, fancyTicket = 0, lawnTicket = 0;
	float amount = 0,totalAmount = 0;
	
	// function to display general information such as instructions and prices
	system("Color 1F");
	displayInformation();
	
	// if the user enter negative number, it will reprompt
	// if the user enter alphabet, the program will end
	do
	{
		// prompt the user total numbers of ticket that he want to buy
		cout << "\nHow many total tickets would you like to buy: ";
	 	cin >> numTickets;
	}while(numTickets < 0);
	
	numTickets3 = numTickets;
	
	// if the user doesnt finish selecting the seats for all the tickets that he wishes to buy, continue looping
	while(numTickets >  0)
	{ 	
		cout << "-------------------------------------------------------------------------------------------------------" << endl;
		cout << "\n";
		// if user enter letter code that doesnt exist, keep prompting
		do
		{
			// prompt the letter code for seat location
			cout << "Enter the letter code of your preferred seat location: ";
			cin >> location;
		}while( location != 'B' && location != 'P' && location != 'F' && location != 'L');
		
		// if number of tickets left is 1, automatically assigned value 1 to numTickets2 (no need to prompt)
		if (numTickets == 1)
		{
			numTickets2 = 1;
		}
		else
		{
			// prompt the user the number of tickets that he want to buy for the preferred seat location
			cout << "How many tickets would you like to purchase for the seat(s) at " << getSeatLocation(location) << " : ";
			cin >> numTickets2;
		}
	
		if (numTickets2 > numTickets)
		{
			cout << "Ooops ! Do you ask for additional tickets ? Please start again !" << endl;
			return 0;
		}
		
			// calculate total price for each seat location
			/*if (location == 'B')
			{
				amount = numTickets2 * (200 * 0.8);
				boxTicket += numTickets2;
			}
			else if(location == 'P')
			{
				amount = numTickets2 * (150 * 0.85);
				pavilionTicket += numTickets2;
			}
			else if(location == 'F')
			{
				amount = numTickets2 * (75 * 0.9);
				fancyTicket += numTickets2;
			}
			else
			{
				amount = numTickets2 * (35 * 0.95);
				lawnTicket += numTickets2;
			}*/
			
			switch(location)
			{
				case 'B' :
					{
						amount = numTickets2 * (200 * 0.8);
						boxTicket += numTickets2;
						break;
					}
				case 'P' :
					{
						amount = numTickets2 * (150 * 0.85);
						pavilionTicket += numTickets2;
						break;
					}
					case 'F' :
					{
						amount = numTickets2 * (75 * 0.9);
						fancyTicket += numTickets2;
						break;
					}
					case 'L' :
					{
						amount = numTickets2 * (35 * 0.95);
						lawnTicket += numTickets2;
						break;
					}
			}
			// add amount of a seat location to total price
			totalAmount += amount;
		// determine numbers of ticket left to be purchased
		numTickets -= numTickets2;
		// remind the user about the numbers of ticket left
		cout << "\n" << numTickets << " left to be purchased" << endl;
		cout << "-------------------------------------------------------------------------------------------------------" << endl;
	}
	// display total price
	cout << "The price is RM " << setprecision(2) << fixed << totalAmount << endl;
	
	// function to display the total price and payment details in ticket form
	getTickets(totalAmount,numTickets3,boxTicket,pavilionTicket,fancyTicket,lawnTicket);
   
    return 0;
}

void displayInformation()
{
	cout << "Hi there! Welcoem to Brown Ticketing Automation System (BTAS)" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "__________________________    _________" << endl;
    cout << "\\______   \\__    ___ /  _  \\  /   _____/" << endl;
    cout << "  |    |  _/ |    | /  /_\\  \\ \\_____  \\ " << endl;
    cout << "  |    |   \\ |    |/    |    \\/        \\ " << endl;
    cout << "  |______  / |____|\\____|__  /_______  /" << endl;
    cout << "         \\/                \\/        \\/ " << endl;
    cout << "\n------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------" << endl;
    // display instructions
    cout << "Instruction" << endl;
    cout << "1. Enter the total number of tickets you want to purchase" << endl;
    cout << "2. Select your seat location using letter code. Please note that the input is case-sensitive" << endl;
    cout << "3. Enter the number of tickets for the seat location you have chosen earlier that you want to buy" << endl;
    cout << "4. The system will display the number of tickets you have purchased and number of tickets left for you to purchase." << endl;
    cout << "5. Step 2 until 4 will be repeated until you have purchased all the tickets." << endl;\
    // display ticket information
    cout << "\nTicket Information" << endl;
    cout << "----------------" << endl;
    cout << "| Seat Location\t|Letter Code\t|Ticket Price(RM)\t|Discount Rate" << endl;
    cout << "| Box          \t|B          \t|200             \t|20%" << endl;
    cout << "| Pavilion     \t|P          \t|150             \t|15%" << endl;
    cout << "| Fancy        \t|F          \t|75              \t|10%" << endl;
    cout << "| Lawn         \t|L          \t|35              \t|5%" << endl;
    cout << "------------------------------------------------------------" << endl;
}

// determine name of the seat based on character prompted
string getSeatLocation(char c)
{
	if (c == 'B')
	{
		return "Box";
	}
	else if(c == 'P')
	{
		return "Pavilion";
	}
	else if(c == 'F')
	{
		return "Fancy";
	}
	else
	{
		return "Lawn";
	}
}

// function containing ticket template
void getTickets(float price, int numTicket,int boxTicket,int pavilionTicket,int fancyTicket,int lawnTicket)
{
	cout << " _________________________________________________________________" << endl;
	cout << "|                      BROWN SCREEN CINEMAS                       | " << endl;
	cout << "|                                                                 | " << endl;
	cout << "|         Congratulations! Your tickets have been booked.         | " << endl;
	cout << "|                                                                 | " << endl;
	cout << "|   The details:  Box       " << boxTicket <<" seat(s)                             | " << endl;
	cout << "|                 Pavilion  " << pavilionTicket <<" seat(s)                             | " << endl;
	cout << "|                 Fancy     " << fancyTicket << " seat(s)                             | " << endl;
    cout << "|                 Lawn      " << lawnTicket << " seat(s)                            | " << endl;	
	cout << "|                                                                 | " << endl;
	cout << "|   Number of tickets booked : " << numTicket <<   "                                  | " << endl;
	cout << "|   Total amount             : RM " << setprecision(2) << fixed << price << "                           |" << endl;
	cout << "|                                                                 | " << endl;
	cout << "|                                                                 | " << endl;
	cout << " ----------------------------------------------------------------- " << endl;
}
