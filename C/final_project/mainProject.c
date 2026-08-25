#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"


/* ========================= Global Variables ========================= */

U16 IndexID;
U16 patients_counter = 0;


/* ========================= Function Prototypes ========================= */

U16 Choose_mode();

U16 AddNewPatient();

U8 isIdExists(U32 ID);

U8 EditPatientRecord(U32 ID);

void PrintpatientInfo(U32 ID);

U8 ReserveAslot(U32 ID);

void PrintAvaSlots();

void PrintNotAvaSlots();

void AdminOptions();

U8 CancelReservation(U32 ID);

void AfterOperation();

void ViewTodayReservations();

void UserOptions(U32 ID);

void ViewMyReservations(U32 ID);


/* ========================= After Operation ========================= */

void AfterOperation()
{
    U8 wanna;

    printf("\n===== What would you like to do? =====\n");
    printf("===== 1. Return to Admin Mode or User Mode =====\n");
    printf("===== Any number for Exit =====\n");

    scanf("%hu", &wanna);

    if(wanna == 1)
    {
        Choose_mode();
    }
    else
    {
        printf("\nGoodbye\n");

        exit(0);
    }
}


/* ========================= Patient Structure ========================= */

typedef struct
{
    U8 name[20];
    U16 age;
    U8 gender[10];
    U32 ID;
} Patient;


/* ========================= Global Appointment Data ========================= */

U32 slots[5] = {0};

U8 Appointments[5][20] =
{
    "2pm to 2:30pm",
    "2:30pm to 3pm",
    "3pm to 3:30pm",
    "4pm to 4:30pm",
    "4:30pm to 5pm"
};


/* ========================= Global Patient Data ========================= */

Patient patients[100];


/* ========================= Main Function ========================= */

U16 main(void)
{
    int x = Choose_mode();

    return 0;
}


/* ========================= Check Patient ID ========================= */

U8 isIdExists(U32 ID)
{
    for (U16 i = 0; i < patients_counter; i++)
    {
        if (ID == patients[i].ID)
        {
            IndexID = i;

            return 0;
        }
    }

    return 1;
}


/* ========================= Print Patient Information ========================= */

void PrintpatientInfo(U32 ID)
{
    printf("\n===== Patient Information =====\n");

    printf("Name: %s\n", patients[IndexID].name);
    printf("Age: %u\n", patients[IndexID].age);
    printf("Gender: %s\n", patients[IndexID].gender);
    printf("ID: %lu\n", patients[IndexID].ID);
}


/* ========================= Add New Patient ========================= */

U16 AddNewPatient()
{
    printf("\n===== Add New Patient =====\n");

    printf("Enter patient name: ");
    scanf("%s", patients[patients_counter].name);

    printf("Enter patient age: ");
    scanf("%d", &patients[patients_counter].age);

    printf("Enter patient gender: ");
    scanf("%s", patients[patients_counter].gender);

    printf("Enter patient ID: ");

    do
    {
        scanf("%lu", &patients[patients_counter].ID);

        if (isIdExists(patients[patients_counter].ID) == 0)
        {
            U8 want_to_add;

            printf(
                "This ID already exists.\n"
                "If you want to enter another ID press 1.\n"
                "If you want other options enter any number: "
            );

            scanf("%hu", &want_to_add);

            if(want_to_add == 1)
            {
                AddNewPatient();
            }
            else
            {
                AfterOperation();
            }
        }

        else
        {
            printf("\nPatient information has been recorded successfully.\n");

            IndexID = patients_counter;

            PrintpatientInfo(patients[patients_counter].ID);

            patients_counter++;

            AfterOperation();

            break;
        }

    } while (1);

    return 1;
}


/* ========================= Edit Patient Record ========================= */

