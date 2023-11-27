#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream> 
#include <chrono>
#include <ctime>
#include <iomanip>
#include <typeinfo>
#include <Windows.h>

using namespace std;

class Dorm {
private: //Details about dorm's residents
    string bed_status; //'Occupied' & 'Empty' 
    string res_Firstname;
    string res_Lastname;
    string res_gender;
    int res_id;
    string res_email;
    string res_contactnum;
    int room_num; // 101 - 110 & 201 - 210

public:
    //GETTERS
    string getBedStatus(){ return bed_status; }
    string getFirstName(){ return res_Firstname; }
    string getLastName() { return res_Lastname; }
    string getGender(){ return res_gender; }
    int getID(){ return res_id; }
    string getEmail(){ return res_email; }
    string getContact(){ return res_contactnum; }
    int getRoom(){ return room_num; }

    //SETTERS
    void setBedStatus(string BedStatus){bed_status = BedStatus;}
    void setFirstName(string firstName) {res_Firstname = firstName; }
    void setLastName(string lastName) {res_Lastname = lastName; }
    void setGender(string gender) {res_gender = gender; }
    void setID(int ID) {res_id = ID;}
    void setEmail(string email){ res_email = email; }
    void setContact(string contactNum){ res_contactnum = contactNum; }
    void setRoom(int roomNo){ room_num = roomNo; }



    string arrangeLetters(string word){
        string newWord = "";

        for (int x = 0; x < word.length(); x++){
            if (x == 0)
                newWord += toupper(word[x]);
            else
                newWord += tolower(word[x]);
        }
        return newWord;
    }

    void emptyRoomsList(Dorm Residents[]){
        cout << "Empty Rooms Are: " << endl;

        for (int k = 1; k < 21; k++){
            if (Residents[k].getBedStatus() == "Empty"){
                cout << '\t' << "-  " << Residents[k].getRoom();
            }
        }        
    }


    int modifyLineInFile(int ModifyLineNum, string forModification[], string combinedText){ //MODIFYING ONE LINE
        //READ FROM THE FILE
        string currentFileName = "dorm.txt";
        ifstream readFile(currentFileName);

        if (!readFile.is_open()) {
            cerr << "File Not opened." << std::endl;
            return -1;
        }

        int currentLineNum = 0;
        string oneLine_Text;

        while (getline(readFile, oneLine_Text)){

            if (currentLineNum == ModifyLineNum) {
                forModification[currentLineNum] = combinedText;
            }

            else if (currentLineNum != ModifyLineNum){
                forModification[currentLineNum] = oneLine_Text;
            }

            currentLineNum += 1;
        }
        readFile.close();

        //WRITE TO THE FILE
        ofstream writeFile(currentFileName);

        if (!writeFile.is_open()) {
            cerr << "Write File Not Opened" << endl;
            return -1;
        }

        for (int i = 0; i< currentLineNum; i++){
            writeFile << forModification[i] << endl;
        }
        writeFile.close();
        
        return 0;
    }


    void moveIn(Dorm Residents[], int SIZE, string forModification[], vector<int>& storeStudentID){
        emptyRoomsList(Residents);

        int EmptyRoomNo;
        cout << endl << endl << "Which room do you want to move in? ";
        cin >> EmptyRoomNo;
        bool flag = false;

        for (int k = 1; k < SIZE; k++){
            if (Residents[k].getRoom() == EmptyRoomNo){
                flag = true;

                if (Residents[k].getBedStatus() == "Occupied")
                    cout << "This Room is Occupied. Please Enter A Valid Room Number" << endl;
                
                else if (Residents[k].getBedStatus() == "Empty"){
                                 
                    cout << "What is your STUDENT ID? ";
                    int sid;

                    if (cin >> sid){
                    }             
                    else{
                        cout << "ERROR! Enter a valid student id of INTEGER type" << endl;
                        break;
                    }

                    bool end = false;

                    for (int vectorIndex = 0; vectorIndex < storeStudentID.size(); vectorIndex++){
                        if (sid == storeStudentID[vectorIndex]){
                            cout << "ALERT!!! " << sid << " is NOT UNIQUE. You are NOT a verified student!!" << endl;
                            end = true;
                            break;
                        }
                    }
                    if (end == false){
                        cout << "What is your FIRST NAME? ";
                        string rfname;

                        if (cin >> rfname)
                            rfname = arrangeLetters(rfname);
                        else{
                            cout << "ERROR! Enter a valid student id of INTEGER type" << endl;
                            break;
                        }

                        cout << "What is your LAST NAME? ";
                        string rlname;
                        cin >> rlname;
                        rlname = arrangeLetters(rlname);

                        cout << "What GENDER do you identify with? ";
                        string gender;  
                        cin >> gender;
                        gender = arrangeLetters(gender);                    

                        cout << "What is your EMAIL ADDRESS? ";
                        string email;
                        cin >> email;

                        cout << "What is your PHONE NUMBER? ";
                        string phoneno;
                        cin >> phoneno;
                        
                        string status = "Occupied";
                        string combinedText = status + '\t' + to_string(EmptyRoomNo) + '\t' + rfname + '\t' + '\t' + rlname + '\t' + '\t' + gender + '\t' + to_string(sid) + '\t' + email + '\t' + phoneno;

                        modifyLineInFile(k, forModification, combinedText);                    

                        Residents[k].setFirstName(rfname);
                        Residents[k].setLastName(rlname);
                        Residents[k].setGender(gender);
                        Residents[k].setID(sid);
                        Residents[k].setEmail(email);
                        Residents[k].setContact(phoneno);
                        Residents[k].setBedStatus("Occupied");

                        cout << "Congratulations! You are MOVED IN" << endl << endl;
                        break;

                    }
                    else
                        break;
                }
                else
                    continue;
            }
        }
        if (flag == false)   
            cout << "The entered room number does NOT exist" << endl;
    }



