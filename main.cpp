#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/*Prototypes*/
class Person;
class Bank;
class Customer;
class Manager;
class Account;

/*Classes*/
/*Person Class*/
class Person{
protected:
	string m_name;
	int m_id;
public:
	Person(){
		m_name = "";
		m_id = 0;
	}
	Person(string name, int id)
		: m_name(name), m_id(id){

	}
	string getName(){

		return m_name;
	}
	void setPerson(){

		cout << "Enter Name: ";    cin >> m_name;
		cout << "Enter ID_no: ";   cin >> m_id;
	}
};
/*Manager Class*/
class Manager : public Person{
protected:
	string m_branch;
public:
	Manager(){}
	Manager(string name, int id, string branch)
		: Person(name, id), m_branch(branch){

	}
	void print_ManagerDetail(){
		cout << "\n\tManager Detail\n";
		cout << "Name of the Manager: " << m_name << endl;
		cout << "Branch No:           " << m_branch << endl;
		cout << "ID No:               " << m_id << endl;
	}
};

/*Account Class*/
class Account{
protected:
	int Account_ID;
	int numberOfAcounts;
	string AccountType;
	int Account_Balance;
	int Customer_ID;
	int withdraw;
	int deposit;
public:
	Account(){
	}
	int account(int accountId){
		Account_ID = accountId;
		return Account_ID;
	}
	int getAcount(){

		return Account_ID;
	}
	void account(){
		cin >> Account_ID;
	}
	
	int setBalance(int balance){
		Account_Balance = balance;
		return Account_Balance;
	}
	
	
	

	void WithDraw(){
		cout << "Your current Account Balance: ";
		cout << Account_Balance << endl;
		cout << "Enter Amount you want to withdraw: ";
		cin >> withdraw;
		Account_Balance -= withdraw;
		cout << "After With Draw: ";
		cout << Account_Balance << endl;
	}
	void Deposit(){
		cout << "Your current Amount: ";
		cout << Account_Balance << endl;
		cout << "Enter Amount you want to deposit: ";
		cin >> deposit;
		Account_Balance += deposit;
		cout << "After Add: ";
		cout << Account_Balance << endl;

	}
	void setBalance(){
		cout << "Enter Account Balance: ";
		cin >> Account_Balance;
	}
	void showBalance(){
		cout << "Your Current balance: ";
		cout << Account_Balance << endl;;
	}

};


/*Customer Class*/
class Customer : public Person, public Account{
public:
	int numberOfaccounts=0;
	Customer(){
	}
	Customer(string name, int id)
		: Person(name, id){

	}
	int getID(){
		return m_id;
	}
	void setNumberOfaccount(){
		numberOfaccounts++;
	}
	int getNumberOfAccounts(){
		return numberOfaccounts;
	}

	void print_CustomerDetail(){
		cout << "Customer Name: " << m_name << endl;
		cout << "Customer ID: " << m_id << endl;
		cout << "Customer Account_ID: " << Account_ID << endl;
		cout << "Current Balance: " << Account_Balance << endl;
	}
};



/*Bank Class*/
class Bank {
public:
	Customer * customers_ptr;
	Account * account_ptr;
	Customer *ptr[10];
	Manager manager;
	int colum;
	int customerCount;

