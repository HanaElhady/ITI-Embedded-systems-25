#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PATIENTS 100
#define MAX_RESERVATIONS 5

const char *slotTimes[MAX_RESERVATIONS] = {
    "2:00pm - 2:30pm",
    "2:30pm - 3:00pm",
    "3:00pm - 3:30pm",
    "4:00pm - 4:30pm",
    "4:30pm - 5:00pm"};

struct basicInformation
{
    char name[50];
    int age;
    char gender;
};

struct user
{
    int id;
    char password[5];
    char state; // 'A' or 'U'
    struct basicInformation info;
    int reservations[MAX_RESERVATIONS];
};

struct user patients[MAX_PATIENTS] = {
    {.id = 100,
     .password = "1234",
     .state = 'U',
     .info = {
         .name = "Hana",
         .age = 20,
         .gender = 'F'},
     .reservations = {1, 0, 3, 0, 5}}};

struct user patients[MAX_PATIENTS];
int patientCount = 1;

void adminMode();
void userMode();
void patientRecord(int index);
void reservations(int index);
void adminFeature();
void addPatient();
void editPatient(int index);
void reserveSlot(int index);
void cancelReservation(int index);
int findPatientByID(int id);
bool isSlotTaken(int slot);

int main(void)
{

    int mode;
    printf("Choose your mode\nEnter 1 for admin mode\n2 for user mode\n> ");
    scanf("%d", &mode);
    if (mode == 1)
        adminMode();
    else
        userMode();
    return 0;
}

void adminMode()
{
    char correctPassword[] = "1234";
    char trial[5];
    int trialNum = 3;

    while (trialNum-- > 0)
    {
        printf("Please enter your password: ");
        scanf("%s", trial);
        if (strcmp(trial, correctPassword) == 0)
        {
            printf("Access granted.\n");
            adminFeature();
            return;
        }
        else
        {
            printf("Wrong password. %d attempts left.\n", trialNum);
        }
    }

    printf("Are you a hacker? No more trials for you. Get out!\n");
}

void userMode()
{
    int feature, id;
    bool login = true;

    while (login)
    {
        printf("\n1 - View your record\n2 - View today's reservations\n> ");
        scanf("%d", &feature);

        printf("Enter your ID: ");
        scanf("%d", &id);

        int index = findPatientByID(id);
        if (index != -1)
        {
            if (feature == 1)
                patientRecord(index);
            else if (feature == 2)
                reservations(index);
            else
                printf("Invalid option.\n");
        }
        else
        {
            printf("Invalid ID.\n");
        }

        char choice;
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N')
        {
            login = false;
        }
    }
}

void patientRecord(int index)
{
    printf("Patient Name: %s\n", patients[index].info.name);
    printf("Patient Age: %d\n", patients[index].info.age);
    printf("Patient Gender: %c\n", patients[index].info.gender);
}

void reservations(int index)
{
    printf("Today's reservations:\n");
    for (int i = 0; i < MAX_RESERVATIONS; i++)
    {
        if (patients[index].reservations[i] != 0)
            printf("Slot %d - %s\n", i + 1, slotTimes[i]);
    }
}

void adminFeature()
{
    int feature;
    bool login = true;

    while (login)
    {
        printf("What feature do you want?\nEnter:\n1 - Add new patient record\n2 - Edit patient record\n3 - Reserve a slot with the doctor\n4 - Cancel reservation.\n> ");
        scanf("%d", &feature);

        int id, index;

        if (feature != 1)
        {
            printf("Enter patient ID: ");
            scanf("%d", &id);
            index = findPatientByID(id);
            if (index == -1)
            {
                printf("Patient not found.\n");
                continue;
            }
        }

        switch (feature)
        {
        case 1:
            addPatient();
            break;
        case 2:
            editPatient(index);
            break;
        case 3:
            reserveSlot(index);
            break;
        case 4:
            cancelReservation(index);
            break;
        default:
            printf("Wrong entry!\n");
            break;
        }

        char choice;
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N')
        {
            login = false;
        }
    }
}

void addPatient()
{
    if (patientCount >= MAX_PATIENTS)
    {
        printf("Patient limit reached!\n");
        return;
    }

    char name[50];
    int age, id;
    char gender;

    printf("Patient name: ");
    scanf("%s", name);
    printf("Patient age: ");
    scanf("%d", &age);
    printf("Patient gender (M/F): ");
    scanf(" %c", &gender);
    printf("Patient ID: ");
    scanf("%d", &id);

    while (findPatientByID(id) != -1)
    {
        printf("This ID is already used. Try another one: ");
        scanf("%d", &id);
    }

    struct user newPatient;
    newPatient.id = id;
    strcpy(newPatient.info.name, name);
    newPatient.info.age = age;
    newPatient.info.gender = gender;
    strcpy(newPatient.password, "1234");
    newPatient.state = 'U';
    for (int i = 0; i < MAX_RESERVATIONS; i++)
        newPatient.reservations[i] = 0;

    patients[patientCount++] = newPatient;
    printf("Patient added successfully.\n");
}

void editPatient(int index)
{
    printf("New name: ");
    scanf("%s", patients[index].info.name);
    printf("New age: ");
    scanf("%d", &patients[index].info.age);
    printf("New gender (M/F): ");
    scanf(" %c", &patients[index].info.gender);
    printf("Record updated successfully.\n");
}

void reserveSlot(int index)
{
    printf("Available slots:\n");
    for (int i = 1; i <= MAX_RESERVATIONS; i++)
    {
        if (!isSlotTaken(i))
            printf("%d - %s\n", i, slotTimes[i - 1]);
    }

    int slot;
    printf("Enter reservation slot (1-5): ");
    scanf("%d", &slot);

    if (slot < 1 || slot > 5 || isSlotTaken(slot))
    {
        printf("Invalid or unavailable slot.\n");
        return;
    }

    patients[index].reservations[slot - 1] = slot;
    printf("Reservation successful for slot %d (%s).\n", slot, slotTimes[slot - 1]);
}

void cancelReservation(int index)
{
    int slot;
    bool cancellation = false;

    printf("Your reservations:\n");
    for (int i = 0; i < MAX_RESERVATIONS; i++)
    {
        if (patients[index].reservations[i] != 0)
            printf("%d - %s\n", i + 1, slotTimes[i]);
    }

    do
    {
        printf("Enter reservation slot to cancel: ");
        scanf("%d", &slot);

        if (slot < 1 || slot > 5 || patients[index].reservations[slot - 1] == 0)
        {
            printf("Invalid slot.\n");
        }
        else
        {
            cancellation = true;
        }

    } while (!cancellation);

    patients[index].reservations[slot - 1] = 0;
    printf("Reservation cancelled successfully for slot %d (%s).\n", slot, slotTimes[slot - 1]);
}

int findPatientByID(int id)
{
    for (int i = 0; i < patientCount; i++)
    {
        if (patients[i].id == id)
            return i;
    }
    return -1;
}

bool isSlotTaken(int slot)
{
    for (int i = 0; i < patientCount; i++)
    {
        for (int j = 0; j < MAX_RESERVATIONS; j++)
        {
            if (patients[i].reservations[j] == slot)
                return true;
        }
    }
    return false;
}

