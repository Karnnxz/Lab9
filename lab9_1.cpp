#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double Loan, InterestRate, YearlyPayment;
    double PrevBalance, Interest, Total, Payment, NewBalance;
    int Year = 1;
    
    cout << "Enter initial loan: ";
    cin >> Loan;

    cout << "Enter interest rate per year (%): ";
    cin >> InterestRate;

    cout << "Enter amount you can pay per year: ";
    cin >> YearlyPayment;

    cout << setw(13) << left << "EndOfYear#"
         << setw(13) << left << "PrevBalance"
         << setw(13) << left << "Interest"
         << setw(13) << left << "Total"
         << setw(13) << left << "Payment"
         << setw(13) << left << "NewBalance" << "\n";

    PrevBalance = Loan;

    while (PrevBalance > 0) {
        Interest = PrevBalance * (InterestRate / 100.0);
        Total = PrevBalance + Interest;                 

        if (Total < YearlyPayment) {
            Payment = Total;
        } else {
            Payment = YearlyPayment;
        }

        NewBalance = Total - Payment;

        cout << fixed << setprecision(2);
        cout << setw(13) << left << Year
             << setw(13) << left << PrevBalance
             << setw(13) << left << Interest
             << setw(13) << left << Total
             << setw(13) << left << Payment
             << setw(13) << left << NewBalance << "\n";
             
        PrevBalance = NewBalance;
        Year++;
    }

    return 0;
}