	Bank(){}
	Bank(int colums) {
		colum = colums;

		for (int i = 0; i < 10; i++){

			for (int j = 0; j < colums; j++) {
				ptr[i] = new Customer[j];
			}
		}
		
		Customer customer1("Ahmad", 11);
		customer1.account(123456);
		customer1.setBalance(2500);
		Customer customer2("Maria", 12);
		customer2.account(456789);
		customer2.setBalance(50000);
		Customer customer3("Joy", 13);
		customer3.account(741852);
		customer3.setBalance(45000);

		ptr[0][0] = customer1;
		ptr[1][0] = customer2;
		ptr[2][0] = customer3;
		customerCount = 3;
	}
	void addCustomer(){
		Customer customer;
		cout << "Enter new Account_ID: ";
		customers_ptr = new Customer;
		customers_ptr = &customer;
		customers_ptr->account();
		cout << "Deposite Money in Account\n";
		customers_ptr->setBalance();
		cout << "Enter Customer Name: ";
		customers_ptr->setPerson();

		cout << "New Customer Created!\n";
		ptr[customerCount][customer.getNumberOfAccounts()] = customer;
		customerCount++;
		
	}
	void DeletAccount(){

		int account_id;
		int indexI = -1;
		int indexJ = -1;

		cout << "Enter Customer Account_ID: ";
		cin >> account_id;
		for (int i = 0; i <10; i++){
			for (int j = 0; j < colum; j++) {

				if (ptr[i][j].getAcount() == account_id){
					indexI = i;
					indexJ = j;
				}
			}
		}
		if (indexI == -1){
			cout << "Account does not Exist!\n";
		}
		else
		{
			for (int k = 0; k < colum; k++) {
				ptr[indexI] = new Customer[k];
			}
			cout << "Account has been deleted";
		}
	}
	void addAccount(){

		int n = 1;
		while (n == 1){
			Bank account;
			Account acc;

			int customer_id;
			cout << "Enter Customer_ID: ";
			cin >> customer_id;
			int indexI = -1;

			for (int i = 0; i < 10; i++){

				if (ptr[i][0].getID() == customer_id){
					indexI = i;
				}

			}
			if (indexI == -1){
				cout << "Customer_ID does not exist!";
			}
			else{
				ptr[indexI][0].print_CustomerDetail();

				Customer customer1 = ptr[indexI][0];
				customer1.setNumberOfaccount();
				ptr[indexI][0] = customer1;

				Customer customer(ptr[indexI][0].getName(), customer_id);
				cout << "Enter " << ptr[indexI][0].getNumberOfAccounts() + 1 << " Account No: ";
				customer.account();
				customer.setBalance();

				ptr[indexI][ptr[indexI][0].getNumberOfAccounts()] = customer;

				cout << "Account Has Been Added!" << endl;
				cout << "If you want to add more accounts: Press[1] \n";
				cout << "If not: Press [0]\n";
				cin >> n;
			}

		}
		
	}
	void DeletCustomer(){
		int account_id;
		int indexI = -1;
		int indexJ = -1;

		cout << "Enter Customer Account_ID: ";
		cin >> account_id;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < colum; j++) {

				if (ptr[i][j].getAcount() == account_id){
					indexI = i;
					indexJ = j;
					
				}
			}
		}
		if (indexI == -1){
			cout << "Account does not Exist!\n";
		}
		else
		{
			for (int k = 0; k < colum; k++) {
				ptr[indexI] = new Customer[k];
			}
			cout << "Customer has been deleted";
		}

	}
	void GetNoOfAccount(){
		cout << "Enter Accounts_ID: ";
		int account_id;
		cin >> account_id;
		int indexI = -1;
		int indexJ = -1;

		for (int i = 0; i < 10; i++){
			for (int j = 0; j < colum; j++) {

				if (ptr[i][j].getAcount() == account_id){
					indexI = i;
					indexJ = j;
				}
			}

		}
		if (indexI == -1){
			cout << "Account does not Exist!\n";
		}
		else{
			cout << ptr[indexI][indexJ].getNumberOfAccounts();
		}
	}
	void GetCustomer_Name(){
		cout << "Enter Account ID: ";
		int account_id;
		cin >> account_id;
		int indexI = -1;
		int indexJ = -1;

		for (int i = 0; i < 10; i++){
			for (int j = 0; j < colum; j++) {

				if (ptr[i][j].getAcount() == account_id){
					indexI = i;
					indexJ = j;
				}
			}

		}
		if (indexI == -1){
			cout << "Account does not Exist!\n";
		}
		else{
			cout << ptr[indexI][indexJ].getName();
		}
	}
	void viewAccountDetail(){
		int accountId;
		cout << "Enter Customer Account_ID: ";
		cin >> accountId;

		int indexI = -1;
		int indexJ = -1;

		for (int i = 0; i < 10; i++){
			for (int j = 0; j < colum; j++) {

				if (ptr[i][j].getAcount() == accountId){
					indexI = i;
					indexJ = j;
				}
			}

		}
		if (indexI == -1){
			cout << "Account does not Exist!\n";
		}
		else{
			ptr[indexI][indexJ].print_CustomerDetail();
		}
	}
	void withDraw(){
		int account_id;
		int indexI = -1;
		int indexJ = -1;

		cout << "Enter your Account_ID:";
		cin >> account_id;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < colum; j++){
				if (ptr[i][j].getAcount() == account_id) {
					indexI = i;
					indexJ = j;
				}
			}
		}
		if (indexI == -1) {
			cout << "Account ID doest not exit!\n" << endl;
		}
		else{
			ptr[indexI][indexJ].WithDraw();
		}
	}
	void deposit(){

		int account_id;
		int indexI = -1;
		int indexJ = -1;

		cout << "Enter your Account_ID:";
		cin >> account_id;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < colum; j++){
				if (ptr[i][j].getAcount() == account_id) {
					indexI = i;
					indexJ = j;
				}
			}
		}
		if (indexI == -1) {
			cout << "Account ID doest not exit!\n" << endl;
		}
		else{
			ptr[indexI][indexJ].Deposit();
		}
	}
	void showBelance(){

		int account_id;
		int indexI = -1;
		int indexJ = -1;

		cout << "Enter your Account_ID:";
		cin >> account_id;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < colum; j++){
				if (ptr[i][j].getAcount() == account_id) {
					indexI = i;
					indexJ = j;
				}
			}
		}
		if (indexI == -1) {
			cout << "Account ID doest not exit!\n" << endl;
		}
		else{
			ptr[indexI][indexJ].showBalance();
		}
	}
};




