#include <iostream>
#include <map>
using namespace std;

// Created by wyattw on 17/01/23
// Version 1.0.0 as of 17/01/23

// Use a map to hold the ticket database
// Alternative: Use a Vector (effiency)
map<int, int> ticketDB;

// void purchaseTicket(int, int)
// Function which takes in ticketID & ticket quantity and adds them to the previously initialized map.
void purchaseTicket(int ticketID, int ticketQty) {
    if (ticketDB.count(ticketID) > 0) {
        ticketDB[ticketID] += ticketQty;
    } else {
        ticketDB[ticketID] = ticketQty;
    }
    cout << "Ticket purchase successful, remaining tickets for event " << ticketID << ": " << ticketDB[ticketID] << endl;
}

// void checkTicket(int)
// Function to check if ID is in map
void checkTicket(int ticketID) {
    if (ticketDB.count(ticketID) > 0) {
        cout << "Remaining tickets for event " << ticketID << ": " << ticketDB[ticketID] << endl;
    } else {
        cout << "Invalid event ID" << endl;
    }
}

// int main()
// Uses purchaseTicket function & checkTicket function to ensure program works correctly.
int main() {
    purchaseTicket(1, 10);
    purchaseTicket(2, 20);
    checkTicket(1);
    checkTicket(2);
    purchaseTicket(1, 2);
    checkTicket(1);
    return 0;
}