    void MoveOut(Dorm Residents[], int SIZE, string forModification[]){
        int MoveOutRoomNo;
        cout << endl << "Which ROOM NUMBER do you want to MOVE OUT? ";
        cin >> MoveOutRoomNo;

        bool work = false;

        for (int k = 1; k < SIZE; k++){

            if (Residents[k].getRoom() == MoveOutRoomNo){
                if (Residents[k].getBedStatus() == "Empty")
                    cout << "This Room is already Empty. Please Enter A Valid Room Number" << endl;

                else if (Residents[k].getBedStatus() == "Occupied"){
                    string bstatus = "Empty";
                    string emptyCombinedText = bstatus + '\t' + '\t' + to_string(MoveOutRoomNo) + '\t' + "" + '\t' + "" + '\t' + "" + '\t' + "" + '\t' + "" + '\t' + "";
                    
                    modifyLineInFile(k, forModification, emptyCombinedText);                    

                    Residents[k].setFirstName("");
                    Residents[k].setLastName("");
                    Residents[k].setGender("");
                    Residents[k].setID(0);
                    Residents[k].setEmail("");
                    Residents[k].setContact("");
                    Residents[k].setBedStatus("Empty");

                    visitorCheckOut(forModification, MoveOutRoomNo);

                    cout << "Congratulations! You and your visitor (if any) are MOVED OUT" << endl << endl;
                    work = true;
                    break;
                }
            }
        }
        if (work == false)
            cout << "No such room exist " << endl;
    }



