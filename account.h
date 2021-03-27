// ===================================================================================
//  Assignment: 1 
//  Milestone : 2
// ===================================================================================
//  Student Name  : Nasim Khodapanah
//  Student ID    : 131929200
//  Student Email : nkhodapanah@myseneca.ca
//  Course Section: NGG
// ===================================================================================

typedef struct Demographic {
	int birthYear;
	double houseHoldIncome;
	char country[31];
}Demographic;

typedef struct UserLogin {
	char customerName[31];
	char userName[11];
	char password[9];

}UserLogin;

typedef struct Account {
	int accountNumber;
	char accountType;
}Account;