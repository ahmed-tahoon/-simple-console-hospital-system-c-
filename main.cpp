#include <iostream>
using namespace std;
const int  MAX_spc = 20;
const int  MAX_qu = 5;

string names[MAX_spc+1][MAX_qu+1];
int status[MAX_spc+1][MAX_qu+1];
int q_l[MAX_qu+1];
//************************************************************************
int  menu() {

int choice=-1;

while (choice == -1){


cout << "Enter your choice :  \n";
        cout << "1) Add new patient \n";
cout << "2) Print All Patient  \n";
        cout << "3) Get Next Patient \n";
cout << "4) Exit\n";
        cin >> choice ;
	if (!(choice>=1&&choice<=4)){
      cout << "INVALID CHOICE : PLEASE ENTER RIGHT CHOICE : \n";
      choice = -1;
		}
}
return choice;
}
//************************************************************************

void shift_left(int spec, string names_sp[], int status_sp[])
{
	int len = q_l[spec];
	for (int i = 1; i < len; ++i) {
		names_sp[i-1] = names_sp[i];
		status_sp[i-1] = status_sp[i];
	}
	q_l[spec]--;
}

//************************************************************************


void shift_right(int spec ,string  name_sp[] , int status[]){
  int len = q_l[spec];
 for (int i =len - 1; i >=0 ;i --  ){
name_sp[i+1]=name_sp[i];
status[i+1]=status[i];


 }
     q_l[spec]++;



}

//*****************************************************************
bool add(){
cout << "Enter Specialization\n";
int spec ;
cin >> spec;
cout << "Enter Name\n";
string name ;
cin >>name;
cout << "Enter Status\n";
int sta;
cin >> sta;

int pos  = q_l[spec];
if (pos  >= MAX_qu){
		cout << "Sorry we can't add more patients for this specialization\n";
return false ;
}

if (sta==0){  // regular, add to end

     names[spec][pos] = name ;
     status[spec][pos]= sta;
     q_l[spec]++;


}
else {

    shift_right(spec,names[spec],status[spec]);
    names[spec][0]=name;
    status[spec][0]= sta;
}
return true;

}
//************************************************************************
void print_patient (int spec , string name[] , int status[]){

int len = q_l[spec] ;
if (len==0)
    return;

    	cout << "There are " << len << " patients in specialization " << spec << "\n";
for (int i =0; i < len ; i ++ ){
      cout <<name[i]<<" " ;
      if (status[i])
       		cout << "urgent\n";
		else
			cout << "regular\n";
	}
	cout << "\n";
}
//************************************************************************

void get_next_patients() {
	int spec;
	cout << "Enter specialization: ";
	cin >> spec;

	int len = q_l[spec];

	if(len == 0) {
		cout<<"No patients at the moment. Have rest, Dr\n";
		return;
	}

	// Let patient goes to dr
	cout<<names[spec][0]<<" please go with the Dr\n";

	// delete the patient in position 0
	shift_left(spec, names[spec], status[spec]);
}

//************************************************************************
void print(){

    cout << "*************************************\n";
	for (int spec = 0; spec <  MAX_spc ; ++spec) {
		print_patient(spec, names[spec], status[spec]);
	}


}
//************************************************************************


int hospital_system(){

while (true){

 int choice=menu()   ;

if (choice==1)
    add();
else  if (choice==2)
    print();
    else  if (choice==3)

    get_next_patients();

else
    break ;

}

}

//************************************************************************



int main()
{
  hospital_system();
    return 0;


}