    int visitorCheckIn(Dorm Residents[], string forModification[], vector<int>& storeRoomNumber, vector<int>& storeStudentID){
        string hostFName;
        cout << "Dear @Visitor, FIRST NAME of the person who invited you? ";
        cin >> hostFName;
        
        hostFName = arrangeLetters(hostFName);
        bool residentVerificationStatus = false;

        for (int a = 1; a < 21; a++){
            if (hostFName == Residents[a].getFirstName()){

                residentVerificationStatus = true; //the resident searched by the visitor found                
                bool quit = false;
                int hostRoomNo = Residents[a].getRoom();

                //CHECKS IF THAT ROOM ALREADY HAS A VISITOR 
                for (int vector_index = 0; vector_index < storeRoomNumber.size(); vector_index++){

                    if (hostRoomNo == storeRoomNumber[vector_index]){
                        cout << Residents[a].getFirstName() << " already has a guest checked in - so NO MORE GUEST" << endl;
                        quit = true;
                        break;
                    }
                }
                if (quit == false){

                    cout << "What is the STUDENT ID of " << Residents[a].getFirstName() << "? ";
                    int hostID;
                    cin >> hostID;

                    if (hostID != Residents[a].getID()){
                        cout << "ALERT! The entered STUDENT ID is incorrect. TRY AGAIN!";
                        break;
                    }
                    int visRoom = Residents[a].getRoom();

                    string visGender;
                    cout << "@Visitor, What gender do you identify with? ";
                    cin >> visGender;
                    visGender = arrangeLetters(visGender);


                    if (visGender != Residents[a].getGender()){
                        cout << "@Visitor, Due to gender difference, you are NOT allowed to move in!";
                        break;
                    }

                    auto presentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
                    tm* timeInfo = localtime(&presentTime);
                    int checkInHour = timeInfo->tm_hour; 
                    int checkInDay = timeInfo->tm_mday;               
                        
                    if (checkInHour < 6){
                        cout << "It is MIDNIGHT, so CHECK-IN is NOT allowed" << endl;
                    }

                    else{
                        cout << "What is your STUDENT ID @Visitor? ";
                        int visID;

                        if (cin >> visID){
                        }             
                        else{
                            cout << "ERROR! Enter a valid student id of INTEGER type" << endl;
                            break;
                        }

                        bool end = false;

                        for (int vectorIndex = 0; vectorIndex < storeStudentID.size(); vectorIndex++){
                            if (visID == storeStudentID[vectorIndex]){
                                cout << "ALERT!!! " << visID << " is NOT a UNIQUE Student ID. You are NOT a verified student!!" << endl;
                                end = true;
                                break;
                            }
                        }
                        if (end == false){
        
                            cout << endl << "What is your FIRST NAME @Visitor? ";
                            string visFName;
                            cin >> visFName;
                            visFName = arrangeLetters(visFName);

                            cout << "What is your LAST NAME @Visitor? ";
                            string visLName;
                            cin >> visLName;
                            visLName = arrangeLetters(visLName);

                            cout << "What is your EMAIL ADDRESS @Visitor? ";
                            string visEmail;
                            cin >> visEmail;                    

                            cout << "What is your CONTACT NUMBER @Visitor? ";
                            string visContact;
                            cin >> visContact;


                            string personType = "Visitor";
                            string visCombinedData = personType + '\t' + '\t' + to_string(visRoom) + '\t' + visFName + '\t' + '\t' + visLName + '\t' + '\t' + visGender + '\t' + to_string(visID) + '\t' + '\t' + visEmail + '\t' + visContact + '\t' + '\t' + '\t' + '\t' + to_string(checkInDay);
                            ofstream appendFile("dorm.txt", ios::app); //open the FILE in APPEND mode

                            if (!appendFile.is_open()) {
                                cerr << "Append File Not Opened" << endl;
                                return -1;
                            }
                            appendFile << visCombinedData << endl;
                            appendFile.close();

                            cout << "Congratulations VISITOR! You are allowed to CHECK IN" << endl;
                            break;
                        }
                        else
                            break;
                    }
                }
                else
                    break;
            }
        }

        if (residentVerificationStatus == false) 
            cout << "SORRY! The entered person does NOT live in this hall!!!" << endl;
    return 0;
    }



    int visitorCheckOut(string forModification[], int enteredRoomNo){
        ifstream readFile("dorm.txt"); //INPUT FILE to READ from the file

        if (!readFile.is_open()) {
            cerr << "File NOT opened successfully!" << endl;
        }

        string eachLine;
        int lineNumber = 0;
        bool flag = false;

        while (getline(readFile, eachLine)) {
            if (lineNumber <= 20)
                lineNumber++;

            else{
                if (eachLine.empty()){ //accurately works for empty line (VERIFIED!)
                    lineNumber++;
                    continue;
                }

                int countWord = 1;
                istringstream splitWord(eachLine);
                string eachWord;

                while (splitWord >> eachWord) {
                    if ((countWord==2) || (flag == true)){

                        if (countWord == 9){

                            auto thisTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
                            tm* timeInfo = localtime(&thisTime);
                            int checkOutDay= timeInfo->tm_mday;

                            if (stoi(eachWord)!=checkOutDay){

                                cout << "@Visitor, your CHECK-IN Day was " << stoi(eachWord) << endl;
                                cout << "ALERT! You OVERSTAYED! You should have checked out before 12 a.m. of day " << stoi(eachWord) << endl;
                                MessageBeep(MB_ICONEXCLAMATION);
                            }
                            string completeText = "";
                            cout << endl << "VISITOR CHECK-OUT done successfully!!!" << endl;
                            modifyLineInFile(lineNumber, forModification, completeText);
                            break;
                        }

                        else if (countWord == 2){
                            if (std::stoi(eachWord) == enteredRoomNo)
                                flag = true;
                        }
                    }
                    countWord++;
                }
                lineNumber++;
            }
        }
        if (flag == false)
            cout << "ERROR!!! There is NO visitor checked into the Room Number " << enteredRoomNo << endl;
    return 0;
    }
};



