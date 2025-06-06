#include<iostream>
#include<string>
#include <cstdlib>
using namespace std;

// Admin panel of banking system
class Admin_Panel{
public:
    static float total_amt;
    static int no_emp_id;
    static int ac_live;
    static int ac_closed;
    static int Admin_count;
    static int employee_count;
    static string Admin_history[100][3];
    static string employee_list[10][3];
    static string live_ac_list[100][4];
    static string closed_ac_list[100][5];

    void print_total_amt();
    void print_total_no_of_ac();
    void print_all_transaction();
    void print_all_emp_id();
    void show_live_ac_details();
    void show_closed_ac_details();
};

// to print all transaction of bank
void Admin_Panel::print_all_transaction(){
    cout<<"\n\n==============================================================\n\n";
    cout<<"\n           Transaction History of PVR Bank"<<endl;
    cout<<"--------------------------------------------------------------\n";
    for(int i =0; i<Admin_count; i++){
        cout<<(i+1)<<".    Date: "<<Admin_history[i][2]<<"    Account Number: "<<Admin_history[i][0]<<"    Amount: "<<Admin_history[i][1]<<endl;
    }
    cout<<"\n--------------------------------------------------------------\n";
    cout<<"            Total money of PVR Bank: "<<total_amt<<endl;
}

//to print total balance of bank
void Admin_Panel::print_total_amt(){
    cout<<"\n\n==============================================================\n\n";
    cout<<"\n   Total money in PVR Bank: "<<total_amt<<endl;
}

//to print total number of account ( live account + close account )
void Admin_Panel::print_total_no_of_ac(){
    cout<<"\n\n==============================================================\n\n";
    int total_ac = ac_live + ac_closed;
    cout<<"Live account number: "<<ac_live;
    cout<<"\nClosed account number: "<<ac_closed;
    cout<<"\nTotal number of account in PVR Bank: "<<total_ac<<endl;
}

//to print all employee id
void Admin_Panel::print_all_emp_id(){
    cout<<"\n\n==============================================================\n\n";
    cout<<"\n          All employee of PVR Bank details "<<endl;
    cout<<"--------------------------------------------------------------\n";
    for(int i =0; i<employee_count; i++){
        cout<<(i+1)<<".  Employee Name: "<<employee_list[i][0]<<"   Mobile No: "<<employee_list[i][1]<<"  Aadhar No: "<<employee_list[i][2]<<endl;
    }
    cout<<"\n--------------------------------------------------------------\n";
    cout<<"               Total employee in PVR Bank: "<<employee_count<<endl;
}

//to print details of live account
void Admin_Panel::show_live_ac_details(){
    cout<<"\n\n==============================================================\n\n";
    cout<<"\n         All live account details of PVR Bank"<<endl;
    cout<<"\n--------------------------------------------------------------\n";
    for(int i =0; i<ac_live; i++){
        cout<<(i+1)<<".  Customer Name: "<<live_ac_list[i][0]<<"   Mobile No: "<<live_ac_list[i][1];
        cout<<"  Aadhar No: "<<live_ac_list[i][2]<<"   Account opening date: "<<live_ac_list[i][3];
    }
    cout<<"\n--------------------------------------------------------------\n";
    cout<<"             Total live account in PVR Bank: "<<ac_live<<endl;
}

//to print details of closed account
void Admin_Panel::show_closed_ac_details(){
    cout<<"\n\n==============================================================\n\n";
    cout<<"\n          All closed account details of PVR Bank"<<endl;
    cout<<"--------------------------------------------------------------\n";
    for(int i =0; i<ac_closed; i++){
        cout<<(i+1)<<".  Customer Name: "<<closed_ac_list[i][0]<<"   Mobile No: "<<closed_ac_list[i][1]<<"  Aadhar No: "<<closed_ac_list[i][2];
        cout<<"   Account opening date: "<<closed_ac_list[i][3]<<"   Account closing date: "<<closed_ac_list[i][4]<<endl;
    }
    cout<<"\n--------------------------------------------------------------\n";
    cout<<"              Total live account in PVR Bank: "<<ac_closed<<endl;
}