U8 EditPatientRecord(U32 ID)
{
    if (isIdExists(ID) == 0)
    {
        U8 EditField;

        printf("\nYou can edit the patient's information.\n");

        printf("\n===== Choose an Attribute to Edit =====\n");

        printf("Please choose:\n");
        printf("1. Name\n");
        printf("2. Age\n");
        printf("3. Gender\n");
        printf("4. ID\n");

        printf("Enter your choice: ");

        scanf("%u", &EditField);


        if (EditField == 1)
        {
            printf("Enter new name:\n");

            scanf("%s", patients[IndexID].name);
        }

        else if (EditField == 2)
        {
            printf("Enter new age:\n");

            scanf("%u", &patients[IndexID].age);
        }

        else if (EditField == 3)
        {
            printf("Enter new gender:\n");

            scanf("%s", patients[IndexID].gender);
        }

        else if (EditField == 4)
        {
            printf("Enter new ID:\n");

            scanf("%lu", &patients[IndexID].ID);
        }

        else
        {
            printf("Invalid choice.\n");

            return 0;
        }


        printf("\nPatient information has been updated successfully.\n");

        PrintpatientInfo(ID);


        U8 want_to_add;

        printf(
            "\nIf you want to edit this record again press 1.\n"
            "If you want other options enter any number: "
        );

        scanf("%hu", &want_to_add);


        if(want_to_add == 1)
        {
            EditPatientRecord(ID);
        }

        else
        {
            AfterOperation();
        }


        return 1;
    }

    else
    {
        printf(
            "\nYou cannot edit the patient's information "
            "because the patient does not exist.\n"
        );


        U8 want_to_add;

        printf(
            "\nIf you want to enter another ID press 1.\n"
            "If you want other options enter any number: "
        );

        scanf("%hu", &want_to_add);


        if(want_to_add == 1)
        {
            EditPatientRecord(ID);
        }

        else
        {
            AfterOperation();
        }


        return 0;
    }
}


/* ========================= Print Available Slots ========================= */

void PrintAvaSlots()
{
    printf("\n===== Available Slots =====\n");

    for (U8 i = 0; i < 5; i++)
    {
        if (slots[i] == 0)
        {
            printf("%d. %s\n", i + 1, Appointments[i]);
        }
    }
}


/* ========================= Print Not Available Slots ========================= */

void PrintNotAvaSlots()
{
    printf("\n===== Not Available Slots =====\n");

    for (U8 i = 0; i < 5; i++)
    {
        if (slots[i] != 0)
        {
            printf(
                "%d. %s --> Patient ID: %lu\n",
                i + 1,
                Appointments[i],
                slots[i]
            );
        }
    }
}


/* ========================= Reserve A Slot ========================= */

U8 ReserveAslot(U32 ID)
{
    if (isIdExists(ID) == 0)
    {
        U8 ChooseSlot;

        PrintAvaSlots();

        printf("\nPlease choose a slot:\n");
        printf("Enter your choice: ");

        scanf("%hu", &ChooseSlot);


        if (ChooseSlot >= 1 && ChooseSlot <= 5)
        {
            if (slots[ChooseSlot - 1] == 0)
            {
                /*
                 * Store Patient ID inside the slot
                 */
                slots[ChooseSlot - 1] = ID;


                printf(
                    "\nSlot %s has been successfully reserved "
                    "for patient ID %lu.\n",
                    Appointments[ChooseSlot - 1],
                    ID
                );


                AfterOperation();

                return 1;
            }

            else
            {
                U8 want_to_add;

                printf(
                    "\nThis slot is already reserved.\n"
                    "If you want to choose another slot press 1.\n"
                    "If you want other options enter any number: "
                );

                scanf("%hu", &want_to_add);


                if(want_to_add == 1)
                {
                    ReserveAslot(ID);
                }

                else
                {
                    AfterOperation();
                }


                return 0;
            }
        }

        else
        {
            U8 want_to_add;

            printf(
                "\nInvalid slot.\n"
                "If you want to try again press 1.\n"
                "If you want other options enter any number: "
            );

            scanf("%hu", &want_to_add);


            if(want_to_add == 1)
            {
                ReserveAslot(ID);
            }

            else
            {
                AfterOperation();
            }


            return 0;
        }
    }

    else
    {
        printf("\nThis patient ID is invalid.\n");

        printf(
            "Please enter a correct ID "
            "or add the patient to the database.\n"
        );

        AfterOperation();

        return 0;
    }
}


