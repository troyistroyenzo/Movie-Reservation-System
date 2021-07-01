


// THANKS FOR WATCHING!!!

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include<ctime>
using namespace std;

//Function Declaration
char getMenu();
char getAdmin(); 
char getLogin(); 
char checkTicket(); 
char getCreditcard(); //Optional Function

char addMovie(); //Function that allows the user to Change or Add Movies
char getSeats();
char buyTickets();
char viewReservedTix();
char viewReservedSeats();

int ticketHolder[1200]; //Holds the value of all the tickets from CinemaOne1-6 and cinemaTwo1-6
string movieC1[6]={"Spider Man","Avengers","Thor","Iron Man","Hulk","Captain America"}; //Holds the movies For Cinema 1
string movieC2[6]={"Batman","Joker","Superman","Unassigned","Unassigned","Unassigned"}; //Holds the movies For Cinema 2
string movieTime[6]={"11:00 AM"," 1:00 PM"," 3:00 PM"," 5:00 PM"," 7:00 PM"," 9:00 PM"}; //Holds the Time for the movies. -- Currently Unchangeable
string name[1200],lname[1200],email[1200]; //Holds the name of all names and email addresses inputted.
double price[12]={280,310,270,285,285,295,270,310,290,300,295,320}; //Movie Prices 1-12 ; From left to right.
char creditCard[16]; //Holds 16 characters for the credit card.
int cinemaOne1[100],cinemaOne2[100],cinemaOne3[100],cinemaOne4[100],cinemaOne5[100],cinemaOne6[100]; //Cinema seats for Each Scheduled Movie
int cinemaTwo1[100],cinemaTwo2[100],cinemaTwo3[100],cinemaTwo4[100],cinemaTwo5[100],cinemaTwo6[100];

//Value Assign Function
int valueAssign() //Optional Function
{
	int ctr=0;
	while(ctr!=100)
	{
		cinemaOne1[ctr]=0;
		cinemaOne2[ctr]=0;
		cinemaOne3[ctr]=0;
		cinemaOne4[ctr]=0;
		cinemaOne5[ctr]=0;
		cinemaOne6[ctr]=0;
		cinemaTwo1[ctr]=0;
		cinemaTwo2[ctr]=0;
		cinemaTwo3[ctr]=0;
		cinemaTwo4[ctr]=0;
		cinemaTwo5[ctr]=0;
		cinemaTwo6[ctr]=0;
		ctr++;
	}
	ctr=0;
	while(ctr!=1200);
		{
			ticketHolder[ctr]=0;
			ctr++;
		}
}

//Global Declaration
char choice,adminChoice;
int adminconf;
int goBack;
string userN,userP,userNconf="Admin",userPconf="1234";
int ctr=0;
int chosenMovie,chosenSeat;
char creditCheck='0';
char goBack_1;

int main()
{
	//declaration
	int valueAssign();
	
	//executable
    do{
    	system("cls");
        goBack=0;
        getMenu();
        
        switch(choice)
        {
            case '1': //Show Movies
            {
            	system("cls");
            		cout<<"Now Showing:"<<endl
                    <<" Time:     [Cinema 1]     [Cinema 2]"<<endl
                    <<movieTime[0]<<" : "<<movieC1[0]<<setw(5)<<" "<<movieC2[0]<<endl
                    <<movieTime[1]<<" : "<<movieC1[1]<<setw(7)<<" "<<movieC2[1]<<endl
                    <<movieTime[2]<<" : "<<movieC1[2]<<setw(11)<<" "<<movieC2[2]<<endl
                    <<movieTime[3]<<" : "<<movieC1[3]<<setw(7)<<" "<<movieC2[3]<<endl
                    <<movieTime[4]<<" : "<<movieC1[4]<<setw(11)<<" "<<movieC2[4]<<endl
                    <<movieTime[5]<<" : "<<movieC1[5]<<setw(3)<<" "<<movieC2[5]<<endl; 
            }
                break;
                
            case '2': //Directs to Log-in Screen with Function getLogin()
            {
                    getLogin();
                    
                    if(adminconf==1)
                    {
                        do{ //Enables the user to go back to the previous menu as long as goBack==1
                        getAdmin();
                        
                        switch(adminChoice)
                        {
                            case '1': //Movies
                            {
                                do{ //Enables user to go back to Previous Menu.
                                addMovie(); //addmovies or change movies currently airing.
                                }while(goBack==0);
                            }
                                break;
                                
                            case '2': //Allows user to View Reserved Seats
                            {
                                viewReservedSeats();
                            }
                                break;
                                
                            case '3': //View list of Bought Tickets
                            {
                            		viewReservedTix();
                            }
                                break; //Sign-out
                                
                            case '4':
                            {
                                goBack=0;
                            }
                                break;
                                
                        }
                        }while(goBack==1); 
                    }
            }
                break;
            case '3': //Allows user to Look-up Ticket
            {
                checkTicket();
            }
                break;
            case '4': //Allows user to buy Ticket
            {
            	do{
            		buyTickets();
				}while(goBack==1);
                goBack=1;
            }
            	break;
            case '5': //Exit 
                exit(0); //Immediately Exits -- Redundant code
                break;
        }
            do{ //Confirms If the user wants to go back to the Main Menu; if Yes, code loops back, if no. Immediately Exits.
            cout<<"Do you want to go Back to the Main Menu? (Y/N): ";
            cin>>choice;
            if(choice=='Y'||choice=='y')
            {
                goBack=1;
                cout<<"test"<<endl;
                break;
            }
            if(choice=='N'||choice=='n')
                goBack=0;
            }while(goBack==1);
    }while(goBack==1);
}
//-----------------------------------//
char viewReservedTix() //Function that holds the code that allows the user to view list of Reserved Tickets.
{
	
	//declaration
    int ctr=0;
    
    //Executable
    system("cls");
    cout<<"List of Bought Tickets:"<<endl;
	do{ //Loops 1200 times to check all the values inside the ticketHolder[1200] variable.		
                if(ticketHolder[ctr]>0) //Checks if the ticketHolder[#] has a ticket store inside. if TicketHolder[#] is greater than 0 (0 is assigned by the value assign function), it means it has a ticket
                {
                	cout<<"Name:"<<name[ctr]<<" "<<lname[ctr]<<endl; //Prints First and Last name stored in the string with the corresponding ticket number. 
                cout<<"Ticket No. "<<ticketHolder[ctr]<<endl; //Outputs the value inside the ticketHolder[#]
                cout<<"Seat No. "<<ctr<<endl;
                    if(ctr>=0&&ctr<100) //If Value is 0-99 ; outputs current movie stored in movieC1[0]
                    {
				cout<<"Movie:"<<movieC1[0]<<endl
                    <<"Time Start: "<<movieTime[0]<<endl<<endl;
            		}
            		else if(ctr>=100&&ctr<200) //If Value is 100-199 ; outputs current movie stored in movieC1[1]
            		{
				cout<<"   Movie:"<<movieC1[1]<<endl
                    <<"   Time Start: "<<movieTime[1]<<endl<<endl;
            		}
            		else if(ctr>=200&&ctr<300) //If Value is 200-299 ; outputs current movie stored in movieC1[2]
            		{
				cout<<"   Movie:"<<movieC1[2]<<endl
                    <<"   Time Start: "<<movieTime[2]<<endl<<endl;
            		}
            		else if(ctr>=300&&ctr<400) //If Value is 300-399 ; outputs current movie stored in movieC1[3]
            		{
				cout<<"   Movie:"<<movieC1[3]<<endl 
                    <<"   Time Start: "<<movieTime[3]<<endl<<endl;
            		}
            		else if(ctr>=400&&ctr<500) //If Value is 400-499 ; outputs current movie stored in movieC1[4]
            		{
				cout<<"   Movie:"<<movieC1[4]<<endl 
                    <<"   Time Start: "<<movieTime[4]<<endl<<endl;
            		}
            	else if(ctr>=500&&ctr<600) //If Value is 500-599 ; outputs current movie stored in movieC1[5]
            		{
				cout<<"   Movie:"<<movieC1[5]<<endl
                    <<"   Time Start: "<<movieTime[5]<<endl<<endl;
            		}
            		else if(ctr>=600&&ctr<700) //If Value is 600-699 ; outputs current movie stored in movieC2[0]
                    {
				cout<<"   Movie:"<<movieC2[0]<<endl
                    <<"   Time Start: "<<movieTime[0]<<endl<<endl;
            		}
            		else if(ctr>=700&&ctr<800) //If Value is 700-799 ; outputs current movie stored in movieC2[1]
            		{
				cout<<"   Movie:"<<movieC2[1]<<endl
                    <<"   Time Start: "<<movieTime[1]<<endl<<endl;
            		}
            		else if(ctr>=800&&ctr<900) //If Value is 800-899 ; outputs current movie stored in movieC2[2]
            		{
				cout<<"   Movie:"<<movieC2[2]<<endl
                    <<"   Time Start: "<<movieTime[2]<<endl<<endl;
            		}
            		else if(ctr>=900&&ctr<1000) //If Value is 900-999 ; outputs current movie stored in movieC2[3]
            		{
				cout<<"   Movie:"<<movieC2[3]<<endl
                    <<"   Time Start: "<<movieTime[3]<<endl<<endl;
            		}
            		else if(ctr>=1000&&ctr<1100) //If Value is 1000-1099 ; outputs current movie stored in movieC2[4]
            		{
				cout<<"   Movie:"<<movieC2[4]<<endl
                    <<"   Time Start: "<<movieTime[4]<<endl<<endl;
            		}
            	else if(ctr>=1100&&ctr<1200) //If Value is 1100-1199 ; outputs current movie stored in movieC2[5]
            		{
				cout<<"   Movie:"<<movieC2[5]<<endl
                    <<"   Time Start: "<<movieTime[5]<<endl<<endl;
            		}
				}
            ctr++;
        }while(ctr<1200);
                                cout<<"Go Back (Y/N)?"; //Confirms if the user wants to go back to previous menu.
                                cin>>goBack_1;
                                if(goBack_1=='Y'|'y')
                                {
                                	goBack=1;
								}
								else
								goBack=0;
}