void studentIDVerification (vector<int>& storeStudentID){
    ifstream readingFile("dorm.txt"); //INPUT FILE for READING from the file

    if (!readingFile.is_open()) {
        cerr << "File NOT opened successfully!" << endl;
    }

    int numLine = 0;
    string everyLine;

    while (getline(readingFile, everyLine)) {

        if (numLine > 0){
            int Countword = 0;
            istringstream splitWord(everyLine);
            string everyWord;

            while (splitWord >> everyWord) {
                if (Countword == 5){

                    try {
                        storeStudentID.push_back(stoi(everyWord));
                        break;
                    }
                    catch (const invalid_argument& e) {
                        cerr << "1 Issue with integer conversion on line " << numLine + 1 << ": " << e.what() << endl;
                    }
                    catch (const out_of_range& e) {
                        cerr << "2 Issue with integer conversion on line " << numLine + 1 << ": Out of range" << endl;
                    }
                }
                else
                    Countword++;
            }
        }
        numLine++;       
    }
    readingFile.close();
}



void visitorsRoomNumber(int SIZE, vector<int>& storeRoomNumber){
    ifstream readFile("dorm.txt"); //INPUT FILE to READ from the file

    if (!readFile.is_open()) {
        cerr << "File NOT opened successfully!" << endl;
    }

    int numLine = 0;
    string eachLine;

    while (getline(readFile, eachLine)) {
        if (numLine < SIZE)
            numLine++;
        else{
            int Countword = 0;
            istringstream splitWord(eachLine);
            string eachWord;

            while (splitWord >> eachWord) {
                if (Countword == 1){
                    storeRoomNumber.push_back(stoi(eachWord));
                    break;
                }
                else
                    Countword++;
            }
        }
    }
    readFile.close();
}



int fill_array(Dorm Residents[], int SIZE) {

    string pathFile = "dorm.txt"; //INPUT FILE
    ifstream file; //ifstream => input operations on files; Fileinput => instance of 'ifstream'
    file.open(pathFile); 

    if (file.is_open()) {        
        int line_num = 0;
        string one_line;

        while (line_num < SIZE && getline(file, one_line)) {
            int word_count = 0;
            if (line_num > 0){ //do NOT select first line of text file as it's a heading

                istringstream splitWord(one_line);
                string word;

                while (splitWord >> word) {

                    try{
                        if (word_count == 0)
                            Residents[line_num].setBedStatus(word);
                        else if (word_count == 1)
                            Residents[line_num].setRoom(stoi(word)); 
                        else if (word_count == 2)
                            Residents[line_num].setFirstName(word);
                        else if (word_count == 3)
                            Residents[line_num].setLastName(word);
                        else if (word_count == 4) 
                            Residents[line_num].setGender(word);
                        else if (word_count == 5) 
                            Residents[line_num].setID(stoi(word));
                        else if (word_count == 6) 
                            Residents[line_num].setEmail(word);
                        else if (word_count == 7) 
                            Residents[line_num].setContact(word);                            
                        word_count++;
                    }

                    catch (invalid_argument& error) {
                        cerr << "Exception: " << error.what() << " ARGUMENT IS NOT VALID " << endl;
        
                    } 
                    catch (out_of_range& err) {
                        cerr << "Exception: " << err.what() << " VALUE NOT WITHIN RANGE " << endl;
                    }   
                }
            }
            line_num++;
        }

    file.close();
    return 0;
    }
    else{
        return -1;
    }
}



void DisplayResult(Dorm Residents[], int SIZE){
    for (int j = 1; j < SIZE; j++){

        if (Residents[j].getBedStatus() == "Occupied"){

            cout << j << endl << " Room Number: " << Residents[j].getRoom() << endl;
            cout << '\t' << "First Name: " << Residents[j].getFirstName() << endl;
            cout << '\t' << "Last Name: " << Residents[j].getLastName() << endl;
            cout << '\t' << "Gender: " << Residents[j].getGender() << endl;
            cout << '\t' << "ID: " << Residents[j].getID() << endl;
            cout << '\t' << "Email Address: " << Residents[j].getEmail() << endl;
            cout << '\t' << "Contact Number: " << Residents[j].getContact() << endl << endl;
        }

        else if (Residents[j].getBedStatus() == "Empty"){
            cout << endl << j<< " Room Number: " << Residents[j].getRoom() << endl;
            cout << '\t' << "Status: " << Residents[j].getBedStatus() << endl << endl;
        }
    }
}