/* ========================= Cancel Reservation ========================= */

U8 CancelReservation(U32 ID)
{
    if (isIdExists(ID) == 0)
    {
        U8 ChooseSlot;

        PrintNotAvaSlots();

        printf("\nPlease choose a slot:\n");
        printf("Enter your choice: ");

        scanf("%hu", &ChooseSlot);


        if (ChooseSlot >= 1 && ChooseSlot <= 5)
        {
            /*
             * The slot contains the Patient ID.
             */
            if (slots[ChooseSlot - 1] == ID)
            {
                slots[ChooseSlot - 1] = 0;


                printf(
                    "\nSlot %s has been successfully cancelled "
                    "for patient ID %lu.\n",
                    Appointments[ChooseSlot - 1],
                    ID
                );


                PrintAvaSlots();

                AfterOperation();

                return 1;
            }

            else
            {
                U8 want_to_add;

                printf(
                    "\nThis slot is not reserved for this patient.\n"
                    "If you want to choose another slot press 1.\n"
                    "If you want other options enter any number: "
                );

                scanf("%hu", &want_to_add);


                if(want_to_add == 1)
                {
                    CancelReservation(ID);
                }

                else
                {
                    AfterOperation();
                }


                return 0;
            }
        }

        else
        {
            U8 want_to_add;

            printf(
                "\nInvalid slot.\n"
                "If you want to try again press 1.\n"
                "If you want other options enter any number: "
            );

            scanf("%hu", &want_to_add);


            if(want_to_add == 1)
            {
                CancelReservation(ID);
            }

            else
            {
                AfterOperation();
            }


            return 0;
        }
    }

    else
    {
        printf("\nThis patient ID is invalid.\n");

        printf(
            "Please enter a correct ID "
            "or add the patient to the database.\n"
        );

        AfterOperation();

        return 0;
    }
}


/* ========================= Admin Options ========================= */

void AdminOptions()
{
    U16 OptionsMode;


    printf("\n===== Admin Options =====\n");

    printf("1. Add new patient record\n");
    printf("2. Edit patient record\n");
    printf("3. Reserve a slot with the doctor\n");
    printf("4. Cancel reservation\n");
    printf("5. View today's reservations\n");

    printf("Enter your choice: ");

    scanf("%hu", &OptionsMode);


    /* ========================= Add Patient ========================= */

    if (OptionsMode == 1)
    {
        printf("\nYou are in Add Patient Record.\n");

        AddNewPatient();
    }


    /* ========================= Edit Patient ========================= */

    else if (OptionsMode == 2)
    {
        U32 PatientID;

        printf("\nYou are in Edit Patient Record.\n");

        printf("Please enter the patient's ID:\n");


        do
        {
            scanf("%lu", &PatientID);


            if (EditPatientRecord(PatientID) == 0)
            {
                printf("\nPlease enter the patient's ID again:\n");
            }

            else
            {
                break;
            }

        } while (1);


        AdminOptions();
    }


    /* ========================= Reserve Doctor Slot ========================= */

    else if (OptionsMode == 3)
    {
        U32 ID;

        printf("\nYou are in Reserve a Slot with the Doctor.\n");

        printf("Please enter patient's ID:\n");

        scanf("%lu", &ID);

        ReserveAslot(ID);
    }


    /* ========================= Cancel Reservation ========================= */

    else if (OptionsMode == 4)
    {
        U32 ID;

        printf("\nYou are in Cancel Reservation.\n");

        printf("Please enter patient's ID:\n");

        scanf("%lu", &ID);

        CancelReservation(ID);
    }


    /* ========================= View Today's Reservations ========================= */

    else if (OptionsMode == 5)
    {
        ViewTodayReservations();

        AfterOperation();
    }


    /* ========================= Invalid Admin Option ========================= */

    else
    {
        printf("\nInvalid choice. Please try again.\n");


        U8 want_to_add;

        printf(
            "If you want to choose another Admin option press 1.\n"
            "If you want other options enter any number: "
        );

        scanf("%hu", &want_to_add);


        if(want_to_add == 1)
        {
            AdminOptions();
        }

        else
        {
            AfterOperation();
        }
    }
}