//static variable of Admin Panel declaration & initialization
int Admin_Panel :: no_emp_id = 0;
int Admin_Panel :: ac_live = 0;
int Admin_Panel :: ac_closed = 0;
int Admin_Panel :: Admin_count = 0;
int Admin_Panel :: employee_count = 0;
string Admin_Panel :: Admin_history[100][3];
float Admin_Panel :: total_amt = 10000.00;
string Admin_Panel ::employee_list[10][3];
string Admin_Panel ::live_ac_list[100][4];
string Admin_Panel ::closed_ac_list[100][5];


//Bank employee panel
class Employee_Panel: public Admin_Panel{

public:
    string name, mobile_num, password, aadhar_no;

    string create_emp_id();
    void delete_emp_id(int);
    void change_password();
    void forgot_password();
    int otp_verification();
    int employee_verification();
};

//Employee panel function
//to create employee id
string Employee_Panel::create_emp_id(){
    cout<<"\n\n==============================================================\n\n";
    cout<<"                    Enter Employee Details"<<endl;
    cout<<"--------------------------------------------------------------\n";
    cout<<"Employee name: ";
    cin>>name;
    cout<<"Mobile Number: ";
    cin>>mobile_num;
    if(mobile_num.length() != 10){
        cout<<"Entered mobile number is wrong!!!"<<endl;
        return "0";
    }
    cout<<"Aadhar Number: ";
    cin>>aadhar_no;
    if(aadhar_no.length() != 12){
        cout<<"Entered aadhar is wrong!!!"<<endl;
        return "0";
    }
    int temp = otp_verification();
    if(temp == 0){
        return "0";
    }
    cout<<"\nEmployee ID created successfully!!!"<<endl;
    cout<<"\nNow Set Password: ";
    cin>>password;
    cout<<"\n\n==============================================================\n\n";
    cout<<"                   Employee Credentials";
    cout<<"\n--------------------------------------------------------------\n";
    cout<<"Username: "<<mobile_num<<"\nPassword: "<<password<<endl;
    employee_list[employee_count][0] = name;
    employee_list[employee_count][1] = mobile_num;
    employee_list[employee_count][2] = aadhar_no;
    employee_count++;
    return mobile_num;
}

//to delete employee id
void Employee_Panel::delete_emp_id(int e_count){
    string temp_pass;
    cout<<"Enter Employee Password: ";
    cin>>temp_pass;
    if(temp_pass == password){

        int temp = otp_verification();
        if(temp == 0){
            return;
        }
        cout<<"\nEmployee ID is successfully deleted!!!";
        employee_count--;
        for(int i = e_count; i<employee_count; i++){
            employee_list[i][0] = employee_list[i+1][0];
            employee_list[i][1] = employee_list[i+1][1];
            employee_list[i][2] = employee_list[i+1][2];
        }
    }
    else {
        cout<<"Credential is wrong\nPlease enter right username and password: ";
    }
}

//to change password of employee id
void Employee_Panel::change_password(){
    string current_password;
    cout<<"Current Password: ";
    cin>>current_password;
    if(current_password == password){
        int temp = otp_verification();
        if(temp == 0){
            return;
        }
        cout<<"Enter new password: ";
        cin>>password;
        cout<<"Password change successfully!!!\n";
        cout<<"\n\n==============================================================\n\n";
        cout<<"                 Employee New Credentials";
        cout<<"\n--------------------------------------------------------------\n";
        cout<<"Username: "<<mobile_num<<"\nPassword: "<<password<<endl;
    }
    else{
        cout<<"Entered details are wrong\nTry again\n";
    }
}

//to forgot password of employee id
void Employee_Panel::forgot_password(){
    int temp = otp_verification();
    if(temp == 0){
        return;
    }
    cout<<"Enter new password: ";
    cin>>password;
    cout<<"Password change successfully!!!\n";
    cout<<"\n\n==============================================================\n\n";
    cout<<"                  Employee New Credentials";
    cout<<"\n--------------------------------------------------------------\n";
    cout<<"Username: "<<mobile_num<<"\nPassword: "<<password<<endl;
    return;
}

