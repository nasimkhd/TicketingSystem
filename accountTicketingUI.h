// ===================================================================================
//  Assignment: 1 
//  Milestone : 4
// ===================================================================================
//  Student Name  : Nasim Khodapanah
//  Student ID    : 131929200
//  Student Email : nkhodapanah@myseneca.ca
//  Course Section: NGG
// ===================================================================================

#ifndef ACCOUNT_TICKETING_UI_H_
#define ACCOUNT_TICKETING_UI_H_

#include "account.h"
#include "accountTicketingUI.h"


void displayAccountSummaryHeader();
void displayAccountSummaryRecord(const Account* name);
void displayAccountDetailHeader();
void displayAccountDetailRecord(const Account* record);

void applicationStartup(Account name[] , int maxSize);
int menuLogin(const struct Account log[], int maxSize);
void menuAgent(Account agent[] , int maxSize, const Account *loggedDetail);
int findAccountIndexByAcctNum(int accountNum , const struct Account account[], int maxSize , int zeroOrNot);
void displayAllAccountSummaryRecords(const Account summary[] , int maxSize);
void displayAllAccountDetailRecords(const Account summary[] , int maxSize);
void pauseExecution();





#endif // !ACCOUNT_TICKETING_UI_H_