/* ========================= View Today's Reservations ========================= */

void ViewTodayReservations()
{
    U8 found = 0;

    printf("\n===== Today's Reservations =====\n");


    for(U8 i = 0; i < 5; i++)
    {
        if(slots[i] != 0)
        {
            printf(
                "%d. Slot: %s --> Patient ID: %lu\n",
                i + 1,
                Appointments[i],
                slots[i]
            );

            found = 1;
        }
    }


    if(found == 0)
    {
        printf("There are no reservations today.\n");
    }
}


/* ========================= User Options ========================= */

void UserOptions(U32 ID)
{
    U8 UserOption;


    printf("\n===== User Options =====\n");

    printf("1. View My Information\n");
    printf("2. View My Reservations\n");

    printf("Enter your choice: ");

    scanf("%hhu", &UserOption);


    /* ========================= View Patient Information ========================= */

    if(UserOption == 1)
    {
        PrintpatientInfo(ID);

        AfterOperation();
    }


    /* ========================= View Patient Reservations ========================= */

    else if(UserOption == 2)
    {
        ViewMyReservations(ID);

        AfterOperation();
    }


    /* ========================= Invalid User Option ========================= */

    else
    {
        printf("\nInvalid choice. Please try again.\n");

        UserOptions(ID);
    }
}


/* ========================= View My Reservations ========================= */

void ViewMyReservations(U32 ID)
{
    U8 found = 0;


    printf("\n===== My Reservations =====\n");


    for(U8 i = 0; i < 5; i++)
    {
        if(slots[i] == ID)
        {
            printf(
                "%d. Slot: %s\n",
                i + 1,
                Appointments[i]
            );

            found = 1;
        }
    }


    if(found == 0)
    {
        printf("You don't have any reservations today.\n");
    }
}


/* ========================= Choose Mode ========================= */

U16 Choose_mode()
{
    int UserOrAdminmode;


    printf("\n===== Hospital Management System =====\n");

    printf("Please choose:\n");

    printf("1. Admin Mode\n");
    printf("2. User Mode\n");
    printf("3. Exit\n");

    printf("Enter your choice: ");

    scanf("%d", &UserOrAdminmode);


    /* ========================= Admin Mode ========================= */

    if (UserOrAdminmode == 1)
    {
        printf("\nWelcome to Admin Mode.\n");


        int pass;


        /* ========================= Admin Password ========================= */

        for (int i = 0; i < 3; i++)
        {
            printf("Please enter your password: ");

            scanf("%d", &pass);


            if (pass == 1234)
            {
                break;
            }


            if (i == 2)
            {
                printf("Incorrect password. Access denied.\n");

                return 0;
            }


            printf("Incorrect password. Please try again.\n");
        }


        /* ========================= Open Admin Options ========================= */

        AdminOptions();

        return UserOrAdminmode;
    }


    /* ========================= User Mode ========================= */

    else if (UserOrAdminmode == 2)
    {
        U32 PatientID;


        printf("\nWelcome to User Mode.\n");

        printf("Please enter the patient's ID:\n");


        do
        {
            scanf("%lu", &PatientID);


            if (isIdExists(PatientID) == 1)
            {
                printf("Patient ID does not exist.\n");

                printf("Please enter the patient's ID again:\n");
            }

            else
            {
                break;
            }

        } while (1);


        /*
         * Send the patient's ID to UserOptions.
         */
        UserOptions(PatientID);


        return UserOrAdminmode;
    }


    /* ========================= Exit ========================= */

    else if(UserOrAdminmode == 3)
    {
        printf("\nGoodbye\n");

        exit(0);
    }


    /* ========================= Invalid Mode ========================= */

    else
    {
        printf("\nInvalid choice. Please try again.\n");

        Choose_mode();
    }


    return 0;
}