// for otp verification
int Employee_Panel::otp_verification(){
    cout<<"\n\n==============================================================\n\n";
    int otp = rand();
    int temp_otp;
    cout<<"Your PVR Bank OTP: "<<otp<<"\nDon't share with anyone"<<endl;
    cout<<"\n\n==============================================================\n\n";
    cout<<"Enter OTP: ";
    cin>>temp_otp;
    if(temp_otp == otp){
        cout<<"OTP verification completed\n";
        return 1;
    }
    cout<<"Entered OTP is incorrect\n";
    return 0;
}

//for employee verification
int Employee_Panel::employee_verification(){
    string temp_password;
    cout<<"Enter your password: ";
    cin>>temp_password;
    if(temp_password == password){
        cout<<"Employee verification successful !!!"<<endl;
        return 1;
    }
    cout<<"Entered password is incorrect.\nTry again\n";
    return 0;
}


//banking panel
class Banking_Panel: private Employee_Panel{
private:
    static int static_ac_number;
    string ac_type, history[100][2];
    float balance;
    int ac_num, count =0;
public:
    Banking_Panel(): balance(0.0){}
    int create_bank_ac(string);
    void close_bank_ac(int,string);
    void view_balance();
    void Deposite_Amt(string);
    void Withdrawal_Amt(string);
    void Transfer_Amt(string, Banking_Panel&);
    void print_Transaction_History();
    void customer_details();
} ;

//banking panel function
//to create account
int  Banking_Panel::create_bank_ac(string date){
    cout<<"\n\n==============================================================\n\n";
    cout<<"\n                   Enter customer details";
    cout<<"\n--------------------------------------------------------------\n";
    cout<<"\nname: ";
    cin>>name;
    cout<<"Mobile Number: ";
    cin>>mobile_num;
    if(mobile_num.length() != 10){
        cout<<"Entered mobile number is wrong!!!"<<endl;
        return 0;
    }
    cout<<"Aadhar Number: ";
    cin>>aadhar_no;
    if(aadhar_no.length() != 12){
        cout<<"Entered aadhar is wrong!!!"<<endl;
        return 0;
    }
    cout<<"Account Type(Current / Saving): ";
    cin>>ac_type;
    cout<<"\n***Account opened successfully***\n";
    live_ac_list[ac_live][0] = name;
    live_ac_list[ac_live][1] = mobile_num;
    live_ac_list[ac_live][2] = aadhar_no;
    live_ac_list[ac_live][3] = date;
    ac_live++;
    static_ac_number++;
    ac_num = static_ac_number;
    cout<<"\n--------------------------------------------------------------\n\n";
    cout<<"                 Customer account number: "<<ac_num;
    return ac_num;
}

//for close account
void Banking_Panel::close_bank_ac(int a_count, string date){
    string m;
    cout<<"\n       *****     Enter customer details     *****\n";
    cout<<"--------------------------------------------------------------\n";
    cout<<"Mobile Number: ";
    cin>>m;
    if(m == mobile_num){
        if(balance != 0){
            cout<<"Withdrawal of "<<balance<<" amount is successful."<<endl;
            total_amt = total_amt - balance;
            Admin_history[Admin_count][0] = to_string(ac_num);
            Admin_history[Admin_count][1] = to_string(-1 * balance);
            Admin_history[Admin_count][2] = date;
            Admin_count++;
        }
        cout<<"Your account has successfully closed\n";
        ac_live--;
        string date_temp = live_ac_list[a_count][3];
        for(int i = a_count; i<ac_live; i++){
            live_ac_list[i][0] = live_ac_list[i+1][0];
            live_ac_list[i][1] = live_ac_list[i+1][1];
            live_ac_list[i][2] = live_ac_list[i+1][2];
            live_ac_list[i][3] = live_ac_list[i+1][3];
        }
        ac_closed++;
        closed_ac_list[ac_closed-1][0] = name;
        closed_ac_list[ac_closed-1][1] = mobile_num;
        closed_ac_list[ac_closed-1][2] = aadhar_no;
        closed_ac_list[ac_closed-1][3] =  date_temp;
        closed_ac_list[ac_closed-1][4] = date;
    }
    else{
        cout<<"Entered details are not right.\nTry again!!!\n";
    }
}

