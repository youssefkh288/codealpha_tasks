#include<iostream>
#include<string>
#include <limits>
using namespace std;

void welcomeMessage(){
    cout<<"-----------------------------------------------"<<endl;
    cout<<"Welcome to the CGPA calculator!"<<endl<<"Please read the instructions to continue."<<endl;
    cout<<"You will be asked to enter your grades for the first semester and then the second."<<endl;
    cout<<"You should enter the grade letter followed by the number of credit hours of that course."<<endl;
    cout<<"Once done, your semester GPA will be printed along with the information you've provided."<<endl;
    cout<<"The next step is to repeat that same process but for the second semester, and after that, your CGPA will be calculated."<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<< endl;

}


void clearInputStream() {
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
}

double calcCreditsEarned(int size,char grades[],double credithrs[]){
    double creditsEarned = 0;
    for (int i =0;i<size ; i++){
        switch (tolower(grades[i])){
            case 'a': creditsEarned += credithrs[i] * 4.0;
            break;
            case 'b': creditsEarned += credithrs[i] * 3.0;
            break;
            case 'c': creditsEarned += credithrs[i] * 2.0;
            break;
            case 'd': creditsEarned += credithrs[i] * 1.0;
            break;
            case 'f': creditsEarned += credithrs[i] * 0.0;
            break;
            default: cout <<"Error (Switch)"<<endl;
            break;
        }
    }
    return creditsEarned;
}

double calculateGPA(double totalcredithrs,double credits){
   double GPA = credits/totalcredithrs;
   return GPA;
}
bool isValidGrade(char grade) {
    grade = tolower(grade);
    return grade == 'a' || grade == 'b' || grade == 'c' || grade == 'd' || grade == 'f';}


int main(){
welcomeMessage();
int size1;
double totalcredithrs=0;


cout << "Enter the number of courses you've taken in the first semester: " << endl;
    while (!(cin >> size1) || size1 <= 0) {
        cout << "Invalid number. Please enter a positive integer: ";
        clearInputStream();
    }

double CreditHours[size1];
char Grades[size1];

cout<<"Enter the letter grade you achieved in the course followed by the number of credit hours: "<<endl;

for(int i = 0;i<size1;i++){
    cout<<"Course number "<<i+1<<" : "<<endl;
    while (true) {
            cout << "Grade: ";
            cin >> Grades[i];
            if (!isValidGrade(Grades[i])) {
                cout << "Invalid grade. Please enter a valid grade (A, B, C, D, F)." << endl;
                clearInputStream();
            } else {
                break;
            }
        }

        while (true) {
            cout << "Credit hours: ";
            if (!(cin >> CreditHours[i]) || CreditHours[i] < 0) {
                cout << "Invalid credit hours. Please enter a non-negative number." << endl;
                clearInputStream();
            } else {
                totalcredithrs += CreditHours[i];
                break;
            }
        }
    }


double credits = calcCreditsEarned(size1,Grades,CreditHours);
double GPA_sem1 = calculateGPA(totalcredithrs,credits);

cout<<"Your grades for the first semester: "<<endl;
for(int i =0;i<size1;i++){
    cout <<"--------------------------------"<<endl;
    cout<<"Course number "<<i+1<<" :"<<endl;
    cout<<"Grade = "<<Grades[i]<<endl;
    cout<<"Credit hours = "<<CreditHours[i]<<endl;
    cout <<"--------------------------------"<<endl;
}
cout<<"Your total GPA is = "<<GPA_sem1<<endl;



cout <<"--------------------------------------------"<<endl;


int size2;
double totalcredithrs2=0;

cout<<"Enter the number of courses you've taken in the second semester: "<<endl;
cin >> size2;

double CreditHours2[size2];
char Grades2[size2];

cout<<"Enter the letter grade you achieved in the course followed by the number of credit hours: "<<endl;


for (int i = 0; i < size2; i++) {
        cout << "Course number " << i + 1 << " : " << endl;

        while (true) {
            cout << "Grade: ";
            cin >> Grades2[i];
            if (!isValidGrade(Grades2[i])) {
                cout << "Invalid grade. Please enter a valid grade (A, B, C, D, F)." << endl;
                clearInputStream();
            } else {
                break;
            }
        }

        while (true) {
            cout << "Credit hours: ";
            if (!(cin >> CreditHours2[i]) || CreditHours2[i] < 0) {
                cout << "Invalid credit hours. Please enter a non-negative number." << endl;
                clearInputStream();
            } else {
                totalcredithrs2 += CreditHours2[i];
                break;
            }
        }
    }
double credits2 = calcCreditsEarned(size2,Grades2,CreditHours2);
double GPA_sem2 = calculateGPA(totalcredithrs2,credits2);

cout<<"Your grades for the second semester: "<<endl;
for(int i =0;i<size2;i++){
    cout <<"--------------------------------"<<endl;
    cout<<"Course number "<<i+1<<" :"<<endl;
    cout<<"Grade = "<<Grades2[i]<<endl;
    cout<<"Credit hours = "<<CreditHours2[i]<<endl;
    cout <<"--------------------------------"<<endl;
}
cout<<"Your total GPA is = "<<GPA_sem2<<endl;

cout <<"--------------------------------------------"<<endl;
cout<<endl;
double CGPA = (GPA_sem1 + GPA_sem2) /2;
cout << "Your CGPA is : "<<CGPA<<endl;
    return 0;
}
