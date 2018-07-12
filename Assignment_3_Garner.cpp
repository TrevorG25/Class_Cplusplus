//Assignment 3: Washington State Ferries
//Author: Trevor Garner
//Date: 7 / 12 / 2018
//Sources: Microsft Docs / Visual C++ / Documentation / C++ Language (https://docs.microsoft.com/en-us/cpp/cpp/if-else-statement-cpp)
/*					NOTES:	
*Total Fare (W/ Car)* = Passenger Fare + Vehicle Fare
*Total Fare (W/o Car)* = Passenger Fare + Bike Fare
*Passenger Fare* = Passenger Type x Number of Passengers per Type
*Bike Surcharge (~Car)* = Bike Surcharge x Number of Bikes 
*Vehicle Fare* = See comments: "Vehicle & Driver Fares" && "Long Vehicle Fares"
*/

#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

/////Function Declarations - Calculate Total Fares Due//////

double noCarFare(double, double, double, double);					//Calculates *Total Fare* for travellers W/O a car
double longOver72Fare(double, double, double, double);				//Calculates *Total Fare* for cars over 22 ft / under 30 && over 7 ft 2 inch
double longUnder72Fare(double, double, double, double);				//Calculates Total Fare for cars over 22 ft / under 30 && under 7ft 2 inch
double longOver30(double, double, double, double);					//Caclulates Total Fare for cars over 30 ft
double over14SeniorDriver(double, double, double, double);			//Calculates Total Fare for cars 14 ft to 22 ft W/ a Senior/Disabled driver
double under14SeniorDriver(double, double, double, double);			//Calculates Total Fare for cars under 14 ft W/ a Senior/Disabled driver
double over14RegDriver(double, double, double, double);				//Calculates Total Fare for cars 14 ft to 22 ft W/ a REGULAR driver
double under14RegDriver(double, double, double, double);			//Calculates Total Fare for cars under 14 ft W/ a REGULAR driver

/////Fares - Passenger & Bike Charges///////////////////

double regularFare = 13.25;				//Regular Fare
double seniorDisabledFare = 6.60;		//Senior/Disabled Fare
double youthFare = 6.60;				//Youth Fare
double bikeFare = 4.00;					//Bicycle Surcharge
double totalFare;						//Total Fare per Group

////Vehicle & Driver Fares - Including Driver//////////

double driver_under14 = 50.90;			//Under 14' + driver
double driver_btwn14_22 = 63.75;		//Over 14' and under 22' + driver
double driver_SD_under14 = 44.25;		//Under 14' with senior/disabled driver
double driver_SD_btwn14_22 = 57.10;		//14' and under 22' with senior/diabled driver

////Long Vehicle Fares - Including Driver//////////////

double lv2230_under7 = 98.70;			//Long vehicle 22'-30' and under 7'2"
double lv2230_over7 = 197.10;			//Long vehicle 22'-30' and over 7'2"
double lv30_under40 = 263.80;			//Long vehicle 30'-40' 

