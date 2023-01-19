#include <iostream>
#include <string>

// Created by wyattw on 19/01/23
// Version 1.1 as of 19/01/23

class Ticket {

private:
    // Fields for ticket object
    int ticketNumber;
    std::string staffID;
    std::string ticketCreatorName;
    std::string contactEmail;
    std::string description;
    std::string response;
    std::string status;
    static int nextTicketNumber;

public:
    // Set fields for ticket object here, public access here is replicated and not set directly.
    Ticket(std::string staffID, std::string ticketCreatorName, std::string contactEmail, std::string description) {
        // +2000 to keep ontop of ticket number requirement.
        this->ticketNumber = nextTicketNumber + 2000;
        nextTicketNumber++;
        this->staffID = staffID;
        this->ticketCreatorName = ticketCreatorName;
        this->contactEmail = contactEmail;
        this->description = description;
        this->response = "Not Yet Provided";
        this->status = "Open";
    }

    // Method to submit a ticket
    void submitTicket() {
        std::cout << "Ticket submitted successfully!" << std::endl;
    }

    // Method to resolve a ticket
    void resolveTicket() {
        // Password Change functionality
        // TODO: Use a switch or something of the sort (ex: List with enum) to create
        if (description.find("Password Change") != std::string::npos) {
            std::string newPassword = staffID.substr(0, 2) + ticketCreatorName.substr(0, 3);
            std::cout << "New password: " << newPassword << std::endl;
        }
        response = "Provided";
        status = "Closed";
        
        if(status != "Closed")
            std::cout << "Unable to resolve ticket, please contact your administrator." << std::endl;
        else
            std::cout << "Ticket resolved." << std::endl;
    }

    // Method to reopen a ticket
    void reopenTicket() {
        status = "Reopened";
    }

    // Method to provide a response to a ticket
    void provideResponse(std::string response) {
        this->response = response;
    }

    // Method to display ticket information
    void displayTicket() {
        std::cout << std::endl; // Seperate ticket display from rest of output.
        std::cout << "Ticket Number: " << ticketNumber << std::endl;
        std::cout << "Creator of Ticket: " << ticketCreatorName << std::endl;
        std::cout << "Staff ID: " << staffID << std::endl;
        std::cout << "Email address: " << contactEmail << std::endl;
        std::cout << "Description of the issue: " << description << std::endl;
        std::cout << "Response from the IT department: " << response << std::endl;
        std::cout << "Ticket status: " << status << std::endl;
    }
};

int Ticket::nextTicketNumber = 0;

int main() {
    // Internal stat clock
    int numOpen = 0, numClosed = 0, numResolved = 0;

    // Creating a new ticket
    // Usage: Constructor object(int staffid, string email, string reason)
    // See line 17 for declaration
    Ticket ticket1("123456", "John Deer", "johndeer@johndeer.co.nz", "Password Change");
    numOpen++; // Add new ticket to counter

    // Submitting the ticket
    ticket1.submitTicket(); // Submit the ticket for review.

    // Resolving the ticket
    ticket1.resolveTicket();
    numOpen--; // +1 is now -1 = 0
    numClosed++; // 0 is now +1 = 1
    numResolved++; // 0 is now +1 = 1 

    // Displaying the ticket
    ticket1.displayTicket();

    // Creating a new ticket
    Ticket ticket2("234567", "Bunnings", "bunnings@example.com", "Help with software installation");
    numOpen++; // 0 is now +1 = 1

    // Submitting the ticket
    ticket2.submitTicket();

    // Providing a response to the ticket
    ticket2.provideResponse("We have sent you an email with instructions on how to install the software.");
    ticket2.resolveTicket();
    numOpen--; // 1 is now -1 = 0
    numClosed++; // 1 is now +1 = 2
    numResolved++; // 1 is now +1 = 2

    // Reopening the ticket
    ticket2.reopenTicket();
    numOpen++; // 0 is now +1 = 1
    numClosed--; // 2 is now -1 = 1
    numResolved--; // 2 is now -1 = 1

    // Displaying the ticket
    ticket2.displayTicket();

    // Displaying statistics
    std::cout << std::endl;
    std::cout << "Ticket Statistics" << std::endl;
    std::cout << "Number of open tickets: " << numOpen << std::endl;
    std::cout << "Number of closed tickets: " << numClosed << std::endl;
    std::cout << "Number of resolved tickets: " << numResolved << std::endl;

    return 0;
}
