//Omar Kaheel
//CSCI 2270
//Juraj Culak
//Assignment 1

//make sure to compile using C++11 due to some of the functions requring c++11 or newer
//to compile using c++11: g++ Assignment_1.cpp -std=c++11
//to run properly use: ./a.out *insert file name here*

//for the best flow of documentation for this assignmnet please open this file and the ReadMe side by side and align the lines 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// Align here ////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct item 
    {   
        string type;
        int price;
        bool status;
        bool matched;
    };

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// Align here ////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv) 
{

    string file_name;
    file_name = argv[1];


    item Items[100];
     item temp;

     for (int x = 0; x<100; x++){   
        Items[x].matched = 0;
     }

    ifstream myFileStream(file_name);
    if(!myFileStream.is_open())
    {
        cout <<"File has failed to open" << endl;
        return 0;
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// Align here ////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    string type_i;
    string price_i;
    string status_i1;
    bool status_i2;
    int num_sold = 0;

    string mystring;
    string line;
    bool matched_flag = 0;
    int j = 0;
    int counter = 0;

    cout <<"Items sold." << endl;
    cout << "#" << endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// Align here ////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    while(getline(myFileStream, line))
    {
        stringstream ss(line);
        getline(ss, type_i, ',');
        getline(ss, status_i1,',');
        getline(ss, price_i, ',');

        if (status_i1 == " for sale")
        {
            status_i2 = 0;
        } 
        else if (status_i1 == " wanted")
        {
            status_i2 = 1;
        }



        temp.type = type_i;
        temp.status = status_i2;
        temp.price = stoi(price_i);
        
        if (j==0)
        {
            Items[j].type = type_i;
            Items[j].status = status_i2;
            Items[j].price = stoi(price_i);
        } 
        for (int k = 0; k< j; k++)
            {
                bool condition_1 = false;
                matched_flag=0;
                //cout << "k = " << k << "J = " << j<< endl; 
                if (Items[k].type == temp.type && Items[k].matched !=1 && Items[k].status != temp.status && Items[k].price == temp.price)  
                {
                   condition_1 = true;
                }

               if (Items[k].type == temp.type && Items[k].matched !=1 && Items[k].status != temp.status && temp.status == 0 && Items[k].price >= temp.price)
               {
                    condition_1 = true;
               }

               if (Items[k].type == temp.type && Items[k].matched !=1 && Items[k].status != temp.status && temp.status == 1 && Items[k].price <= temp.price)
               {
                    condition_1 == true;
               }

                if (condition_1 == true) 
                {
                    counter ++;
                    cout << temp.type << ", " << temp.price <<endl;
                    Items[k].matched = 1;
                    matched_flag=1;
                    break;
                }

               /* if (Items[k].type == temp.type && Items[k].matched !=1 && Items[k].status != temp.status && Items[k].price == temp.price)
                {

                    cout << temp.type << "" << endl << " index of k: " << k << " "<< temp.status << " priced " << temp.price << " matches "<< Items[k].type << " " <<Items[k].status << " priced " << Items[k].price <<endl;
                    Items[k].matched = 1;
                    matched_flag=1;
                    break;
                }*/

            }
            if(!matched_flag){
                Items[j].type = type_i;
                Items[j].status = status_i2;
                Items[j].price = stoi(price_i);
              //if(j==100) break;
                j++; 
            }

    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////// Align here ////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    cout << "#" << endl;
    cout << "Items remaining in the message board after reading all lines in the file." << endl; 
    cout << "#" << endl;

    for (int u =0; u < 100; u++)
    {

        if(Items[u].matched != 1)
        {  
            if(Items[u].status == 0)
            {
                if(Items[u].type != "")
                {
                    cout << Items[u].type << ", " << "for sale"<< ", "<< Items[u].price <<endl;
                    num_sold++;
                }
            } 

            else 
            {
                if(Items[u].type != "")
                {
                    cout << Items[u].type << ", " << "wanted"<< ", "<< Items[u].price <<endl;
                    num_sold++;
                }
            }
        }
    }

    cout << "Items sold: " << counter << endl;
    cout << "items remaining in the message board after reading all lines in the file: " << (100 - (2*num_sold)) << endl;


}
