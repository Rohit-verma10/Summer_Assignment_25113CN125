#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Seat {
public:
    int seatNumber;
    bool isBooked;
    string passengerName;

    Seat(int number) {
        seatNumber = number;
        isBooked = false;
        passengerName = "";
    }
};

class Show {
private:
    string movieName;
    string showTime;
    double price;
    vector<vector<Seat>> seatingArrangement;
    int rows;
    int cols;

public:
    Show(string name, string time, double ticketPrice, int r, int c) {
        movieName = name;
        showTime = time;
        price = ticketPrice;
        rows = r;
        cols = c;

        int seatCounter = 1;
        for (int i = 0; i < rows; ++i) {
            vector<Seat> rowSeats;
            for (int j = 0; j < cols; ++j) {
                rowSeats.push_back(Seat(seatCounter++));
            }
            seatingArrangement.push_back(rowSeats);
        }
    }

    string getMovieName() const { return movieName; }
    string getShowTime() const { return showTime; }
    double getPrice() const { return price; }

    void displaySeats() const {
        cout << "\n--- SEATING LAYOUT FOR " << movieName << " (" << showTime << ") ---" << endl;
        cout << "   [ SCREEN THIS WAY ]\n\n";

        for (int i = 0; i < rows; ++i) {
            cout << "Row " << (char)('A' + i) << " ->  ";
            for (int j = 0; j < cols; ++j) {
                if (seatingArrangement[i][j].isBooked) {
                    cout << "[ X ] "; // Booked seat
                } else {
                    cout << "[" << setw(2) << seatingArrangement[i][j].seatNumber << "] "; // Available seat
                }
            }
            cout << "\n";
        }
        cout << "\nLegend: [X] = Booked, [Number] = Available\n";
    }


    bool bookTicket(int seatNum, string name) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (seatingArrangement[i][j].seatNumber == seatNum) {
                    if (seatingArrangement[i][j].isBooked) {
                        cout << "\nError: Seat " << seatNum << " is already booked!\n";
                        return false;
                    }
                    seatingArrangement[i][j].isBooked = true;
                    seatingArrangement[i][j].passengerName = name;
                    return true;
                }
            }
        }
        cout << "\nError: Invalid seat number!\n";
        return false;
    }
};


int main() {
    
    vector<Show> shows;
    shows.push_back(Show("Inception", "12:00 PM", 12.50, 5, 6));
    shows.push_back(Show("Interstellar", "04:30 PM", 15.00, 5, 6));
    shows.push_back(Show("The Dark Knight", "09:00 PM", 14.00, 5, 6));

    int mainChoice;

    do {
        cout << "\n=====================================";
        cout << "\n      TICKET BOOKING SYSTEM          ";
        cout << "\n=====================================";
        cout << "\n1. View Available Shows";
        cout << "\n2. Book a Ticket";
        cout << "\n3. Exit";
        cout << "\nEnter your choice (1-3): ";
        cin >> mainChoice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (mainChoice) {
            case 1: {
                cout << "\nAvailable Movies & Timings:\n";
                for (size_t i = 0; i < shows.size(); ++i) {
                    cout << i + 1 << ". " << shows[i].getMovieName() 
                         << " | Time: " << shows[i].getShowTime() 
                         << " | Price: $" << fixed << setprecision(2) << shows[i].getPrice() << "\n";
                }
                break;
            }
            case 2: {
                cout << "\nSelect a movie show to book:\n";
                for (size_t i = 0; i < shows.size(); ++i) {
                    cout << i + 1 << ". " << shows[i].getMovieName() << " (" << shows[i].getShowTime() << ")\n";
                }
                cout << "Enter show number: ";
                int showSelection;
                cin >> showSelection;

                if (showSelection < 1 || showSelection > static_cast<int>(shows.size())) {
                    cout << "Invalid show selection.\n";
                    break;
                }

                Show& selectedShow = shows[showSelection - 1];
                selectedShow.displaySeats();

                cout << "\nEnter seat number to book: ";
                int seatNum;
                cin >> seatNum;

                cout << "Enter customer name: ";
                string name;
                cin.ignore(); 
                getline(cin, name);

                if (selectedShow.bookTicket(seatNum, name)) {
                    cout << "\n=====================================";
                    cout << "\n      TICKET BOOKED SUCCESSFULLY!    ";
                    cout << "\n=====================================";
                    cout << "\nCustomer: " << name;
                    cout << "\nMovie:    " << selectedShow.getMovieName();
                    cout << "\nTime:     " << selectedShow.getShowTime();
                    cout << "\nSeat No:  " << seatNum;
                    cout << "\nTotal:    $" << selectedShow.getPrice();
                    cout << "\n=====================================\n";
                }
                break;
            }
            case 3:
                cout << "\nThank you for using the Ticket Booking System!\n";
                break;
            default:
                cout << "\nInvalid selection. Try again.\n";
        }
    } while (mainChoice != 3);

    return 0;
}