int main(){
	cout << "\tManager Input\n";
	Manager manager("Alex", 77229, "Lahore");
	manager.print_ManagerDetail();
	int count = 0;
	const int totalnumber = 100;
	const int accNumber = 10;

	Bank bank(accNumber);

	/////////////////* For Updating one customer information *//////////////////////////////
	cout << "\n\tCustomer Inputs\n";
	int n;
	Customer *customerPtr[totalnumber];
	for (int i = 0; i < totalnumber; i++){

		for (int j = 0; j < accNumber; j++) {
			customerPtr[i] = new Customer[j];
		}
	}

	while (true) {
		cout << "\n\t====================================";
		cout << "\n\tOPTIONS:\n";
		cout << "\t1.View an Customer Account: Press [1]\n";
		cout << "\t2.Make an Tansaction: Press [2] \n";
		cout << "\t3.To Deposit Amount: Press [3] \n";
		cout << "\t4.To Check Balance: Press [4] \n";
		cout << "\t5.To Creat New Customer: Press [5] \n";
		cout << "\t6.To Add More Account: Press [6] \n";
		cout << "\t7.To Delte a Customer: Press [7] \n";
		cout << "\t8.To Delte an Account: Press [8] \n";
		cout << "\t9.To get a Customer Name: Press [9] \n";
		cout << "\t10.To get Number of Accounts: Press [10] \n";
		cout << "\t====================================\n";
		cin >> n;
		///////* For Customer IDs *////////////
		if (n == 1){
			bank.viewAccountDetail();
		}

		if (n == 2){
			bank.withDraw();
		}
		if (n == 3){
			bank.deposit();
		}
		if (n == 4){
			bank.showBelance();
		}
	
		if (n == 5){

			bank.addCustomer();
		}
		if (n == 6){
			bank.addAccount();
		
		}
		if (n == 7){
			bank.DeletCustomer();
		}
		if (n == 8){
			bank.DeletAccount();
		}
		if (n == 9){
			bank.GetCustomer_Name();
		}
		if (n == 10){
			bank.GetNoOfAccount();
		}
	}

	system("pause");
	return 0;
}