//-----------------------------------//
char getMenu() //Simple Menu function
{
    do{
    cout<<"Welcome to CineMix: Online Reservation Ticket"<<endl
        <<"[1] Movies: Now Playing"<<endl
        <<"[2] Log-in"<<endl
        <<"[3] Look-up Ticket"<<endl
        <<"[4] Buy Ticket"<<endl
        <<"[5] Exit"<<endl
        <<"Enter Choice:";
    cin>>choice;
        
        if(choice<'1'||choice>'5') //will output if value inputted is less than 1 or greater than 5.
        {
            cout<<"Input is not valid."<<endl
            <<"Please Try Again."<<endl;
        }
        
    }while(choice<'1'||choice>'5');
    return choice;
    
}
//-----------------------------------//

char getLogin() //Simple Login fucntion
{
    //local declaration
    char tryAgain;
    
    //executable
    system ("cls"); 
    cout<<"Please Log-in before we proceed"<<endl;
    do{
    cout<<"User-Name:";
    cin>>userN;
    cout<<"Password:";
    cin>>userP;
    
    if(userN==userNconf&&userP==userPconf) //Compares if the input is equal to "Admin"
    {
        adminconf=1;
        return adminconf;
    }
    else
    {
    cout<<"Username or Password is incorrect"<<endl
        <<"Do you want to try again? (Y/N)?"; //Confirms if the user wants to try again with logging in. If yes, loops back. if no, user goes back to the Main Menu
            cin>>tryAgain;
            if(tryAgain=='N'||tryAgain=='n')
            {
                goBack=0;
            return goBack;
                break;
            }
            if(tryAgain=='Y'||tryAgain=='y')
            {
                goBack=1;
            }
    }
    }while(goBack==1);
    return goBack;
}

//-----------------------------------//

char getAdmin() //Simple admin output
{
	system("cls");
    do{
    cout<<"Admin Menu"<<endl
        <<"[1] Movies"<<endl
        <<"[2] View Reserved Seats"<<endl
        <<"[3] View List of bought Tickets"<<endl
        <<"[4] Sign Out"<<endl
        <<"Enter Choice:";
    cin>>adminChoice;
    }while(adminChoice<'1'||adminChoice>'4');
    return adminChoice;
}

//-----------------------------------//

char viewReservedSeats()
{
	system ("cls");
 ctr=0; //Ctr variable is used widely, sets the value to 0 so that it won't create any kind intersection with ctr used in other functions.
 cout<<endl<<"Movie: "<<movieC1[0]<<endl;
	do //For cinema 1; 11 am
    {
    	if(ctr<=99) //100 Loops to print out all the variables inside the designated cinema(One/Two)(1-5) variable
        {
        cout<<"[ ";
	    	if(cinemaOne1[ctr]==1) //If cinemaOne[#] Already has a value, it means that it is taken. 
            cout<<" X";
   		    else
            {
        		if(ctr<10) //Adds a space to the first 9 numbers.
            	{
            		cout<<" ";
            	}
                	cout<<ctr;
                }
                	cout<<" ]";
                if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99) //Creates the rows in intervals of 20.
                	cout<<endl;
                if(cinemaOne1[ctr]!=1) //Assigns value to cinemacinema(One/Two)(1-5) -- Is a redundant code due to Value Assign Function already assigning codes.
                {
                	cinemaOne1[ctr]=0;
                }
                ctr++;
                }
    }while(ctr<100);
    cout<<endl<<"Movie: "<<movieC1[1]<<endl; 
    
    ctr=0; //Resets the value of ctr to 0 to be used on the next instance.
	do //For cinema 1; 1 pm. This is the same code as is above, but has different variables.
    {
    	if(ctr<=99)
        {
        cout<<"[ ";
	    	if(cinemaOne2[ctr]==1)
            cout<<" X";
   		    else
            {
        		if(ctr<10)
            	{
            		cout<<" ";
            	}
                	cout<<ctr;
                }
                	cout<<" ]";
                if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                	cout<<endl;
                if(cinemaOne2[ctr]!=1)
                {
                	cinemaOne2[ctr]=0;
                }
                ctr++;
                }
    }while(ctr<100);
    cout<<endl;
    ctr=0;
    cout<<endl<<"Movie: "<<movieC1[2]<<endl;
	do //For cinema 1; 3 pm
    {
    	if(ctr<=99)
        {
        cout<<"[ ";
	    	if(cinemaOne3[ctr]==1)
            cout<<" X";
   		    else
            {
        		if(ctr<10)
            	{
            		cout<<" ";
            	}
                	cout<<ctr;
                }
                	cout<<" ]";
                if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                	cout<<endl;
                if(cinemaOne3[ctr]!=1)
                {
                	cinemaOne3[ctr]=0;
                }
                ctr++;
                }
    }while(ctr<100);
    cout<<endl;
    ctr=0;
    cout<<endl<<"Movie: "<<movieC1[3]<<endl;
	do //For cinema 1; 5 pm
    {
    	if(ctr<=99)
        {
        cout<<"[ ";
	    	if(cinemaOne4[ctr]==1)
            cout<<" X";
   		    else
            {
        		if(ctr<10)
            	{
            		cout<<" ";
            	}
                	cout<<ctr;
                }
                	cout<<" ]";
                if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                	cout<<endl;
                if(cinemaOne4[ctr]!=1)
                {
                	cinemaOne4[ctr]=0;
                }
                ctr++;
                }
    }while(ctr<100);
    cout<<endl;
    ctr=0;
    cout<<endl<<"Movie: "<<movieC1[4]<<endl;
	do //For cinema 1; 7 pm
    {
    	if(ctr<=99)
        {
        cout<<"[ ";
	    	if(cinemaOne5[ctr]==1)
            cout<<" X";
   		    else
            {
        		if(ctr<10)
            	{
            		cout<<" ";
            	}
                	cout<<ctr;
                }
                	cout<<" ]";
                if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                	cout<<endl;
                if(cinemaOne5[ctr]!=1)
                {
                	cinemaOne5[ctr]=0;
                }
                ctr++;
                }
    }while(ctr<100);
    cout<<endl;
    ctr=0;
    cout<<endl<<"Movie: "<<movieC1[5]<<endl;
	do //For cinema 1; 9 pm
    {
    	if(ctr<=99)
        {
        cout<<"[ ";
	    	if(cinemaOne6[ctr]==1)
            cout<<" X";
   		    else
            {
        		if(ctr<10)
            	{
            		cout<<" ";
            	}
                	cout<<ctr;
                }
                	cout<<" ]";
                if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                	cout<<endl;
                if(cinemaOne6[ctr]!=1)
                {
                	cinemaOne6[ctr]=0;
                }
                ctr++;
                }
    }while(ctr<100);
    //----------------------------------// Cinema 2: View Reserved Seats
    cout<<endl;
    cout<<endl<<"Movie: "<<movieC2[0]<<endl;
    ctr=0;
	do //For cinema 2; 11 am
    {
    	if(ctr<=99)
        {
        cout<<"[ ";
	    	if(cinemaTwo1[ctr]==1)
            cout<<" X";
   		    else
            {
        		if(ctr<10)
            	{
            		cout<<" ";
            	}
                	cout<<ctr;
                }
                	cout<<" ]";
                if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                	cout<<endl;
                if(cinemaTwo1[ctr]!=1)
                {
                	cinemaTwo1[ctr]=0;
                }
                ctr++;
                }
    }while(ctr<100);
    cout<<endl;
    ctr=0;
    cout<<endl<<"Movie: "<<movieC2[1]<<endl;
	do //For cinema 2; 1 pm
    {
    	if(ctr<=99)
        {
        cout<<"[ ";
	    	if(cinemaTwo2[ctr]==1)
            cout<<" X";
   		    else
            {
        		if(ctr<10)
            	{
            		cout<<" ";
            	}
                	cout<<ctr;
                }
                	cout<<" ]";
                if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                	cout<<endl;
                if(cinemaTwo2[ctr]!=1)
                {
                	cinemaTwo2[ctr]=0;
                }
                ctr++;
                }
    }while(ctr<100);
    cout<<endl;
    ctr=0;
    cout<<endl<<"Movie: "<<movieC2[2]<<endl;
	do //For cinema 2; 3 pm
    {
    	if(ctr<=99)
        {
        cout<<"[ ";
	    	if(cinemaTwo3[ctr]==1)
            cout<<" X";
   		    else
            {
        		if(ctr<10)
            	{
            		cout<<" ";
            	}
                	cout<<ctr;
                }
                	cout<<" ]";
                if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                	cout<<endl;
                if(cinemaTwo3[ctr]!=1)
                {
                	cinemaTwo3[ctr]=0;
                }
                ctr++;
                }
    }while(ctr<100);
    cout<<endl;
    ctr=0;
    cout<<endl<<"Movie: "<<movieC2[3]<<endl;
	do //For cinema 2; 5 pm
    {
    	if(ctr<=99)
        {
        cout<<"[ ";
	    	if(cinemaTwo4[ctr]==1)
            cout<<" X";
   		    else
            {
        		if(ctr<10)
            	{
            		cout<<" ";
            	}
                	cout<<ctr;
                }
                	cout<<" ]";
                if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                	cout<<endl;
                if(cinemaTwo4[ctr]!=1)
                {
                	cinemaTwo4[ctr]=0;
                }
                ctr++;
                }
    }while(ctr<100);
    cout<<endl;
    ctr=0;
    cout<<"Movie: "<<movieC2[4]<<endl;
	do //For cinema 2; 7 pm
    {
    	if(ctr<=99)
        {
        cout<<"[ ";
	    	if(cinemaTwo5[ctr]==1)
            cout<<" X";
   		    else
            {
        		if(ctr<10)
            	{
            		cout<<" ";
            	}
                	cout<<ctr;
                }
                	cout<<" ]";
                if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                	cout<<endl;
                if(cinemaTwo5[ctr]!=1)
                {
                	cinemaTwo5[ctr]=0;
                }
                ctr++;
                }
    }while(ctr<100);
    cout<<endl;
    ctr=0;
    cout<<endl<<"Movie: "<<movieC2[5]<<endl;
	do //For cinema 2; 9 pm
    {
    	if(ctr<=99)
        {
        cout<<"[ ";
	    	if(cinemaTwo6[ctr]==1)
            cout<<" X";
   		    else
            {
        		if(ctr<10)
            	{
            		cout<<" ";
            	}
                	cout<<ctr;
                }
                	cout<<" ]";
                if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                	cout<<endl;
                if(cinemaTwo6[ctr]!=1)
                {
                	cinemaTwo6[ctr]=0;
                }
                ctr++;
                }
    }while(ctr<100); //Confirms if the user wants to go Back to the previous menu.
    cout<<endl<<"Go Back (Y/N)?";
    cin>>goBack_1;
        if(goBack_1=='Y'|'y')
    {
    goBack=1;
	}
	else
	goBack=0;
}
 

