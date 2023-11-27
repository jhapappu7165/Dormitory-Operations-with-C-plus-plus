#include "Dorm.h"

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;


int main(){

    const int SIZE = 21;
    Dorm Residents[SIZE];
    string forModification[SIZE];
    vector<int> storeRoomNumber;
    vector<int> storeStudentID;


    int return_num = fill_array(Residents, SIZE);
    if (return_num == -1){
        cout << "Unable to open file! " << endl;
        return 1;
    }
    
    else if (return_num == 0){
        Dorm Hillcrest;

        char dormChoice;
        cout << "Are You? " << endl << '\t' << "- A Resident To Move IN ('A'): " << endl << '\t' << "- A Resident To Move OUT ('B'): " << endl << '\t' << "- A Visitor To Check IN ('C'): " << endl << '\t' << "- A Visitor To Check OUT ('D'): " << endl << '\t' << "- View the Current Status of Residents ('E'): " << endl;

        cin >> dormChoice;
        cin.ignore();  

        if (!isalpha(dormChoice)) { //Determines if a character is an alphabetic letter (uppercase/lowercase) & returns True/False
            cout << "ERROR! Enter a character." << endl;
            return -1;
        }
        dormChoice = toupper(dormChoice);

        switch(dormChoice){

            case ('A'):
                studentIDVerification (storeStudentID);
                Hillcrest.moveIn(Residents, SIZE, forModification, storeStudentID);
                break;

            case ('B'):
                Hillcrest.MoveOut(Residents, SIZE, forModification);
                break;

            case ('C'):
                visitorsRoomNumber(SIZE, storeRoomNumber);
                studentIDVerification (storeStudentID);
                Hillcrest.visitorCheckIn(Residents, forModification, storeRoomNumber, storeStudentID);
                break;

            case('D'):
                cout <<  "@Visitor, Enter the room number you checked in? ";
                int enteredRoomNo;
                cin >> enteredRoomNo;
                Hillcrest.visitorCheckOut(forModification, enteredRoomNo);
                break;
            
            case('E'):
                DisplayResult(Residents, SIZE); //show current status of rooms after MOVE IN
                break;
            

            default:
                cout << "Please! Enter a Valid Character among ('A', 'B', 'C', 'D', 'E') in any case " << endl;
                break;
        }
    }
    return 0;
}