//to view balance
void Banking_Panel::view_balance(){
    cout<<"\nbalance: "<<balance<<endl;
}
// for deposit amount
void Banking_Panel::Deposite_Amt(string date){
    float amt;
    cout<<"\nEnter amount: ";
    cin>>amt;
    balance += amt;
    cout<<"Updated balance: "<<balance<<endl;
    total_amt += amt;
    history[count][0] = to_string(amt);
    history[count][1] = date;
    count++;
    Admin_history[Admin_count][0] = to_string(ac_num);
    Admin_history[Admin_count][1] = to_string(amt);
    Admin_history[Admin_count][2] = date;
    Admin_count++;
}

// for withdrawal amount
void Banking_Panel::Withdrawal_Amt(string date){
    float amt;
    cout<<"\nEnter withdrawal amount: ";
    cin>>amt;
    if(amt > balance){
        cout<<"Insufficient balance!!!";
        return;
    }
    cout<<"Withdrawal is successful!!!\n";
    balance -= amt;
    cout<<"Updated balance: "<<balance;
    total_amt -= amt;
    history[count][0] = to_string(-1 * amt);
    history[count][1] = date;
    count++;
    Admin_history[Admin_count][0] = to_string(ac_num);
    Admin_history[Admin_count][1] = to_string(-1 * amt);
    Admin_history[Admin_count][2] = date;
    Admin_count++;
}

// for transfer of money
void Banking_Panel::Transfer_Amt(string date, Banking_Panel& b){
    float amt;
    cout<<"\nEnter transfering amount: ";
    cin>>amt;
    if(amt > balance){
        cout<<"Insufficient balance!!!";
        return;
    }
    balance -= amt;
    b.balance += amt;
    history[count][0] = to_string(-1 * amt);
    history[count][1] = date;
    count++;
    b.history[count][0] = to_string(amt);
    b.history[count][1] = date;
    b.count++;
    cout<<"Updated balance: "<<balance<<endl;
    Admin_history[Admin_count][0] = to_string(ac_num);
    Admin_history[Admin_count][1] = to_string(-1 * amt);
    Admin_history[Admin_count][2] = date;
    Admin_count++;
    Admin_history[Admin_count][0] = to_string(b.ac_num);
    Admin_history[Admin_count][1] = to_string(amt);
    Admin_history[Admin_count][2] = date;
    Admin_count++;
}

// to print transaction history of account
void Banking_Panel::print_Transaction_History(){
    if(count == 0){
        cout<<"There is no history of "<<ac_num<<" account number."<<endl;

    }
    else{
        cout<<"\n            Transaction history of account number "<<ac_num<<endl;
        cout<<"--------------------------------------------------------------\n";
        for(int i=0; i<count; i++){
            cout<<(i+1)<<".    Date: "<<history[i][1]<<"    Amount: "<<history[i][0]<<endl;
        }
        cout<<"--------------------------------------------------------------\n";
        cout<<"\nTotal balance: "<<balance<<endl;
    }
}

// to show customer details
void Banking_Panel::customer_details(){
    cout<<"\n                      Customer details\n";
    cout<<"\n--------------------------------------------------------------\n";
    cout<<"Name: "<<name<<"\nAccount Number: "<<ac_num<<"\nMobile Number: "<<mobile_num<<endl;
    cout<<"Account Type: "<<ac_type<<"\nAadhar Number: "<<aadhar_no<<endl;
}

//static variable of Banking_Panel declaration
int Banking_Panel::static_ac_number = 1000;

// for check account number exist or not
int check_ac_number(int account_number, int ac[]){
    for(int i=0; i<Admin_Panel::ac_live; i++){
        if(ac[i] == account_number){
            return i;
        }
    }
    cout<<"Account not found!!!";
    return -1;
}