//-----------------------------------//

char addMovie() //Add or Change Movie Function.
{
	//Local Declaration
    char choiceMovie;
    char choiceAddMovieCinema;
    char choiceWhichMovie;
    
    //executable
    system ("cls");
        cout<<"Current Movies:"<<endl
            <<"           [Cinema 1]    [Cinema 2]"<<endl
            <<movieTime[0]<<" : "<<movieC1[0]<<setw(5)<<" "<<movieC2[0]<<endl
                    <<movieTime[1]<<" : "<<movieC1[1]<<setw(7)<<" "<<movieC2[1]<<endl
                    <<movieTime[2]<<" : "<<movieC1[2]<<setw(11)<<" "<<movieC2[2]<<endl
                    <<movieTime[3]<<" : "<<movieC1[3]<<setw(7)<<" "<<movieC2[3]<<endl
                    <<movieTime[4]<<" : "<<movieC1[4]<<setw(11)<<" "<<movieC2[4]<<endl
                    <<movieTime[5]<<" : "<<movieC1[5]<<setw(3)<<" "<<movieC2[5]<<endl
            <<"You can only add up to 12 movies to be Premiered"<<endl
            <<"[1] Add or Change Movie"<<endl
            <<"[2] Go Back"<<endl
            <<"Enter Choice:";
        cin>>choiceMovie;
        
        switch(choiceMovie) //Enables the user to choose which cinema to change/add the movie to.
        {
            case '1':
            {

                cout<<"Change or Add movie to:"<<endl
                    <<"[1] Cinema 1"<<endl
                    <<"[2] Cinema 2"<<endl
                    <<"[3] Go Back"<<endl
                    <<"Enter Choice:";
                cin>>choiceAddMovieCinema;
                
                if(choiceAddMovieCinema=='1')
                {
                    do{
                        goBack=1; //Resets the value to 1 so that it could loop; and would have the same value as all the goBack loops for less confusion.
                        system ("cls");
                cout<<endl
                    <<"Change/Add movie;"<<endl //Allows user to choose which movie to change/add.
                    <<"[1]"<<movieTime[0]<<" : "<<movieC1[0]<<endl
                    <<"[2]"<<movieTime[1]<<" : "<<movieC1[1]<<endl
                    <<"[3]"<<movieTime[2]<<" : "<<movieC1[2]<<endl
                    <<"[4]"<<movieTime[3]<<" : "<<movieC1[3]<<endl
                    <<"[5]"<<movieTime[4]<<" : "<<movieC1[4]<<endl
                    <<"[6]"<<movieTime[5]<<" : "<<movieC1[5]<<endl
                    <<"[7] Go Back"<<endl
                    <<"Enter Choice (Press Enter Twice To Confirm Answer):";
                    cin>>choiceWhichMovie;
                    
                    
                    switch(choiceWhichMovie)
                    {
                case '1':
                cin.ignore();
                cout<<"Enter Movie:";
                getline(cin,movieC1[0]); //also Stores the ' ' inside the string. 
                            cin.ignore(); //Assists in getline(cin,variable) to help it work. 
                            break;
                case '2':
                cin.ignore();
                cout<<"Enter Movie:";
                getline(cin,movieC1[1]);
                            cin.ignore();
                            break;
                case '3':
                cin.ignore();
                cout<<"Enter Movie:";
                getline(cin,movieC1[2]);
                            cin.ignore();
                            break;
                case '4':
                cin.ignore();
                cout<<"Enter Movie:";
                getline(cin,movieC1[3]);
                            cin.ignore();
                            break;
                case '5':
                cin.ignore();
                cout<<"Enter Movie:";
                getline(cin,movieC1[4]);
                            cin.ignore();
                            break;
                case '6':
                cin.ignore();
                cout<<"Enter Movie:";
                getline(cin,movieC1[5]);
                            cin.ignore();
                case '7':
                            goBack=0;
                            break;
                    }
                    }while(goBack==1);
                }
                if(choiceAddMovieCinema=='2') //Same as above but for cinema 2.
                {
                    cout<<"Change/Add movie;"<<endl
                    <<"[1]"<<movieTime[0]<<" : "<<movieC2[0]<<endl
                    <<"[2]"<<movieTime[1]<<" : "<<movieC2[1]<<endl
                    <<"[3]"<<movieTime[2]<<" : "<<movieC2[2]<<endl
                    <<"[4]"<<movieTime[3]<<" : "<<movieC2[3]<<endl
                    <<"[5]"<<movieTime[4]<<" : "<<movieC2[4]<<endl
                    <<"[6]"<<movieTime[5]<<" : "<<movieC2[5]<<endl
                    <<"[7] Go Back"<<endl
                    <<"Enter Choice:";
                    cin>>choiceWhichMovie;
                    switch(choiceWhichMovie)
               {
                case '1':
                cin.ignore();
                cout<<"Enter Movie:";
                getline(cin,movieC2[0]);
                            cin.ignore();
                            break;
                case '2':
                cin.ignore();
                cout<<"Enter Movie:";
                getline(cin,movieC2[1]);
                            cin.ignore();
                            break;
                case '3':
                cin.ignore();
                cout<<"Enter Movie:";
                getline(cin,movieC2[2]);
                            cin.ignore();
                            break;
                case '4':
                cin.ignore();
                cout<<"Enter Movie:";
                getline(cin,movieC2[3]);
                            cin.ignore();
                            break;
                case '5':
                cin.ignore();
                cout<<"Enter Movie:";
                getline(cin,movieC2[4]);
                            cin.ignore();
                            break;
                case '6':
                cin.ignore();
                cout<<"Enter Movie:";
                getline(cin,movieC2[5]);
                            cin.ignore();
                            break;
                case '7':
                            goBack=0;
                            break;
                    }
                }
                if(choiceAddMovieCinema=='3')
                {
                    goBack=0;
                    return goBack;
                }
                
            }
                break;
            case '2':
            {
                goBack=1;
                return goBack;
            }
        }
    return 0; //Xcode on mac doesn't allow functions without returns outside of do-while loop.
}

