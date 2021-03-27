
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include "account.h"
#include "accountTicketingUI.h"
#include "commonHelpers.h"


void displayAccountSummaryHeader() {
    printf("\nAcct# Acct.Type Birth\n");
    printf("----- --------- -----\n");
}

void  displayAccountDetailHeader() {
    printf("Acct# Acct.Type Birth Income      Country    Disp.Name       Login      Password\n");
    printf("----- --------- ----- ----------- ---------- --------------- ---------- --------\n");
}

void displayAccountSummaryRecord(const struct Account* name) {

    char agentAccountType[] = "AGENT";
    char customerAccountType[] = "CUSTOMER";

    if (name->accountType == 'A') {
        printf("%05d %-9s %5d",
            name->accountNumber, agentAccountType,
            name->log.birthYear);
    }
    else {
        printf("%05d %-9s %5d",
            name->accountNumber, customerAccountType,
            name->log.birthYear);

    }
    putchar('\n');
}
void displayAccountDetailRecord(const struct Account* record) {
    char password[50] = { 0 };
    int i;

    for (i = 0; record->name.password[i] != '\0'; i++)
    {
        if (i % 2) {
            password[i] = '*';
        }
        else
            password[i] = record->name.password[i];
    }
    char agentAccountType[] = "AGENT";
    char customerAccountType[] = "CUSTOMER";

    if (record->accountType == 'A') {
        printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s",
               
            record->accountNumber, agentAccountType,
            record->log.birthYear,
            record->log.houseHoldIncome,
            record->log.country,
            record->name.customerName,
            record->name.userName,
            password);
    }
    else {
        printf("%05d %-9s %5d $%10.2lf %-10s %-15s %-10s %8s",
            record->accountNumber, customerAccountType,
            record->log.birthYear,
            record->log.houseHoldIncome,
            record->log.country,
            record->name.customerName,
            record->name.userName,
            password);
    }
}

void applicationStartup(Account accounts[], int arrSize)
{
    int result = -2;
    while (result != -1)
    {
        result = menuLogin(accounts, arrSize);
        if (result > -1 && accounts[result].accountType != 'C')
        {
            printf("\n");
            menuAgent(accounts, arrSize, &accounts[result]);
        }
        else if (result > -1 && accounts[result].accountType == 'C')
        {
            printf("\nCUSTOMER: home menu currently unavailable...\n\n");
            pauseExecution();
            printf("\n");
        }
    }
}

int menuLogin(const struct Account accounts[], int arrSize)
{
    int return_val = -1;
    char confirm = ' ';
    printf("==============================================\n");
    printf("Account Ticketing System - Login\n");
    printf("==============================================\n");
    printf("1) Login to the system\n0) Exit application\n----------------------------------------------\n\nSelection: ");
    int customer_selection = getIntFromRange(0, 1);
    if (1 == customer_selection)
    {
        printf("\n");
        int found_flag = findAccountIndexByAcctNum(0, accounts, arrSize, 1);

        if (found_flag > -1)
        {
            return_val = found_flag;
        }
        else
        {
            return_val = -2;
            printf("\nERROR:  Access Denied.\n\n");
            pauseExecution();
            printf("\n");
        }

    }
    else
    {
        printf("\nAre you sure you want to exit? ([Y]es|[N]o): ");
        confirm = getCharOption("yYnN");
        printf("\n");
        if ('y' == confirm || 'Y' == confirm)
        {
            return_val = -1;
            printf("==============================================\n");
            printf("Account Ticketing System - Terminated\n");
            printf("==============================================\n");
        }
        else
        {
            return_val = -2;
        }
    }

    return return_val;
}


