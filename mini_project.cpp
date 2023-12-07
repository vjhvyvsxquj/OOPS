#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double calculateEMI(double principal, double rate, double time) {
    rate /= 12 * 100; // Monthly interest rate
    time *= 12; // Time in months

    double emi = (principal * rate * pow(1 + rate, time)) / (pow(1 + rate, time) - 1);
    return emi;
}

int main() {
    ofstream outputFile("EMI_Details.txt", ios::app); // File to store EMI details
    if (!outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int choice;
    do {
        cout<<"******* FINANCE MANGEMENT SYSTEM *********"<<endl;
        cout << "Select Bank:\n";
        cout << "1. HDFC BANK(@8.5 pcpa)\n2. SBI BANK(@9.0 pcpa)\n3. YES BANK(@9.5 pcpa)\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double principal, time;
                cout << "Enter principal amount for HDFC bank: ";
                cin >> principal;
                cout << "Enter tenure in years: ";
                cin >> time;

                double emi = calculateEMI(principal, 8.5, time); 

                cout << "EMI for HDFC Bank: Rs." << emi << endl;

                
                outputFile << "Bank: HDFC bank \tPrincipal: Rs." << principal
                           << "\tTenure: " << time << " years\tEMI: Rs." << emi << endl;
                break;
            }
            case 2: {
                double principal, time;
                cout << "Enter principal amount for SBI Bank: ";
                cin >> principal;
                cout << "Enter tenure in years: ";
                cin >> time;

                double emi = calculateEMI(principal, 9.0, time); 

                cout << "EMI for SBI Bank: Rs." << emi << endl;

                
                outputFile << "Bank: SBI bank \tPrincipal: Rs." << principal
                           << "\tTenure: " << time << " years\tEMI: Rs." << emi << endl;
                break;
            }
            case 3: {
                double principal, time;
                cout << "Enter principal amount for YES Bank: ";
                cin >> principal;
                cout << "Enter tenure in years: ";
                cin >> time;

                double emi = calculateEMI(principal, 9.5, time); 

                cout << "EMI for YES Bank: Rs." << emi << endl;

                
                outputFile << "Bank: YES bank \tPrincipal: Rs." << principal
                           << "\tTenure: " << time << " years\tEMI: Rs." << emi << endl;
                break;
            }
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    outputFile.close(); // Close the file
    return 0;
}