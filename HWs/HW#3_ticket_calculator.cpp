//
//
//
/*
Purpose of program: This program is designed to calculate the number of tickets
purchased, as well as the type of tickets. In addition to giving numeric values
on these metrics, it also displays to the user the gross profit from the tickets,
the net profit, and the profit of the theater distributor.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <limits>

using namespace std;

int main()
{
    // declared all necessary variables
    int adultTickets,
        childTickets;

    double grossProfit,
           netProfit,
           distributorProfit;

    const double adultTicketsConst = 11.75,
                 childTicketsConst = 6.55,
                 profitPercent = 0.2;

    string movieTitle,
           theaterLocation;


    // movie title prompt and output
    cout << "Please enter the movie title: ";
    getline(cin, movieTitle);
    cout << "Movie title is " << movieTitle << endl;

    // number of adult priced tickets input and output
    cout << "Please enter the number of adult tickets sold: ";
    cin >> adultTickets;
    cout << "Number of adult tickets sold is " << adultTickets << endl;

    // number of child priced tickets input and output
    cout << "Please enter the number of child tickets sold: ";
    cin >> childTickets;
    cout << "Number of child tickets sold is " << childTickets;

    // theater location prompt and output
    cout << endl << "Please enter the theater's location: ";
    cin.ignore(); // clears cache of previous cin statement to allow for getline
    getline(cin, theaterLocation);
    cout << "Theater location is " << theaterLocation << endl;

    // calculates different profit margins based on info put in by user
    grossProfit = (adultTicketsConst * adultTickets) + (childTicketsConst * childTickets);
    netProfit = (grossProfit * profitPercent);
    distributorProfit = (grossProfit - netProfit);

    // outputs results of previous equations
    cout << fixed << setprecision(2); // turns on fixed
    cout << "Gross profit is $" << grossProfit << endl;
    cout << "Net profit is $" << netProfit << endl;
    cout << "Distributor profit is $" << distributorProfit << endl;

    // starts revenue report output to user
    cout << "\nRevenue Report" << endl;
    cout << "==============" << endl;

    cout << "Movie Title:" << right << setw(16) << " " << movieTitle << endl;
    cout << "Theater Location:" << right << setw(11) << " " << theaterLocation << endl;
    cout << "Adult Tickets Sold:" << right << setw(10) << " " << setfill(' ') << setw(8) << adultTickets << endl;
    cout << "Child Tickets Sold:" << right << setw(10) << " " << setfill(' ') << setw(8) << childTickets << endl;
    cout << "Gross Box Office Profit:" << right << setw(5) << "$" << setfill(' ') << setw(8) << grossProfit << endl;
    cout << "Net Box Office Profit:" << right << setw(7) << "$" << setfill(' ') << setw(8) << netProfit << endl;
    cout << "Amount Paid to Distributor:" << right << setw(2) << "$" << setfill(' ') << setw(8) << distributorProfit << endl;
    cout << resetiosflags(ios::fixed); // turns off fixed

    return 0;
}
