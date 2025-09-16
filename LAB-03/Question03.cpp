/*write a simple airline ticket reservation program. The program should display a menu with the following options:
reserve a ticket, cancel a reservation, check whether a ticket is reserved for particular person, and display the
passengers. the information is maintained on a alphabetized linked list of names. in simple version of the
program, assume that tickets are reserved for only one flight. In a fuller version, place no limit on the number of
flights. create a linked list of flights with each node including a pointer to a linked list of passengers*/
#include <bits/stdc++.h> // for including all the libraries
using namespace std;

struct Passenger
{
    string name;
    Passenger *next;
    Passenger(string n) : name(n), next(nullptr) {}
};

//insert passenfer in alphabatic order
Passenger *reserveTicket(Passenger *head, string name)
{
    Passenger *newNode = new Passenger(name);

    if (!head || head->name > name)
    {
        newNode->next = head;
        return newNode;
    }

    Passenger *temp = head;
    while (temp->next && temp->next->name < name)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}
Passenger *cancelTicket(Passenger *head, string name)
{
    if (!head)
        return nullptr;

    if (head->name == name)
    {
        Passenger *del = head;
        head = head->next;
        delete del;
        return head;
    }

    Passenger *temp = head;
    while (temp->next && temp->next->name != name)
    {
        temp = temp->next;
    }

    if (temp->next)
    {
        Passenger *del = temp->next;
        temp->next = temp->next->next;
        delete del;
    }
    return head;
}
bool isReserved(Passenger *head, string name)
{
    Passenger *temp = head;
    while (temp)
    {
        if (temp->name == name)
            return true;
        temp = temp->next;
    }
    return false;
}
void displayPassengers(Passenger *head)
{
    if (!head)
    {
        cout << "No reservations yet.\n";
        return;
    }
    Passenger *temp = head;
    cout << "Passengers: ";
    while (temp)
    {
        cout << temp->name << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Passenger *head = nullptr;
    int choice;
    string name;

    do
    {
        cout << "\n--- Airline Reservation Menu ---\n";
        cout << "1. Reserve Ticket\n";
        cout << "2. Cancel Reservation\n";
        cout << "3. Check Reservation\n";
        cout << "4. Display Passengers\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter passenger name: ";
            cin >> name;
            head = reserveTicket(head, name);
            break;

        case 2:
            cout << "Enter passenger name to cancel: ";
            cin >> name;
            head = cancelTicket(head, name);
            break;

        case 3:
            cout << "Enter passenger name to check: ";
            cin >> name;
            if (isReserved(head, name))
                cout << name << " has a reservation.\n";
            else
                cout << name << " does not have a reservation.\n";
            break;

        case 4:
            displayPassengers(head);
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
