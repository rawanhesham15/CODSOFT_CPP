#include <bits/stdc++.h>
using namespace std;

class Movie{
    string name;
    string time;
public:

    string seats[11][11];
    Movie(string n, string t){
        for (int i = 0; i < 11; ++i) {
            for (int j = 0; j < 11; ++j) {
                seats[i][j] = '[';
                seats[i][j] += char(65+i);
                seats[i][j] += to_string(j+1);
                seats[i][j] += ']';
            }
        }
        name = n;
        time = t;
    }

    void printSeats(){
        cout << "\n                     __________Seats__________\n\n";
        for (int i = 0; i < 11; ++i) {
            for (int j = 0; j < 11; ++j) {
                cout << seats[i][j];
                if(j == 2 || j == 7){
                    cout << "           ";
                }
            }
            cout << endl;
        }
    }

    void updateSeats(){

    }

    string getName(){
        return name;
    }

    string getTime(){
        return time;
    }
};

class BookingSystem{
private:
    vector<Movie> movies;

public:
    void printMovies(){
        cout << "\n__________Movies__________\n\n";
        for (int i = 0; i < movies.size(); ++i) {
            cout << movies[i].getName() << "   " << movies[i].getTime() << endl;
        }
        cout << endl;
    }

    void addMovie(const Movie movie){
        movies.push_back(movie);
    }

    void bookTickets(){
        string movie;
        string time;
        string seats[11][11];
        bool check = true;
        int num;
        while(check){
            cout << "Enter the name of the movie: ";
            cin >> movie;
            for (int i = 0; i < movies.size(); ++i) {
                if(movies[i].getName() == movie){
                    cout << "-> " << movies[i].getName() << "   " << movies[i].getTime() << endl;
                    cout << "Choose the time you want to attend in it: ";
                    cin >> time;
                    check = false;
                    movies[i].printSeats();
                }
            }
            if(!check){
                cout << "Enter the number of seats you want to book: ";
                cin >> num;
                string arr[num];
                cout << "Choose the seats you want to book (type them separately): ";
                for (int i = 0; i < num; ++i) {
                    cin >> arr[i];
                }
                cout << "Done\n";
            }
        }
    }
};

int main(){
    cout << "----------------------------------------\n";
    cout << "Welcome To Simple Ticket Booking System\n";
    cout << "----------------------------------------\n";

    Movie m1("DARK", "11:00 AM,10:00 AM,5:00 AM");
    Movie m2("AVENGERS", "9:00 AM,10:00 AM,11:00 AM,5:00 PM");
    Movie m3("CAPTAIN AMERICA", "1:00 AM,10:00 AM");
    Movie m4("aaa", "9:00 AM,10:00 AM,11:00 AM,5:00 PM");
    Movie m5("STRANGER THINGS", "4:00 AM,9:00 AM,11:00 AM,2:00 PM");
    Movie m6("MISSION IMPOSSIBLE", "9:00 AM,10:00 AM,11:00 AM,5:00 PM");
    Movie m7("WONDER WOMAN", "3:00 AM,6:00 AM,8:00 AM");
    Movie m8("ANT MAN", "9:00 AM");

    BookingSystem b;
    b.addMovie(m1);
    b.addMovie(m2);
    b.addMovie(m3);
    b.addMovie(m4);
    b.addMovie(m5);
    b.addMovie(m6);
    b.addMovie(m7);
    b.addMovie(m8);

    int choice;

    do{
        cout << "1- View All Movies.\n";
        cout << "2- Book Tickets.\n";
        cout << "3- Exit.\n";
        cout << "Enter what do you want to do: ";
        cin >> choice;
        switch (choice) {
            case 1:
                b.printMovies();
                break;
            case 2:
                b.bookTickets();
            case 3:
                return 0;
        }
    }while(choice != 3);
}