//-----------------------------------//
char getCreditcard() //Optional Function -- Could be used to optimized and make the credit card taker better.
{
	cout<<"Enter Credit Card Number (16 Digits): ";
    cin>>creditCard;
}

//-----------------------------------//

char buyTickets() //Allows the user to buy Tickets.
{
	//Local Declaration
    int seatTaken=0;
    int checker;
    int randNum, randMax=300000, randMin=200000;
	int batch=2019;
	int ctr;
    char transactionConf;
    
    //executable
    system ("cls");
    
    do{
    	srand (time(NULL)); //Ticket Number Randomizer taken from BB
	for(ctr=1;ctr<=5;ctr++)
	{
		randNum=(batch*1000000)+ (rand()%(randMax-randMin)+randMin); //Allows the number to be randomized vlue to be between 200k and 300k with the initial 4 numbers always starting with 2019
	}
	
        cout<<"Now Showing:"<<endl //Shows current movies and their time.
        <<"    Time :Choice: [Cinema 1]"<<endl
        <<movieTime[0]<<" : "<<" [1] : "<<movieC1[0]<<endl
        <<movieTime[1]<<" : "<<" [2] : "<<movieC1[1]<<endl
        <<movieTime[2]<<" : "<<" [3] : "<<movieC1[2]<<endl
        <<movieTime[3]<<" : "<<" [4] : "<<movieC1[3]<<endl
        <<movieTime[4]<<" : "<<" [5] : "<<movieC1[4]<<endl
        <<movieTime[5]<<" : "<<" [6] : "<<movieC1[5]<<endl
        <<"    Time:         [Cinema 2]"<<endl
        <<movieTime[0]<<" : "<<" [7] : "<<movieC2[0]<<endl
        <<movieTime[1]<<" : "<<" [8] : "<<movieC2[1]<<endl
        <<movieTime[2]<<" : "<<" [9] : "<<movieC2[2]<<endl
        <<movieTime[3]<<" : "<<"[10] : "<<movieC2[3]<<endl
        <<movieTime[4]<<" : "<<"[11] : "<<movieC2[4]<<endl
        <<movieTime[5]<<" : "<<"[12] : "<<movieC2[5]<<endl
        <<"    Enter  [13] Go Back"<<endl
        <<"Choose Movie (1-13):";
        cin>>chosenMovie;
        if(chosenMovie<1&&chosenMovie>13) //Only allows value to be entered to be either less than 1 or greater than 13. Anything else inputted will loop.
            cout<<"Please Enter numbers between 1 and 13"<<endl;
    }while(chosenMovie<1||chosenMovie>13);
    system ("cls");
    switch(chosenMovie)
    {
        case 1:
        {
            do{
            goBack=0;
            do{
            cout<<"Cinema 1: "<<movieC1[1]<<" Seats: [  X  ] Reserved [  #  ] Vacant"<<endl<<endl;
                ctr=0;
            do 
            {
                if(ctr<=99) //Shows the Seats Available loop -- Same code as the one from View Reserved Seats function
                {
                
                    cout<<"[ ";
                    if(cinemaOne1[ctr]==1)
                        cout<<" X";
                    else
                    {
                        if(ctr<10)
                        {
                            cout<<" ";
                        }
                        cout<<ctr;
                    }
                    cout<<" ]";
                    if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                        cout<<endl;
                    if(cinemaOne1[ctr]!=1)
                    {
                    cinemaOne1[ctr]=0;
                    }
                        ctr++;
                }
            }while(ctr<100);
                
            cout<<endl;
            cout<<"Please Choose a Seat: ";
            cin>>chosenSeat;
                system ("cls");
                checker=cinemaOne1[chosenSeat]; //Checks if chosen seat is already taken or not
            if(checker==1)
            {
                cout<<"That Seat is already taken; Please Choose another one"<<endl; //Output if seat is already taken.
                seatTaken=1;
            }
            if(checker==0)
            {
            cinemaOne1[chosenSeat]=1;
                cout<<"You have Succesfully reserved the Seat"<<endl;
                seatTaken=0;
            }
                ctr=0;
            }while(seatTaken==1); //Shows an updated graphic picture of the seats;
           
                do
                {
                    if(ctr<=99)
                    {
                        
                        cout<<"[ ";
                        if(cinemaOne1[ctr]==1)
                            cout<<" X";
                        else
                        {
                            if(ctr<10)
                            {
                                cout<<" ";
                            }
                            cout<<ctr;
                        }
                        cout<<"  ]";
                        if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                            cout<<endl;
                        if(cinemaOne1[ctr]!=1)
                        {
                            cinemaOne1[ctr]=0;
                        }
                        ctr++;
                    }
                }while(ctr<100);
                    //Asks user to input personal information to store along with the seat
                cout<<"Please Enter Your First Name:";
                cin>>name[chosenSeat];
                cout<<"Please Enter Your Last Name:";
                cin>>lname[chosenSeat];
                cout<<"Pleae Enter Your Email Adress:";
                cin>>email[chosenSeat];
        		
                
                getCreditcard(); 

                cout<<"The total price is P"<<price[0]<<endl;
                
                cout<<"Continue transaction? (Y/N):"; //Asks if the user wants to continue the transaction. If yes continues, if no; resets the value of the seat that was chosen to 0; therefore not taken anymore and then goes back to previous menu.
                cin>>transactionConf;
            if(transactionConf=='n'||transactionConf=='N')
                {
                    cinemaOne1[chosenSeat]=0;
                    break;
                }
            if(transactionConf=='Y'||transactionConf=='y')
                {
                    ticketHolder[chosenSeat]=randNum;
                cout<<"Transaction Succesful!"<<endl
                    <<"Your Ticket number is "<<ticketHolder[chosenSeat]<<endl;
                
                }
                do{ //Confirms if the user wants to go back to previous menu.
                cout<<"Go Back? (Y/N):";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    goBack=1;
                    break;
                }
                if(choice=='N'||choice=='n')
                    goBack=0;
            }while(goBack==1);
            }while(goBack==0);
            
            return goBack;
        }
            break;
        case 2: //Buy Tickets For cinema 1 / 1 pm Time //Same code as is above, just different varabiles.
        {
            do{
            goBack=0;
            do{
            cout<<"Cinema 1: "<<movieC1[2]<<" Seats: [  X  ] Reserved [  #  ] Vacant"<<endl<<endl;
                ctr=0;
            do
            {
                if(ctr<=99)
                {
                
                    cout<<"[ ";
                    if(cinemaOne2[ctr]==1)
                        cout<<" X";
                    else
                    {
                        if(ctr<10)
                        {
                            cout<<" ";
                        }
                        cout<<ctr;
                    }
                    cout<<" ]";
                    if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                        cout<<endl;
                    if(cinemaOne2[ctr]!=1)
                    {
                    cinemaOne2[ctr]=0;
                    }
                        ctr++;
                }
            }while(ctr<100);
                
            cout<<endl;
            cout<<"Please Choose a Seat: ";
            cin>>chosenSeat;
                system ("cls");
                checker=cinemaOne2[chosenSeat];
            if(checker==1)
            {
                cout<<"That Seat is already taken; Please Choose another one"<<endl;
                seatTaken=1;
            }
            if(checker==0)
            {
            cinemaOne2[chosenSeat]=1;
                cout<<"You have Succesfully reserved the Seat"<<endl;
                seatTaken=0;
            }
                ctr=0;
            }while(seatTaken==1);
                do
                {
                    if(ctr<=99)
                    {
                        
                        cout<<"[ ";
                        if(cinemaOne2[ctr]==1)
                            cout<<" X";
                        else
                        {
                            if(ctr<10)
                            {
                                cout<<" ";
                            }
                            cout<<ctr;
                        }
                        cout<<"  ]";
                        if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                            cout<<endl;
                        if(cinemaOne2[ctr]!=1)
                        {
                            cinemaOne2[ctr]=0;
                        }
                        ctr++;
                    }
                }while(ctr<100);
                //Plus one hundered on some variables to store inside the ticketHolder[#] in between 100-199;
                cout<<"Please Enter Your First Name:";
                cin>>name[chosenSeat+100]; 
                cout<<"Please Enter Your Last Name:";
                cin>>lname[chosenSeat+100];
                cout<<"Pleae Enter Your Email Adress:";
                cin>>email[chosenSeat+100];
                
                getCreditcard();
                
                cout<<"The total price is P"<<price[0]<<endl;
                
                cout<<"Continue transaction? (Y/N):";
                cin>>transactionConf;
            if(transactionConf=='n'||transactionConf=='N')
                {
                    cinemaOne2[chosenSeat]=0;
                    break;
                }
            if(transactionConf=='Y'||transactionConf=='y')
                {
                    ticketHolder[chosenSeat+100]=randNum;
                cout<<"Transaction Succesful!"<<endl
                    <<"Your Ticket number is "<<ticketHolder[chosenSeat+100]<<endl;
                
                }
                do{
                cout<<"Go Back? (Y/N):";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    goBack=1;
                    break;
                }
                if(choice=='N'||choice=='n')
                    goBack=0;
            }while(goBack==1);
            }while(goBack==0);
            
            return goBack;
        }
            break;
        case 3: //Cinema 1 ; 3 pm
        {
        	do{
            goBack=0;
            do{
            cout<<"Cinema 1: "<<movieC1[2]<<" Seats: [  X  ] Reserved [  #  ] Vacant"<<endl<<endl;
                ctr=0;
            do
            {
                if(ctr<=99)
                {
                
                    cout<<"[ ";
                    if(cinemaOne3[ctr]==1)
                        cout<<" X";
                    else
                    {
                        if(ctr<10)
                        {
                            cout<<" ";
                        }
                        cout<<ctr;
                    }
                    cout<<" ]";
                    if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                        cout<<endl;
                    if(cinemaOne3[ctr]!=1)
                    {
                    cinemaOne3[ctr]=0;
                    }
                        ctr++;
                }
            }while(ctr<100);
                
            cout<<endl;
            cout<<"Please Choose a Seat: ";
            cin>>chosenSeat;
                system ("cls");
                checker=cinemaOne3[chosenSeat];
            if(checker==1)
            {
                cout<<"That Seat is already taken; Please Choose another one"<<endl;
                seatTaken=1;
            }
            if(checker==0)
            {
            cinemaOne3[chosenSeat]=1;
                cout<<"You have Succesfully reserved the Seat"<<endl;
                seatTaken=0;
            }
                ctr=0;
            }while(seatTaken==1);
                do
                {
                    if(ctr<=99)
                    {
                        
                        cout<<"[ ";
                        if(cinemaOne3[ctr]==1)
                            cout<<" X";
                        else
                        {
                            if(ctr<10)
                            {
                                cout<<" ";
                            }
                            cout<<ctr;
                        }
                        cout<<"  ]";
                        if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                            cout<<endl;
                        if(cinemaOne3[ctr]!=1)
                        {
                            cinemaOne3[ctr]=0;
                        }
                        ctr++;
                    }
                }while(ctr<100);
                
                cout<<"Please Enter Your First Name:";
                cin>>name[chosenSeat+200];
                cout<<"Please Enter Your Last Name:";
                cin>>lname[chosenSeat+200];
                cout<<"Pleae Enter Your Email Adress:";
                cin>>email[chosenSeat+200];
                
                getCreditcard();
                
                cout<<"The total price is P"<<price[0]<<endl;
                
                cout<<"Continue transaction? (Y/N):";
                cin>>transactionConf;
            if(transactionConf=='n'||transactionConf=='N')
                {
                    cinemaOne3[chosenSeat]=0;
                    break;
                }
            if(transactionConf=='Y'||transactionConf=='y')
                {
                    ticketHolder[chosenSeat+200]=randNum;
                cout<<"Transaction Succesful!"<<endl
                    <<"Your Ticket number is "<<ticketHolder[chosenSeat+200]<<endl;
                
                }
                do{
                cout<<"Go Back? (Y/N):";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    goBack=1;
                    break;
                }
                if(choice=='N'||choice=='n')
                    goBack=0;
            }while(goBack==1);
            }while(goBack==0);
            
            return goBack;    
        }
            break;
        case 4: //Cinema 1 ; 5 pm
        {
            do{
            goBack=0;
            do{
            cout<<"Cinema 1: "<<movieC1[3]<<" Seats: [  X  ] Reserved [  #  ] Vacant"<<endl<<endl;
                ctr=0;
            do
            {
                if(ctr<=99)
                {
                
                    cout<<"[ ";
                    if(cinemaOne4[ctr]==1)
                        cout<<" X";
                    else
                    {
                        if(ctr<10)
                        {
                            cout<<" ";
                        }
                        cout<<ctr;
                    }
                    cout<<" ]";
                    if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                        cout<<endl;
                    if(cinemaOne4[ctr]!=1)
                    {
                    cinemaOne4[ctr]=0;
                    }
                        ctr++;
                }
            }while(ctr<100);
                
            cout<<endl;
            cout<<"Please Choose a Seat: ";
            cin>>chosenSeat;
                system ("cls");
                checker=cinemaOne4[chosenSeat];
            if(checker==1)
            {
                cout<<"That Seat is already taken; Please Choose another one"<<endl;
                seatTaken=1;
            }
            if(checker==0)
            {
            cinemaOne4[chosenSeat]=1;
                cout<<"You have Succesfully reserved the Seat"<<endl;
                seatTaken=0;
            }
                ctr=0;
            }while(seatTaken==1);
                do
                {
                    if(ctr<=99)
                    {
                        
                        cout<<"[ ";
                        if(cinemaOne4[ctr]==1)
                            cout<<" X";
                        else
                        {
                            if(ctr<10)
                            {
                                cout<<" ";
                            }
                            cout<<ctr;
                        }
                        cout<<"  ]";
                        if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                            cout<<endl;
                        if(cinemaOne4[ctr]!=1)
                        {
                            cinemaOne4[ctr]=0;
                        }
                        ctr++;
                    }
                }while(ctr<100);
                
                cout<<"Please Enter Your First Name:";
                cin>>name[chosenSeat+300];
                cout<<"Please Enter Your Last Name:";
                cin>>lname[chosenSeat+300];
                cout<<"Pleae Enter Your Email Adress:";
                cin>>email[chosenSeat+300];
                
                getCreditcard();
                
                cout<<"The total price is P"<<price[3]<<endl;
                
                cout<<"Continue transaction? (Y/N):";
                cin>>transactionConf;
            if(transactionConf=='n'||transactionConf=='N')
                {
                    cinemaOne4[chosenSeat]=0;
                    break;
                }
            if(transactionConf=='Y'||transactionConf=='y')
                {
                    ticketHolder[chosenSeat+300]=randNum;
                cout<<"Transaction Succesful!"<<endl
                    <<"Your Ticket number is "<<ticketHolder[chosenSeat+300]<<endl;
                
                }
                do{
                cout<<"Go Back? (Y/N):";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    goBack=1;
                    break;
                }
                if(choice=='N'||choice=='n')
                    goBack=0;
            }while(goBack==1);
            }while(goBack==0);
        }
            break;
        case 5: // Cinema 1 ; 7 pm
        {
            do{
            goBack=0;
            do{
            cout<<"Cinema 1: "<<movieC1[4]<<" Seats: [  X  ] Reserved [  #  ] Vacant"<<endl<<endl;
                ctr=0;
            do
            {
                if(ctr<=99)
                {
                
                    cout<<"[ ";
                    if(cinemaOne5[ctr]==1)
                        cout<<" X";
                    else
                    {
                        if(ctr<10)
                        {
                            cout<<" ";
                        }
                        cout<<ctr;
                    }
                    cout<<" ]";
                    if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                        cout<<endl;
                    if(cinemaOne5[ctr]!=1)
                    {
                    cinemaOne5[ctr]=0;
                    }
                        ctr++;
                }
            }while(ctr<100);
                
            cout<<endl;
            cout<<"Please Choose a Seat: ";
            cin>>chosenSeat;
                system ("cls");
                checker=cinemaOne5[chosenSeat];
            if(checker==1)
            {
                cout<<"That Seat is already taken; Please Choose another one"<<endl;
                seatTaken=1;
            }
            if(checker==0)
            {
            cinemaOne5[chosenSeat]=1;
                cout<<"You have Succesfully reserved the Seat"<<endl;
                seatTaken=0;
            }
                ctr=0;
            }while(seatTaken==1);
                do
                {
                    if(ctr<=99)
                    {
                        
                        cout<<"[ ";
                        if(cinemaOne5[ctr]==1)
                            cout<<" X";
                        else
                        {
                            if(ctr<10)
                            {
                                cout<<" ";
                            }
                            cout<<ctr;
                        }
                        cout<<"  ]";
                        if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                            cout<<endl;
                        if(cinemaOne5[ctr]!=1)
                        {
                            cinemaOne5[ctr]=0;
                        }
                        ctr++;
                    }
                }while(ctr<100);
                
                cout<<"Please Enter Your First Name:";
                cin>>name[chosenSeat+400];
                cout<<"Please Enter Your Last Name:";
                cin>>lname[chosenSeat+400];
                cout<<"Pleae Enter Your Email Adress:";
                cin>>email[chosenSeat+400];
                
                getCreditcard();
                
                cout<<"The total price is P"<<price[4]<<endl;
                
                cout<<"Continue transaction? (Y/N):";
                cin>>transactionConf;
            if(transactionConf=='n'||transactionConf=='N')
                {
                    cinemaOne5[chosenSeat]=0;
                    break;
                }
            if(transactionConf=='Y'||transactionConf=='y')
                {
                    ticketHolder[chosenSeat+400]=randNum;
                cout<<"Transaction Succesful!"<<endl
                    <<"Your Ticket number is "<<ticketHolder[chosenSeat+400]<<endl;
                
                }
                do{
                cout<<"Go Back? (Y/N):";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    goBack=1;
                    break;
                }
                if(choice=='N'||choice=='n')
                    goBack=0;
            }while(goBack==1);
            }while(goBack==0);
        }
            break;
        case 6: //Cinema 1 ; 9 pm
        {
            do{
            goBack=0;
            do{
            cout<<"Cinema 1: "<<movieC1[5]<<" Seats: [  X  ] Reserved [  #  ] Vacant"<<endl<<endl;
                ctr=0;
            do
            {
                if(ctr<=99)
                {
                
                    cout<<"[ ";
                    if(cinemaOne6[ctr]==1)
                        cout<<" X";
                    else
                    {
                        if(ctr<10)
                        {
                            cout<<" ";
                        }
                        cout<<ctr;
                    }
                    cout<<" ]";
                    if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                        cout<<endl;
                    if(cinemaOne6[ctr]!=1)
                    {
                    cinemaOne6[ctr]=0;
                    }
                        ctr++;
                }
            }while(ctr<100);
                
            cout<<endl;
            cout<<"Please Choose a Seat: ";
            cin>>chosenSeat;
                system ("cls");
                checker=cinemaOne6[chosenSeat];
            if(checker==1)
            {
                cout<<"That Seat is already taken; Please Choose another one"<<endl;
                seatTaken=1;
            }
            if(checker==0)
            {
            cinemaOne6[chosenSeat]=1;
                cout<<"You have Succesfully reserved the Seat"<<endl;
                seatTaken=0;
            }
                ctr=0;
            }while(seatTaken==1);
                do
                {
                    if(ctr<=99)
                    {
                        
                        cout<<"[ ";
                        if(cinemaOne6[ctr]==1)
                            cout<<" X";
                        else
                        {
                            if(ctr<10)
                            {
                                cout<<" ";
                            }
                            cout<<ctr;
                        }
                        cout<<"  ]";
                        if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                            cout<<endl;
                        if(cinemaOne6[ctr]!=1)
                        {
                            cinemaOne6[ctr]=0;
                        }
                        ctr++;
                    }
                }while(ctr<100);
                
                cout<<"Please Enter Your First Name:";
                cin>>name[chosenSeat+500];
                cout<<"Please Enter Your Last Name:";
                cin>>lname[chosenSeat+500];
                cout<<"Pleae Enter Your Email Adress:";
                cin>>email[chosenSeat+500];
                
                getCreditcard();
                
                cout<<"The total price is P"<<price[5]<<endl;
                
                cout<<"Continue transaction? (Y/N):";
                cin>>transactionConf;
            if(transactionConf=='n'||transactionConf=='N')
                {
                    cinemaOne6[chosenSeat]=0;
                    break;
                }
            if(transactionConf=='Y'||transactionConf=='y')
                {
                    ticketHolder[chosenSeat+500]=randNum;
                cout<<"Transaction Succesful!"<<endl
                    <<"Your Ticket number is "<<ticketHolder[chosenSeat+500]<<endl;
                
                }
                do{
                cout<<"Go Back? (Y/N):";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    goBack=1;
                    break;
                }
                if(choice=='N'||choice=='n')
                    goBack=0;
            }while(goBack==1);
            }while(goBack==0);
        }
            break;
        case 7: //Cinema 2 ; 11 am
        {
            do{
            goBack=0;
            do{
            cout<<"Cinema 1: "<<movieC2[0]<<" Seats: [  X  ] Reserved [  #  ] Vacant"<<endl<<endl;
                ctr=0;
            do
            {
                if(ctr<=99)
                {
                
                    cout<<"[ ";
                    if(cinemaTwo1[ctr]==1)
                        cout<<" X";
                    else
                    {
                        if(ctr<10)
                        {
                            cout<<" ";
                        }
                        cout<<ctr;
                    }
                    cout<<" ]";
                    if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                        cout<<endl;
                    if(cinemaTwo1[ctr]!=1)
                    {
                    cinemaTwo1[ctr]=0;
                    }
                        ctr++;
                }
            }while(ctr<100);
                
            cout<<endl;
            cout<<"Please Choose a Seat: ";
            cin>>chosenSeat;
                system ("cls");
                checker=cinemaTwo1[chosenSeat];
            if(checker==1)
            {
                cout<<"That Seat is already taken; Please Choose another one"<<endl;
                seatTaken=1;
            }
            if(checker==0)
            {
            cinemaTwo1[chosenSeat]=1;
                cout<<"You have Succesfully reserved the Seat"<<endl;
                seatTaken=0;
            }
                ctr=0;
            }while(seatTaken==1);
                do
                {
                    if(ctr<=99)
                    {
                        
                        cout<<"[ ";
                        if(cinemaTwo1[ctr]==1)
                            cout<<" X";
                        else
                        {
                            if(ctr<10)
                            {
                                cout<<" ";
                            }
                            cout<<ctr;
                        }
                        cout<<"  ]";
                        if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                            cout<<endl;
                        if(cinemaTwo1[ctr]!=1)
                        {
                            cinemaTwo1[ctr]=0;
                        }
                        ctr++;
                    }
                }while(ctr<100);
                
                cout<<"Please Enter Your First Name:";
                cin>>name[chosenSeat+600];
                cout<<"Please Enter Your Last Name:";
                cin>>lname[chosenSeat+600];
                cout<<"Pleae Enter Your Email Adress:";
                cin>>email[chosenSeat+600];
                
                getCreditcard();
                
                cout<<"The total price is P"<<price[6]<<endl;
                
                cout<<"Continue transaction? (Y/N):";
                cin>>transactionConf;
            if(transactionConf=='n'||transactionConf=='N')
                {
                    cinemaTwo1[chosenSeat]=0;
                    break;
                }
            if(transactionConf=='Y'||transactionConf=='y')
                {
                    ticketHolder[chosenSeat+600]=randNum;
                cout<<"Transaction Succesful!"<<endl
                    <<"Your Ticket number is "<<ticketHolder[chosenSeat+600]<<endl;
                
                }
                do{
                cout<<"Go Back? (Y/N):";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    goBack=1;
                    break;
                }
                if(choice=='N'||choice=='n')
                    goBack=0;
            }while(goBack==1);
            }while(goBack==0);
        }
            break;
        case 8: //Cinema 2 ; 2 pm
        {
            do{
            goBack=0;
            do{
            cout<<"Cinema 1: "<<movieC2[1]<<" Seats: [  X  ] Reserved [  #  ] Vacant"<<endl<<endl;
                ctr=0;
            do
            {
                if(ctr<=99)
                {
                
                    cout<<"[ ";
                    if(cinemaTwo2[ctr]==1)
                        cout<<" X";
                    else
                    {
                        if(ctr<10)
                        {
                            cout<<" ";
                        }
                        cout<<ctr;
                    }
                    cout<<" ]";
                    if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                        cout<<endl;
                    if(cinemaTwo2[ctr]!=1)
                    {
                    cinemaTwo2[ctr]=0;
                    }
                        ctr++;
                }
            }while(ctr<100);
                
            cout<<endl;
            cout<<"Please Choose a Seat: ";
            cin>>chosenSeat;
                system ("cls");
                checker=cinemaTwo2[chosenSeat];
            if(checker==1)
            {
                cout<<"That Seat is already taken; Please Choose another one"<<endl;
                seatTaken=1;
            }
            if(checker==0)
            {
            cinemaTwo2[chosenSeat]=1;
                cout<<"You have Succesfully reserved the Seat"<<endl;
                seatTaken=0;
            }
                ctr=0;
            }while(seatTaken==1);
                do
                {
                    if(ctr<=99)
                    {
                        
                        cout<<"[ ";
                        if(cinemaTwo2[ctr]==1)
                            cout<<" X";
                        else
                        {
                            if(ctr<10)
                            {
                                cout<<" ";
                            }
                            cout<<ctr;
                        }
                        cout<<"  ]";
                        if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                            cout<<endl;
                        if(cinemaTwo2[ctr]!=1)
                        {
                            cinemaTwo2[ctr]=0;
                        }
                        ctr++;
                    }
                }while(ctr<100);
                
                cout<<"Please Enter Your First Name:";
                cin>>name[chosenSeat+700];
                cout<<"Please Enter Your Last Name:";
                cin>>lname[chosenSeat+700];
                cout<<"Pleae Enter Your Email Adress:";
                cin>>email[chosenSeat+700];
                
                getCreditcard();
                
                cout<<"The total price is P"<<price[6]<<endl;
                
                cout<<"Continue transaction? (Y/N):";
                cin>>transactionConf;
            if(transactionConf=='n'||transactionConf=='N')
                {
                    cinemaTwo2[chosenSeat]=0;
                    break;
                }
            if(transactionConf=='Y'||transactionConf=='y')
                {
                    ticketHolder[chosenSeat+700]=randNum;
                cout<<"Transaction Succesful!"<<endl
                    <<"Your Ticket number is "<<ticketHolder[chosenSeat+700]<<endl;
                
                }
                do{
                cout<<"Go Back? (Y/N):";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    goBack=1;
                    break;
                }
                if(choice=='N'||choice=='n')
                    goBack=0;
            }while(goBack==1);
            }while(goBack==0);
        }
            break;
        case 9:
        {
            do{
            goBack=0;
            do{
            cout<<"Cinema 1: "<<movieC2[2]<<" Seats: [  X  ] Reserved [  #  ] Vacant"<<endl<<endl;
                ctr=0;
            do
            {
                if(ctr<=99)
                {
                
                    cout<<"[ ";
                    if(cinemaTwo3[ctr]==1)
                        cout<<" X";
                    else
                    {
                        if(ctr<10)
                        {
                            cout<<" ";
                        }
                        cout<<ctr;
                    }
                    cout<<" ]";
                    if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                        cout<<endl;
                    if(cinemaTwo3[ctr]!=1)
                    {
                    cinemaTwo3[ctr]=0;
                    }
                        ctr++;
                }
            }while(ctr<100);
                
            cout<<endl;
            cout<<"Please Choose a Seat: ";
            cin>>chosenSeat;
                system ("cls");
                checker=cinemaTwo3[chosenSeat];
            if(checker==1)
            {
                cout<<"That Seat is already taken; Please Choose another one"<<endl;
                seatTaken=1;
            }
            if(checker==0)
            {
            cinemaTwo3[chosenSeat]=1;
                cout<<"You have Succesfully reserved the Seat"<<endl;
                seatTaken=0;
            }
                ctr=0;
            }while(seatTaken==1);
                do
                {
                    if(ctr<=99)
                    {
                        
                        cout<<"[ ";
                        if(cinemaTwo3[ctr]==1)
                            cout<<" X";
                        else
                        {
                            if(ctr<10)
                            {
                                cout<<" ";
                            }
                            cout<<ctr;
                        }
                        cout<<"  ]";
                        if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                            cout<<endl;
                        if(cinemaTwo3[ctr]!=1)
                        {
                            cinemaTwo3[ctr]=0;
                        }
                        ctr++;
                    }
                }while(ctr<100);
                
                cout<<"Please Enter Your First Name:";
                cin>>name[chosenSeat+800];
                cout<<"Please Enter Your Last Name:";
                cin>>lname[chosenSeat+800];
                cout<<"Pleae Enter Your Email Adress:";
                cin>>email[chosenSeat+800];
                
                getCreditcard();
                
                cout<<"The total price is P"<<price[7]<<endl;
                
                cout<<"Continue transaction? (Y/N):";
                cin>>transactionConf;
            if(transactionConf=='n'||transactionConf=='N')
                {
                    cinemaTwo3[chosenSeat]=0;
                    break;
                }
            if(transactionConf=='Y'||transactionConf=='y')
                {
                    ticketHolder[chosenSeat+800]=randNum;
                cout<<"Transaction Succesful!"<<endl
                    <<"Your Ticket number is "<<ticketHolder[chosenSeat+800]<<endl;
                
                }
                do{
                cout<<"Go Back? (Y/N):";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    goBack=1;
                    break;
                }
                if(choice=='N'||choice=='n')
                    goBack=0;
            }while(goBack==1);
            }while(goBack==0); 
        }
            break;
        case 10:
        {
            do{
            goBack=0;
            do{
            cout<<"Cinema 1: "<<movieC2[3]<<" Seats: [  X  ] Reserved [  #  ] Vacant"<<endl<<endl;
                ctr=0;
            do
            {
                if(ctr<=99)
                {
                
                    cout<<"[ ";
                    if(cinemaTwo4[ctr]==1)
                        cout<<" X";
                    else
                    {
                        if(ctr<10)
                        {
                            cout<<" ";
                        }
                        cout<<ctr;
                    }
                    cout<<" ]";
                    if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                        cout<<endl;
                    if(cinemaTwo4[ctr]!=1)
                    {
                    cinemaTwo4[ctr]=0;
                    }
                        ctr++;
                }
            }while(ctr<100);
                
            cout<<endl;
            cout<<"Please Choose a Seat: ";
            cin>>chosenSeat;
                system ("cls");
                checker=cinemaTwo4[chosenSeat];
            if(checker==1)
            {
                cout<<"That Seat is already taken; Please Choose another one"<<endl;
                seatTaken=1;
            }
            if(checker==0)
            {
            cinemaTwo4[chosenSeat]=1;
                cout<<"You have Succesfully reserved the Seat"<<endl;
                seatTaken=0;
            }
                ctr=0;
            }while(seatTaken==1);
                do
                {
                    if(ctr<=99)
                    {
                        
                        cout<<"[ ";
                        if(cinemaTwo4[ctr]==1)
                            cout<<" X";
                        else
                        {
                            if(ctr<10)
                            {
                                cout<<" ";
                            }
                            cout<<ctr;
                        }
                        cout<<"  ]";
                        if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                            cout<<endl;
                        if(cinemaTwo4[ctr]!=1)
                        {
                            cinemaTwo4[ctr]=0;
                        }
                        ctr++;
                    }
                }while(ctr<100);
                
                cout<<"Please Enter Your First Name:";
                cin>>name[chosenSeat+900];
                cout<<"Please Enter Your Last Name:";
                cin>>lname[chosenSeat+900];
                cout<<"Pleae Enter Your Email Adress:";
                cin>>email[chosenSeat+900];
                
                getCreditcard();
                
                cout<<"The total price is P"<<price[8]<<endl;
                
                cout<<"Continue transaction? (Y/N):";
                cin>>transactionConf;
            if(transactionConf=='n'||transactionConf=='N')
                {
                    cinemaTwo4[chosenSeat]=0;
                    break;
                }
            if(transactionConf=='Y'||transactionConf=='y')
                {
                    ticketHolder[chosenSeat+900]=randNum;
                cout<<"Transaction Succesful!"<<endl
                    <<"Your Ticket number is "<<ticketHolder[chosenSeat+900]<<endl;
                
                }
                do{
                cout<<"Go Back? (Y/N):";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    goBack=1;
                    break;
                }
                if(choice=='N'||choice=='n')
                    goBack=0;
            }while(goBack==1);
            }while(goBack==0); 
        }
            break;
        case 11:
        {
            do{
            goBack=0;
            do{
            cout<<"Cinema 1: "<<movieC2[4]<<" Seats: [  X  ] Reserved [  #  ] Vacant"<<endl<<endl;
                ctr=0;
            do
            {
                if(ctr<=99)
                {
                
                    cout<<"[ ";
                    if(cinemaTwo5[ctr]==1)
                        cout<<" X";
                    else
                    {
                        if(ctr<10)
                        {
                            cout<<" ";
                        }
                        cout<<ctr;
                    }
                    cout<<" ]";
                    if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                        cout<<endl;
                    if(cinemaTwo5[ctr]!=1)
                    {
                    cinemaTwo5[ctr]=0;
                    }
                        ctr++;
                }
            }while(ctr<100);
                
            cout<<endl;
            cout<<"Please Choose a Seat: ";
            cin>>chosenSeat;
                system ("cls");
                checker=cinemaTwo5[chosenSeat];
            if(checker==1)
            {
                cout<<"That Seat is already taken; Please Choose another one"<<endl;
                seatTaken=1;
            }
            if(checker==0)
            {
            cinemaTwo5[chosenSeat]=1;
                cout<<"You have Succesfully reserved the Seat"<<endl;
                seatTaken=0;
            }
                ctr=0;
            }while(seatTaken==1);
                do
                {
                    if(ctr<=99)
                    {
                        
                        cout<<"[ ";
                        if(cinemaTwo5[ctr]==1)
                            cout<<" X";
                        else
                        {
                            if(ctr<10)
                            {
                                cout<<" ";
                            }
                            cout<<ctr;
                        }
                        cout<<"  ]";
                        if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                            cout<<endl;
                        if(cinemaTwo5[ctr]!=1)
                        {
                            cinemaTwo5[ctr]=0;
                        }
                        ctr++;
                    }
                }while(ctr<100);
                
                cout<<"Please Enter Your First Name:";
                cin>>name[chosenSeat+1000];
                cout<<"Please Enter Your Last Name:";
                cin>>lname[chosenSeat+1000];
                cout<<"Pleae Enter Your Email Adress:";
                cin>>email[chosenSeat+1000];
                
                getCreditcard();
                
                cout<<"The total price is P"<<price[8]<<endl;
                
                cout<<"Continue transaction? (Y/N):";
                cin>>transactionConf;
            if(transactionConf=='n'||transactionConf=='N')
                {
                    cinemaTwo5[chosenSeat]=0;
                    break;
                }
            if(transactionConf=='Y'||transactionConf=='y')
                {
                    ticketHolder[chosenSeat+1000]=randNum;
                cout<<"Transaction Succesful!"<<endl
                    <<"Your Ticket number is "<<ticketHolder[chosenSeat+1000]<<endl;
                
                }
                do{
                cout<<"Go Back? (Y/N):";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    goBack=1;
                    break;
                }
                if(choice=='N'||choice=='n')
                    goBack=0;
            }while(goBack==1);
            }while(goBack==0);
        }
            break;
        case 12:
        {
            do{
            goBack=0;
            do{
            cout<<"Cinema 1: "<<movieC2[5]<<" Seats: [  X  ] Reserved [  #  ] Vacant"<<endl<<endl;
                ctr=0;
            do
            {
                if(ctr<=99)
                {
                
                    cout<<"[ ";
                    if(cinemaTwo6[ctr]==1)
                        cout<<" X";
                    else
                    {
                        if(ctr<10)
                        {
                            cout<<" ";
                        }
                        cout<<ctr;
                    }
                    cout<<" ]";
                    if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                        cout<<endl;
                    if(cinemaTwo6[ctr]!=1)
                    {
                    cinemaTwo6[ctr]=0;
                    }
                        ctr++;
                }
            }while(ctr<100);
                
            cout<<endl;
            cout<<"Please Choose a Seat: ";
            cin>>chosenSeat;
                system ("cls");
                checker=cinemaTwo6[chosenSeat];
            if(checker==1)
            {
                cout<<"That Seat is already taken; Please Choose another one"<<endl;
                seatTaken=1;
            }
            if(checker==0)
            {
            cinemaTwo6[chosenSeat]=1;
                cout<<"You have Succesfully reserved the Seat"<<endl;
                seatTaken=0;
            }
                ctr=0;
            }while(seatTaken==1);
                do
                {
                    if(ctr<=99)
                    {
                        
                        cout<<"[ ";
                        if(cinemaTwo6[ctr]==1)
                            cout<<" X";
                        else
                        {
                            if(ctr<10)
                            {
                                cout<<" ";
                            }
                            cout<<ctr;
                        }
                        cout<<"  ]";
                        if(ctr==19||ctr==39||ctr==59||ctr==79||ctr==99)
                            cout<<endl;
                        if(cinemaTwo6[ctr]!=1)
                        {
                            cinemaTwo6[ctr]=0;
                        }
                        ctr++;
                    }
                }while(ctr<100);
                
                cout<<"Please Enter Your First Name:";
                cin>>name[chosenSeat+1100];
                cout<<"Please Enter Your Last Name:";
                cin>>lname[chosenSeat+1100];
                cout<<"Pleae Enter Your Email Adress:";
                cin>>email[chosenSeat+1100];
                
                getCreditcard();
                
                cout<<"The total price is P"<<price[8]<<endl;
                
                cout<<"Continue transaction? (Y/N):";
                cin>>transactionConf;
            if(transactionConf=='n'||transactionConf=='N')
                {
                    cinemaTwo6[chosenSeat]=0;
                    break;
                }
            if(transactionConf=='Y'||transactionConf=='y')
                {
                    ticketHolder[chosenSeat+1100]=randNum;
                cout<<"Transaction Succesful!"<<endl
                    <<"Your Ticket number is "<<ticketHolder[chosenSeat+1100]<<endl;
                
                }
                do{
                cout<<"Go Back? (Y/N):";
                cin>>choice;
                if(choice=='Y'||choice=='y')
                {
                    goBack=1;
                    break;
                }
                if(choice=='N'||choice=='n')
                    goBack=0;
            }while(goBack==1);
            }while(goBack==0);
        }
            break;
        case 13:
        {
            goBack=0;
            return goBack;
        }
            break;
    }
	    return choice;
}

//-----------------------------------//

char checkTicket() //Allows the user to check the movie and seat of buyer using the ticket number.
{
	//local declataion
    char checker2;
    int getTicket;
    
    //executable
	system ("cls"); 
    do{
        ctr=0;
        cout<<endl<<"Enter Ticket Number:";
        cin>>getTicket;
        do{ //Loops 1200 times to check all values inside the ticketHolder[1200] and if the value inside is the same as the value or ticket number inputted.
            if(getTicket==ticketHolder[ctr])
            {
                cout<<"Name:"<<name[ctr]<<" "<<lname[ctr]<<endl
                    <<"Movie:"<<movieC1[0]<<endl
                    <<"Time Start: "<<movieTime[0]<<endl;
            }
            ctr++;
        }while(ctr<1200);
        cout<<"Try Again? (Y/N): "; //Asks the user to try again, Option if the user input a non-existing ticket number or inputted the wrong ticket number. Simply allows the user to try again.
        cin>>checker2;
        if(checker2=='Y'||checker2=='y')
            goBack=0;
        else
            goBack=1;
        
    }while(goBack==0);
    return 0;
}