void menuAgent(struct Account agent[], int maxSize, const struct Account* loggedDetail) {
    int index, account;
    char acc;
    do {
        printf("AGENT: %s (%d)\n", loggedDetail->name.customerName, loggedDetail->accountNumber);
        printf("==============================================\n");
        printf("Account Ticketing System - Agent Menu\n");
        printf("==============================================\n");
        printf("1) Add a new account\n");
        printf("2) Modify an existing account\n");
        printf("3) Remove an account\n");
        printf("4) List accounts: summary view\n");
        printf("5) List accounts: detailed view\n");
        printf("----------------------------------------------\n");
        printf("0) Logout\n");
        printf("\nSelection: ");
        account = getIntFromRange(0, 5);
        switch (account) {
        case 1:
            index = findAccountIndexByAcctNum(0, agent, maxSize, 0);

            if (index < 0) {
                printf("ERROR: Account listing is FULL, call ITS Support!\n");
            }
            else {
                getAccount(&agent[index]);
                printf("\n");
                getUserLogin(&agent[index].name);
                printf("\n");
                getDemographic(&agent[index].log);
                printf("\n*** New account added! ***\n\n");
            }
            pauseExecution();
            printf("\n");
            break;
        case 2: 
            printf("\nEnter the account#: ");
            account = getPositiveInteger();
            index = findAccountIndexByAcctNum(account, agent, maxSize, 0);
            if (index < 0) {
                printf("ERROR: Access Denied.\n");
                pauseExecution();
                printf("\n");
            }
            else {
               updateAccount(&agent[index]);
            }
            break;
        case 3:  printf("\nEnter the account#: ");
            account = getPositiveInteger();
            index = findAccountIndexByAcctNum(account, agent, maxSize, 0);

            if (index > 0 && agent[index].accountNumber == loggedDetail->accountNumber)
            {
                printf("\nERROR: You can't remove your own account!\n\n");
                pauseExecution();
                printf("\n");
                break;
            }
            else if (index > -1)
            {
                displayAccountDetailHeader();
                displayAccountDetailRecord(&agent[index]);
                printf("\n\nAre you sure you want to remove this record? ([Y]es|[N]o): ");
                acc = getCharOption("YN");
                if (acc == 'Y')
                {
                    agent[index].accountNumber = 0;
                    printf("\n*** Account Removed! ***\n\n");
                    pauseExecution();
                    printf("\n");
                }
                else
                {
                    printf("\n*** No changes made! ***\n\n");
                    pauseExecution();
                    printf("\n");
                }
            }
            else
            {
                printf("\nERROR:  Access Denied.\n\n");
                pauseExecution();
                //printf("\n");
            }
            break;
        case 4: displayAllAccountSummaryRecords(agent, maxSize);
            pauseExecution();
            printf("\n");
                break;
        case 5: printf("\n");
            displayAllAccountDetailRecords(agent, maxSize);
            pauseExecution();
            printf("\n");
                break;
        case 0: printf("\n### LOGGED OUT ###\n");
            printf("\n");
            break;
        }
    } while (account);
}


int findAccountIndexByAcctNum(int accountNum, const struct Account account[], int maxSize, int prompt) {
    int i, index = -1;
    if (prompt) {
        printf("Enter your account#: ");
        accountNum = getPositiveInteger();
    }
    for (i = 0; i < maxSize; i++) {
        if (account[i].accountNumber == accountNum) {

            index = i;
            break;
        }
    }
    return index;
}
void displayAllAccountSummaryRecords(const struct Account summary[], int maxSize) {
    int i = 0;
    displayAccountSummaryHeader();
    while (i < maxSize) {
        if (summary[i].accountNumber != '\0') {
            displayAccountSummaryRecord(&summary[i]);
        }
        i++;
    }
    putchar('\n');
}
void displayAllAccountDetailRecords(const struct Account summary[], int maxSize) {
    int i = 0;
    displayAccountDetailHeader();
    while (i < maxSize) {
        if (summary[i].accountNumber != '\0') {
            displayAccountDetailRecord(&summary[i]);
            putchar('\n');
        }
        i++;
    }
    putchar('\n');
}
void pauseExecution() {
    printf("<< ENTER key to Continue... >>");
    clearStandardInputBuffer();
    //putchar('\n');
}