// for check employee exist for not
int check_employee_list(string e_username[]){
    if(Admin_Panel::employee_count == 0){
        cout<<"\n\n==============================================================\n\n";
        cout<<"\nThere is no employee\n";
        return -1;
        cout<<"\n\n==============================================================\n\n";
    }
    cout<<"\n\n==============================================================\n\n";
    cout<<"       ********    Employee Verification     ********\n\n";
    string username;
    cout<<"Enter employee username: ";
    cin>>username;
    for(int i=0; i<Admin_Panel::employee_count; i++){
        if(e_username[i] == username){
            return i;
        }
    }
    cout<<"Username not found!!!\n";
    return -1;
}

int main(){
    int choice = 0, choose = 0, i, j, k, l, all_account_number[100], account_number, recipient_account_number;
    string employee_username[10], username, Admin_password, date;
    Admin_Panel Admin;
    Employee_Panel E[10];
    Banking_Panel Account[100];
    do{
        cout<<"\n\n==============================================================\n\n";
        cout<<"\n*********   Welcome to PVR Bank   *********"<<endl;
        cout<<"1.Access Admin Panel\n2.Access Employee Panel\n3.Access Banking Panel\n4.Exit\nEnter Your Choice: ";
        cin>>choice;
        switch(choice){
            // Admin panel
            case 1:
                cout<<"\n\n==============================================================\n\n";
                cout<<"Enter Admin Panel username: ";
                cin>>username;
                cout<<"Enter Admin Panel password: ";
                cin>>Admin_password;
                if(username == "Admin" && Admin_password == "29"){
                    cout<<"Proceed....\n";
                }
                else{
                    cout<<"\nEntered Username or Password are incorrect\nTry again\n \n";
                    break;
                }
                do{
                    cout<<"\n\n==============================================================\n\n";
                    cout<<"\n*********   Welcome to Admin panel of PVR Bank   *********\n\n";
                    cout<<"1.Show Total Transaction of Bank\n2.Show Total Amount in Bank\n3.Show Total Number of Bank Account\n4.Show All Employee ID's\n";
                    cout<<"5.Show live account details\n6.Show closed account details\n7.Previous Menu\n8.Exit\nEnter your choice: ";
                    cin>>choose;
                    switch(choose){
                        case 1:
                            Admin.print_all_transaction();
                            break;
                        case 2:
                            Admin.print_total_amt();
                            break;
                        case 3:
                            Admin.print_total_no_of_ac();
                            break;
                        case 4:
                            Admin.print_all_emp_id();
                            break;
                        case 5:
                            Admin.show_live_ac_details();
                            break;
                        case 6:
                            Admin.show_closed_ac_details();
                            break;
                        case 7:
                            cout<<"\n\n==============================================================\n\n";
                            cout<<"Returned to previous menu\n";
                            break;
                        case 8:
                            cout<<"\n\n==============================================================\n\n";
                            cout<<"Exit successfully!!!\n";
                            choice = 4;
                            break;
                        default:
                            cout<<"Your choice is wrong\nPlease enter your choice again\n";
                    }
                }while(choice != 4 && choose != 7);
                break;

                //Employee panel
            case 2:
                do{
                    cout<<"\n\n==============================================================\n\n";
                    cout<<"\n*********   Welcome to Employee panel of PVR Bank   *********\n\n";
                    cout<<"1.Create Employee ID\n2.Delete Employee ID\n3.Change Password\n";
                    cout<<"4.Forgot Password\n5.Previous Menu\n6.Exit\nEnter your choice: ";
                    cin>>choose;
                    if(choose < 1 || choose > 6){
                        cout<<"Your choice is wrong\nPlease enter your choice again\n";
                        continue;
                    }
                    // for check employee exist for not
                    if(choose != 1 && choose != 6 && choose != 5){
                        i = check_employee_list(employee_username);
                        if(i == -1){
                            continue;
                        }
                    }
                    switch(choose){
                        case 1:
                            username = E[Admin_Panel::employee_count].create_emp_id();
                            if(username == "0"){
                                break;
                            }
                            employee_username[Admin_Panel::employee_count-1] = username;
                            break;
                        case 2:
                            E[i].delete_emp_id(i);
                            for(int p = i; p<Admin_Panel::employee_count; p++){
                                E[i] = E[i+1];
                                employee_username[i] = employee_username[i+1];
                            }
                            break;
                        case 3:
                            E[i].change_password();
                            break;
                        case 4:
                            E[i].forgot_password();
                            break;
                        case 5:
                            cout<<"\n\n==============================================================\n\n";
                            cout<<"Returned to previous menu successfully...\n";
                            break;
                        case 6:
                            cout<<"\n\n==============================================================\n\n";
                            cout<<"Exit successfully!!!\n";
                            choice = 4;
                            break;
                    }
                }while(choose != 6 && choose !=5);
                break;

                //Banking panel
            case 3:
                // for check employee exist for not
                k = check_employee_list(employee_username);
                if(k == -1){
                    break;
                }
                // to verify employee credentials
                l = E[k].employee_verification();
                if(l == 0){
                    break;
                }
                do{
                    cout<<"\n\n==============================================================\n\n";
                    cout<<"\n*********   Welcome to Banking panel of PVR Bank   *********\n\n";
                    cout<<"Enter today date: ";
                    cin>>date;
                    cout<<"1.Open new bank account\n2.Close bank account\n3.View balance\n4.Deposit money\n";
                    cout<<"5.Withdrawal money\n6.Transfer money\n7.Show transaction history\n8.Details of customer\n";
                    cout<<"9.Previous menu\n10.Exit\nEnter your choice: ";
                    cin>>choose;
                    if(choose < 1 || choose > 10){
                        cout<<"Your choice is wrong\nPlease enter your choice again\n";
                        continue;
                    }
                    if(Admin_Panel::ac_live == 0 && choose != 1){
                        cout<<"\n\n==============================================================\n\n";
                        cout<<"There is no bank account in PVR Bank"<<endl;
                        continue;
                    }
                    // for check account number exist or not
                    if(choose != 1 && choose != 10 && choose != 9){
                        cout<<"\n\n==============================================================\n\n";
                        cout<<"Enter Customer Account Number:  ";
                        cin>>account_number;
                        i = check_ac_number(account_number,all_account_number);
                        if(i == -1){
                            continue;
                        }
                    }
                    switch(choose){
                        case 1:
                            account_number = Account[Admin_Panel::ac_live].create_bank_ac(date);
                            if(account_number == 0){
                                break;
                            }
                            all_account_number[Admin_Panel::ac_live-1] = account_number;
                            break;
                        case 2:
                            Account[i].close_bank_ac(i,date);
                            for(int p=i; p<Admin_Panel::ac_live; p++){
                                Account[i] = Account[i+1];
                                all_account_number[i] = all_account_number[i+1];
                            }
                            break;
                        case 3:
                            Account[i].view_balance();
                            break;
                        case 4:
                            Account[i].Deposite_Amt(date);
                            break;
                        case 5:
                            Account[i].Withdrawal_Amt(date);
                            break;


                        case 6:
                            cout<<"Enter Recipient Account Number: ";
                            cin>>recipient_account_number;
                            j = check_ac_number(recipient_account_number, all_account_number);
                            if(i == j){
                                cout<<"Choose another person account number"<<endl;
                                break;
                            }
                            if(j == -1) {
                                cout<<"\nThis account number not exist";
                                break;
                            }
                            Account[i].Transfer_Amt(date, Account[j]);
                            break;
                        case 7:
                            Account[i].print_Transaction_History();
                            break;
                        case 8:
                            Account[i].customer_details();
                            break;
                        case 9:
                            cout<<"\n\n==============================================================\n\n";
                            cout<<"Returned to previous menu successfully...\n";
                            break;
                        case 10:
                            cout<<"\n\n==============================================================\n\n";
                            cout<<"Exit successfully!!!\n";
                            choice = 4;
                            break;
                    }
                }while(choose != 10 && choose != 9);
                break;

            case 4:
                cout<<"Exit successfully!!!\n";
                break;
            default:
                cout<<"Your choice is wrong\nPlease enter your choice again\n";
        }
    }while(choice != 4);
}