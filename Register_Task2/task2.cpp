#include<iostream>
#include<string>
#include<fstream>

using namespace std;
bool CheckUsername(const string& file_name){
    std::ifstream infile(file_name);
    return infile.good();
}
void Signup(){
string username, password;
bool validuser = false;
cout<<"-----------------------------------------"<<endl;
cout<<"Sign-up: "<<endl;
while(!validuser){
cout<<"Enter your username: "<<endl;
cin>>username;

string file_name = username + ".txt";
    if (CheckUsername(file_name)) {
        cout << "Username already exists. Please choose another username."<<endl;
        cin.clear();
    }
    else validuser = true;
}
cout<<"Enter your password: "<<endl;
cin >> password;
string file_name = username + ".txt";
ofstream user_file(file_name);
    if (user_file.is_open()) {
        user_file << password;
        user_file.close();
        cout << "You have successfully created a new account."<<endl;
        cout<<"-----------------------------------------"<<endl;
    } else {
        cerr << "Error opening file."<<endl;
    }
}

bool Login(){
string username,password;
string realpassword;
bool validuser = false;
bool validpass = false;
int passtrial = 0;
cout<<"-----------------------------------------"<<endl;
cout<<"Log-in: "<<endl;

    while(!validuser){
cout<<"Enter your username: "<<endl;
cin>>username;

string file_name = username + ".txt";
    if (!CheckUsername(file_name)) {
        cout << "That username does not exist. Please enter the correct username or sign-up."<<endl;
        cin.clear();
        
    }
    else validuser = true;}


    while(!validpass){
cout<<"Enter your password: "<<endl;
cin>>password;
string file_name = username + ".txt";
    ifstream user_file(file_name);
    if (user_file.is_open()) {
        getline(user_file, realpassword);
        user_file.close();}
        else {
        cerr << "Error opening file."<<endl;
        cout<<"-----------------------------------------"<<endl;}

        if (password == realpassword) {
            validpass = true;
            return true;
        } 
        if(password !=realpassword){
        if(passtrial <4){
            cout << "Invalid password. Please try again."<<endl;
            cin.clear();
            validpass = false;
            passtrial++;}


            else cout <<"Too many invalid attempts. Try again later."<<endl;
        }
    }
    
    return false;

}


int main(){
int choice;
bool ValidChoice = false;
cout<<"-----------------------------------------"<<endl;
cout <<"Welcome! Please choose whether you want to log-in or create a new account:"<<endl<<endl;
cout<<"1. Log-in"<<endl<<"2.Sign-up"<<endl;

while(!ValidChoice){
    cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail() || (choice != 1 && choice != 2)) {
            cin.clear(); 
            cout << "Invalid choice. Please enter 1 to Log-in or 2 to Sign-up."<<endl;
        } else {
            ValidChoice = true;
        }
    }
if(choice == 1){

    if(Login()){
        cout<<"You have successfully logged in!"<<endl;
        cout<<"-----------------------------------------"<<endl;
    }

}

else if (choice == 2){
    Signup();
}

else
    return 0;
}