#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
struct student_input
{
    char add_stu_name[100];
    int add_stu_roll, add_stu_marks[3];
};
struct student_info
{
    char stu_name[100];
    int stu_roll, stu_marks[3], total_marks;
    float percentage;
};
int main()
{
    int total_stu = 0, choice;
    bool duplicate, found;
    struct student_input sip[100];
    struct student_info sif[100];
    do
    {
        cout << "1. Add new student" << endl
             << "2. View all students" << endl
             << "3. Search student by roll number" << endl
             << "4. Update marks of a student" << endl
             << "5. Delete a student" << endl
             << "6. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1: // Adding a new student
        {
            // Main logic to add new students' info
            cout << "Enter the name of student: ";
            cin >> sip[total_stu].add_stu_name;
            cout << "Enter the roll number of student: ";
            cin >> sip[total_stu].add_stu_roll;
            for (int i = 0; i < 3; i++)
            {
                cout << "Enter the marks in subject " << i + 1 << " ,out of 100, of student: ";
                cin >> sip[total_stu].add_stu_marks[i];
            }

            // Adding marks and calculating percentage
            sif[total_stu].total_marks = 0;
            for (int i = 0; i < 3; i++)
            {
                sif[total_stu].stu_marks[i] = sip[total_stu].add_stu_marks[i];
                sif[total_stu].total_marks += sip[total_stu].add_stu_marks[i];
            }
            sif[total_stu].percentage = (sif[total_stu].total_marks * 100.0) / 300;

            cout << "Total marks: " << sif[total_stu].total_marks;

            // Logic to check duplicate
            duplicate = false;
            for (int i = 0; i < total_stu; i++)
            {
                if (strcmp(sif[i].stu_name, sip[total_stu].add_stu_name) == 0)
                {
                    duplicate = true;
                    break;
                }
                else if (sif[i].stu_roll == sip[total_stu].add_stu_roll)
                {
                    duplicate = true;
                }
            }
            if (duplicate)
            {
                cout << "A student with same name or roll number already exists...";
            }
            else
            {
                strcpy(sif[total_stu].stu_name, sip[total_stu].add_stu_name);
                sif[total_stu].stu_roll = sip[total_stu].add_stu_roll;
                total_stu++;
                cout << endl
                     << "A new student has been added successfully" << endl;
            }
            break;
        }

        case 2: // Viewing all students
        {
            cout << left
                 << setw(15) << "Student Name"
                 << setw(15) << "Roll Number"
                 << setw(15) << "Total Marks"
                 << setw(15) << "Percentage" << endl;
            for (int i = 0; i < total_stu; i++)
            {
                cout << left
                     << setw(15) << sif[i].stu_name
                     << setw(15) << sif[i].stu_roll
                     << setw(15) << sif[i].total_marks
                     << setw(15) << sif[i].percentage << endl;
            }
            break;
        }

        case 3: // Search student by roll number
        {
            int temp;
            bool temp_found = false;
            cout << "Enter the roll number of the student you want to search: ";
            cin >> temp;

            // Main logic
            for (int i = 0; i < total_stu; i++)
            {
                if (temp == sif[i].stu_roll)
                {
                    cout << left
                         << setw(15) << "Student Name"
                         << setw(15) << "Roll Number"
                         << setw(15) << "Total Marks"
                         << setw(15) << "Percentage" << endl;
                    cout << left
                         << setw(15) << sif[i].stu_name
                         << setw(15) << sif[i].stu_roll
                         << setw(15) << sif[i].total_marks
                         << setw(15) << sif[i].percentage << endl;
                    temp_found = true;
                    break; // Stop searching once found
                }
            }
            if (!temp_found)
            {
                cout << "Student not found...";
            }
            break;
        }

        case 4: // Updating the marks of student
        {
            int temp;
            bool temp_found = false;
            cout << "Enter the roll number of the student whose marks you want update: ";
            cin >> temp;

            // Finding ths student
            for (int i = 0; i < total_stu; i++)
            {
                if (temp == sif[i].stu_roll)
                {
                    temp_found = true;
                    sif[i].total_marks = 0; // This resets the marks of the student

                    // Changing the marks of the student
                    for (int j = 0; j < 3; j++)
                    {
                        cout << "Enter the marks in subject " << j + 1 << " ,out of 100, of student: ";
                        cin >> sif[i].stu_marks[j];
                        sif[i].total_marks += sif[i].stu_marks[j];
                    }
                    sif[i].percentage = (sif[i].total_marks * 100.0) / 300;
                    cout << "Marks updated successfully" << endl;
                    break;
                }
            }
            if (!temp_found)
            {
                cout << "Student not found..." << endl
                     << "Please Enter a valid roll number";
            }
            break;
        }

        case 5: // Delete a student
        {
            int temp;
            bool temp_found = false;

            cout << "Enter the roll number of the student you want to delete: ";
            cin >> temp;

            for (int i = 0; i < total_stu; i++)
            {
                if (temp == sif[i].stu_roll)
                {
                    temp_found = true;

                    // Shift all students left to overwrite the deleted one
                    for (int j = i; j < total_stu - 1; j++)
                    {
                        sif[j] = sif[j + 1];
                    }

                    total_stu--; // Reduce total count
                    cout << "Student deleted successfully." << endl;
                    break;
                }
            }

            if (!temp_found)
            {
                cout << "Student not found..." << endl;
            }
            break;
        }

        case 6: // Exit
        {
            cout << "Press Enter to exit...";
            break;
        }

        default: // Wrong option
        {
            cout << "Please enter a valid option...";
            break;
        }
        }
    } while (choice != 6);

    cin.get();
    cin.get();
    return 0;
}