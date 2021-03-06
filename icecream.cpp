#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

int main() 
{ 
string flavor_input, Capitalize; 
string flavors[] = { "Chocolate", "Vanilla", "Strawberry", "Mint", "Rocky Road", "Mocha" }; 
int scoop_count [6] = { 0, 0, 0, 0, 0, 0 }, scoops = 0, j, k
bool valid_option; 

cout << "Welcome to Frozen Tongue Ice Cream Shop\n"<<endl;
cout << "Flavors avaliable: "<<endl;
cout << "Chocolate "<<endl;
cout << "Valnilla "<<endl;
cout << "Strawberry "<<endl;
cout << "Mint "<<endl;
cout << "Rocky Road "<<endl;
cout << "Mocha \n"<<endl;

while(true) { 

    cout << "Please enter the flavor of icecream sold or 'STOP' to exit.\n"<<endl;
    getline (cin, flavor_input); // getline causes rocky road to be accepted with a space between the words. 


    string::iterator it( flavor_input.begin());  //converting the first letter of input to uppercase if not already.

    if (it != flavor_input.end())
        flavor_input[0] = toupper((unsigned char)flavor_input[0]);

    while(++it != flavor_input.end())
    {
        *it = tolower((unsigned char)*it);
    }


    if (flavor_input == "STOP" || flavor_input == "Stop")
        break; 

    valid_option = false; 

    for(int i=0;i<6;i++)  //Checks to see if input matches those of possible inputs.
        if(!flavor_input.compare(flavors[i]))
        {
            valid_option = true;
            break;
        }

        if(!valid_option)
        {
            cout << "Invalid Flavor. Try again.\n\n"; 
            flavor_input.clear();
            continue; 
        }

        for(int i=0;i<6;i++)
        {
            if(!flavor_input.compare(flavors[i])) 
            {
                cout << "Enter how many scoops were sold: ";
                cin >> scoops;
                cin.ignore();
                scoop_count[i] += scoops; 
                scoops = 0; 
                cout << '\n';
                break;
            }
        }
}


for(int i=0;i<6;i++)
{
    if(!scoop_count[i])
        continue;
    else
    {
        cout << "\nDAILY SCOOP REPORT: "<<endl;   
        cout << setiosflags( ios::left )
            << setw( 11 )  << flavors[i]
        << resetiosflags( ios::left )
            << setw( 4 ) << scoop_count[i] << endl;

    }
}


cin.get();
return 0;
}