int main()
{
	/*Character Variables - If/Else Statements*/
	
	char car;							//Driving a car? (y/n)
	char driver_seniorDisabled;			//Senior/Disabled Driver? (y/n)
	char over72;						//Is car height over 7 feet, 2 inches? (y/n)

	/*Integer Variables - Total Fare Calculations*/
	
	/*Passengers*/
	double regular;
	double seniorDisabled;
	double youth;
	double bikes;
	
	/*Vehicle*/
	int carLength;
	
	
/////////////Begin Promt For Input///////////////////////

	cout << "Welcome to Trevor Garner's Fare Calculator\n"
		<< "Are you driving a vehicle onto the ferry? (y/n) ";
	cin >> car;
	
	if (car == 'n') /*No Car*/
	{
		cout << "How many Regular Fare Adults in your group? ";
		cin >> regular;
		cout << "How many Senior Citizens or Disabled persons in your group? ";
		cin >> seniorDisabled;
		cout << "How many Youths in your group? ";
		cin >> youth;
		cout << "How many bicycles? ";
		cin >> bikes;
		cout << "Your Total Fare is: $ "
			<< noCarFare(regular, seniorDisabled, youth, bikes)
			<< endl;
	}
	else		/*With Car*/
	{
		cout << "How long is your vehicle in feet? ";
		cin >> carLength;
		
		if (carLength >= 30)								//Car over 30 ft length
		{
			cout << "How many passengers in your vehicle? (excluding the driver)"
				<< "Regular Fare Adults:"
				<< endl;
			cin >> regular;
			cout << "Senior Citizens or Disabled:"
				<< endl;
			cin >> seniorDisabled;
			cout << "Youth: "
				<< endl;
			cin >> youth;
			cout << "Your Total Fare is: $"
				<< longOver30(lv30_under40, regular, seniorDisabled, youth);
		}
		else if (carLength >= 22 && carLength < 30)			//Car 22 ft to 30 ft in length
		{
			cout << "Is your vehicle over 7 feet, 2 inches in height?"
				<< endl;
			cin >> over72;

			if (over72 == 'y')		//Car over 7 ft 2 inch in height
			{
				cout << "How many passengers in your vehicle? (excluding the driver)"
					<< "Regular Fare Adults:"
					<< endl;
				cin >> regular;
				cout << "Senior Citizens or Disabled:"
					<< endl;
				cin >> seniorDisabled;
				cout << "Youth: "
					<< endl;
				cin >> youth;
				cout << "Your Total Fare is: $"
					<< longOver72Fare(lv2230_over7, regular, seniorDisabled, youth);
			}
			else		//Car under 7 ft 2 inch in height
			{
				cout << "How many passengers in your vehicle? (excluding the driver)"
					<< "Regular Fare Adults:"
					<< endl;
				cin >> regular;
				cout << "Senior Citizens or Disabled:"
					<< endl;
				cin >> seniorDisabled;
				cout << "Youth: "
					<< endl;
				cin >> youth;
				cout << "Your Total Fare is: $"
					<< longUnder72Fare(lv2230_under7, regular, seniorDisabled, youth);
			}
		}
		else if (carLength >= 14 && carLength < 22)			//Car 14 ft to 22 ft in length
		{
			cout << "Is the driver a Senior Citizen or Disabled? (y/n)"
				<< endl;
			cin >> driver_seniorDisabled;

			if (driver_seniorDisabled == 'y')		//Driver: Senior/Disabled
			{
				cout << "How many passengers in your vehicle? (excluding the driver)"
					<< "Regular Fare Adults:"
					<< endl;
				cin >> regular;
				cout << "Senior Citizens or Disabled:"
					<< endl;
				cin >> seniorDisabled;
				cout << "Youth: "
					<< endl;
				cin >> youth;
				cout << "Your Total Fare is: $"
					<< over14SeniorDriver(driver_SD_btwn14_22, regular, seniorDisabled, youth);
			}
			else									//Driver: Regular
			{
				cout << "How many passengers in your vehicle? (excluding the driver)\n"
					<< "\tRegular Fare Adults:"
					<< endl;
				cin >> regular;
				cout << "\tSenior Citizens or Disabled:"
					<< endl;
				cin >> seniorDisabled;
				cout << "\tYouth: "
					<< endl;
				cin >> youth;
				cout << "Your Total Fare is: $"
					<< over14RegDriver(driver_btwn14_22, regular, seniorDisabled, youth);
			}
		}
		else												//carLength < 14
		{
			cout << "Is the driver a Senior Citizen or Disabled? (y/n)"
				<< endl;
			cin >> driver_seniorDisabled;

			if (driver_seniorDisabled == 'y')		//Driver: Senior/Disabled
			{
				cout << "How many passengers in your vehicle? (excluding the driver)\n"
					<< "\tRegular Fare Adults: \n";
				cin >> regular;
				cout << "\tSenior Citizens or Disabled: \n";
				cin >> seniorDisabled;
				cout << "\tYouth: \n";
				cin >> youth;
				cout << "Your Total Fare is: $"
					<< under14SeniorDriver(driver_SD_under14, regular, seniorDisabled, youth);
			}
			else									//Driver: Regular
			{
				cout << "How many passengers in your vehicle? (excluding the driver)\n"
					<< "\tRegular Fare Adults: \n";
				cin >> regular;
				cout << "\tSenior Citizens or Disabled: \n";
				cin >> seniorDisabled;
				cout << "\tYouth: \n";
				cin >> youth;
				cout << "Your Total Fare is: $"
					<< under14RegDriver(driver_under14, regular, seniorDisabled, youth);
			}
		}
	}

	return 0;
}

/*Functions to calculate Total Fares due*/

double noCarFare(double reg, double senDis, double yth, double bike)
{
	double total;
	total = ( reg * regularFare ) + ( senDis * seniorDisabledFare ) + ( yth * youthFare ) + ( bike * bikeFare ) ;
	return total;
}

double longOver72Fare(double longOver72, double reg, double senDis, double yth)
{
	double total;
	total = longOver72 + ( reg * regularFare ) + ( senDis * seniorDisabledFare ) + ( yth * youthFare );
	return total;
}

double longUnder72Fare(double longUnder72, double reg, double senDis, double yth)
{
	double total;
	total = longUnder72 + ( reg * regularFare ) + ( senDis * seniorDisabledFare ) + ( yth * youthFare );
	return total;
}

double longOver30(double over30, double reg, double senDis, double yth)
{
	double total;
	total = over30 + ( reg * regularFare ) + ( senDis * seniorDisabledFare ) + ( yth * youthFare );
	return total;
}

double over14SeniorDriver(double senDisCar, double reg, double senDis, double yth)
{
	double total;
	total = senDisCar + ( reg * regularFare ) + ( senDis * seniorDisabledFare ) + ( yth * youthFare );
	return total;
}

double under14SeniorDriver(double senDisCar, double reg, double senDis, double yth)
{
	double total;
	total = senDisCar + ( reg * regularFare ) + ( senDis * seniorDisabledFare ) + ( yth * youthFare );
	return total;
}

double over14RegDriver(double regDriverFare, double reg, double senDis, double yth)
{
	double total;
	total = regDriverFare + ( reg * regularFare ) + ( senDis * seniorDisabledFare ) + ( yth * youthFare );
	return total;
}

double under14RegDriver(double regDriverFare, double reg, double senDis, double yth)
{
	double total;
	total = regDriverFare + ( reg * regularFare ) + ( senDis * seniorDisabledFare ) + ( yth * youthFare );
	return total;
}