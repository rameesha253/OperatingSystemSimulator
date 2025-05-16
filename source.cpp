#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <string.h>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

int harddisk, ram, cores;
pthread_mutex_t lock[15];
int memory[100];
string tasks[100];
int ind = -1;
int counter = 0;
bool checkIfKernel = false;

void *taskManager(void *arg) // taskmanager
{
    cout << endl
         << "		Active Tasks			MB \n";
    for (int i = 0; i < counter; i++)
    {
        if (memory[i] == 0)
        {
            continue;
        }
        else
        {
            cout << "		Task" << i + 1 << " : " << tasks[i] << "		" << memory[i] << endl;
        }
    }
    pthread_exit(NULL);
}

void freeMemory(int &sum, int &size, string &var)
{
    for (int i = 0; i < counter; i++)
    {
        memory[i] = 0;
        tasks[i] = " ";
    }
    ind = -1;
    counter = 0;
    sum = 0;
    size = 0;
    var;
}

// functions
// 1
void *calender(void *arg)
{
    pthread_mutex_lock(&lock[1]);
    system("g++ calendar.cpp -o calendar ");
    system("gnome-terminal -- \"./calendar\"");
    pthread_mutex_unlock(&lock[1]);
    pthread_exit(NULL);
}
// 2
void *calculator(void *arg)
{
    pthread_mutex_lock(&lock[2]);
    system("g++ calculator.cpp -o calculator ");
    system("gnome-terminal -- \"./calculator\"");
    pthread_mutex_unlock(&lock[2]);
    pthread_exit(NULL);
}
// 3

void *tictactoe(void *arg)
{
    pthread_mutex_lock(&lock[3]);
    system("g++ tictactoe.cpp -o tictactoe ");
    system("gnome-terminal -- \"./tictactoe\"");
    pthread_mutex_unlock(&lock[3]);
    pthread_exit(NULL);
}
// 4

void *createfile(void *arg)
{
    pthread_mutex_lock(&lock[4]);
    system("g++ CreateFile.cpp -o CreateFile ");
    system("gnome-terminal -- \"./CreateFile\"");
    pthread_mutex_unlock(&lock[4]);
    pthread_exit(NULL);
}
// 5

void *movefile(void *arg)
{
    pthread_mutex_lock(&lock[5]);
    system("g++ moveFile.cpp -o moveFile ");
    system("gnome-terminal -- \"./moveFile\"");
    pthread_mutex_unlock(&lock[5]);
    pthread_exit(NULL);
}
// 6
void *deletefile(void *arg)
{
    pthread_mutex_lock(&lock[6]);
    system("g++ delete.cpp -o delete ");
    system("gnome-terminal -- \"./delete\"");
    pthread_mutex_unlock(&lock[6]);
    pthread_exit(NULL);
}
// 7
void *notepad(void *arg)
{
    pthread_mutex_lock(&lock[7]);
    system("g++ notepad.cpp -o notepad ");
    system("gnome-terminal -- \"./notepad\"");
    pthread_mutex_unlock(&lock[7]);
    pthread_exit(NULL);
}
// 8
void *createdirectory(void *arg)
{
    pthread_mutex_lock(&lock[8]);
    system("g++ CreateDirectory.cpp -o CreateDirectory ");
    system("gnome-terminal -- \"./CreateDirectory\"");
    pthread_mutex_unlock(&lock[8]);
    pthread_exit(NULL);
}
// 9
void *stopwatch(void *arg)
{
    pthread_mutex_lock(&lock[9]);
    system("g++ stopwatch.cpp -o stopwatch ");
    system("gnome-terminal -- \"./stopwatch\"");
    pthread_mutex_unlock(&lock[9]);
    pthread_exit(NULL);
}
// 10
void *deletedirectory(void *arg)
{
    pthread_mutex_lock(&lock[11]);
    system("g++ DeleteDirectory.cpp -o DeleteDirectory ");
    system("gnome-terminal -- \"./DeleteDirectory\"");
    pthread_mutex_unlock(&lock[11]);
    pthread_exit(NULL);
}
// 11
void *displayfile(void *arg)
{
    system("g++ DisplayFile.cpp -o DisplayFile ");
    system("gnome-terminal -- \"./DisplayFile\"");
    pthread_mutex_unlock(&lock[12]);
    pthread_exit(NULL);
}

// 12
void *time(void *arg)
{
    pthread_mutex_lock(&lock[14]);
    system("g++ Time.cpp -o Time ");
    system("gnome-terminal -- \"./Time\"");
    pthread_mutex_unlock(&lock[14]);
    pthread_exit(NULL);
}
// End
void startup()
{

    // Set the loading bar width
    const int barWidth = 20;

    cout << "Loading...\n";

    // Loop through the loading sequence
    for (int i = 0; i <= barWidth; i++)
    {
        cout << "[";
        // Print the progress bar
        for (int j = 0; j < barWidth; j++)
        {
            if (j < i)
            {
                cout << "#";
            }
            else
            {
                cout << ".";
            }
        }
        cout << "] " << int(i / (float)barWidth * 100.0) << " %\r";
        cout.flush();

        // Delay for a short amount of time to simulate the loading
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << endl
         << "Loading complete!\n";
    sleep(5);
    system("clear");
}
void userMode()
{
    ram = 2 * 1024;
    harddisk = 250 * 1024;
    checkIfKernel = false;
}
void kernelMode()
{
    cout << "Enter the amount of Ram(GB) : ";
    cin >> ram;
    cout << "Enter the amount of Hardisk(GB) : ";
    cin >> harddisk;
    cout << "Enter the amount of cores : ";
    cin >> cores;
    ram = ram * 1024;
    harddisk = harddisk * 1024;
    checkIfKernel = true;
}
void resources()
{
    cout << endl;
    cout << "		Ram Available: " << ram << " MB\n";
    cout << "		Hardisk Available: " << harddisk << " MB\n";
    cout << endl;
}
void menu()
{
    int mode = 0;
    cout << "Select the booting mode \n";
    cout << "1. User Mode \n";
    cout << "2. Kernel Mode " << endl
         << endl;
    cout << "Choice : ";
    cin >> mode;
    while (mode != 1 && mode != 2)
    {
        cout << "Enter correct mode : ";
        cin >> mode;
    }
    if (mode == 1)
        userMode();
    else if (mode == 2)
        kernelMode();
    else
        cout << "Enter a Valid Choice \n";
}

void Main_Menu()
{
    bool check = false;
    pthread_t thread[15];
    for (int i = 0; i < 15; ++i)
    {
        pthread_mutex_init(&lock[i], NULL);
    }
    int sum = 0;
    int size = 0;
    string var;
    int choice;
    while (true)
    {
        system("clear");
        cout << endl;
        cout << "0.  Task Manager\n";
        cout << "1.  Calendar\n";
        cout << "2.  Calculator\n";
        cout << "3.  Tic Tac Toe\n";
        cout << "4.  Make a new File\n";
        cout << "5.  Move a File \n";
        cout << "6.  Delete a File \n";
        cout << "7.  Notepad \n";
        cout << "8.  Create Directory \n";
        cout << "9.  Stopwatch \n";
        //cout << "10. Hangman\n";
        cout << "10. Delete Directory\n";
        cout << "11. Open A file\n";
        //cout << "13. Find String in File\n";
        cout << "12. System Time \n";
        cout << "13. Shut Down" << endl << endl;
        cout << "Choice : ";
        cin >> choice;
        if (choice == 0)
        {
            pthread_create(&thread[choice], NULL, &taskManager, NULL);
            pthread_join(thread[choice], NULL);
        }
        else if (choice == 1)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << endl
                     << "  ... Can't Allocate Memory ...\n";
                check = true;
            }
            if (check != true)
            {
                var = "Calendar";
                size = 150;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &calender, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 2)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ...\n";
                check = true;
            }
            if (check != true)
            {
                var = "Calculator";
                size = 80;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &calculator, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 3)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ...\n";
                check = true;
            }
            if (check != true)
            {
                var = "TicTacToe";
                size = 150;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &tictactoe, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 4)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ...\n";
                check = true;
            }
            if (check != true)
            {
                var = "MakeFile";
                size = 10;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &createfile, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 5)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ...\n";
                check = true;
            }
            if (check != true)
            {
                var = "MoveFile";
                size = 20;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &movefile, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 6)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ...\n";
                check = true;
            }
            if (check != true)
            {
                var = "DeleteFile";
                size = 100;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &deletefile, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 7)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ...\n";
                check = true;
            }
            if (check != true)
            {
                var = "Notepad";
                size = 100;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &notepad, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 8)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ...\n";
                check = true;
            }
            if (check != true)
            {
                var = "CreateDirectory";
                size = 50;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &createdirectory, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 9)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ...\n";
                check = true;
            }
            if (check != true)
            {
                var = "Stopwatch";
                size = 50;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &stopwatch, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 10)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ...\n";
                check = true;
            }
            if (check != true)
            {
                var = "DeleteDirectory";
                size = 150;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &deletedirectory, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 11)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ...\n";
                check = true;
            }
            if (check != true)
            {
                var = "Display a File";
                size = 150;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &displayfile, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 12)
        {
            for (int i = 0; i < counter; i++)
            {
                sum = sum + memory[i];
            }
            if (sum > ram)
            {
                cout << "  ... Can't Allocate Memory ...\n";
                check = true;
            }
            if (check != true)
            {
                var = "Time";
                size = 100;
                ind++;
                tasks[ind] = var;
                memory[ind] = size;
                counter++;

                int f = fork();
                if (f > 0)
                {
                    wait(NULL);
                }
                else
                {
                    pthread_create(&thread[choice], NULL, &time, NULL);
                    pthread_join(thread[choice], NULL);
                    exit(0);
                }
            }
        }

        else if (choice == 13)
        {
            cout << "\e[1;32m\n";
            system("clear");
            cout << "\n\n\n\t    --- Shutting Down --- \n";
            sleep(3);
            system("xdotool getactivewindow windowkill");
            break;
        }
        else
        {
            cout << "Enter a Valid Choice\n";
            sleep(2);
            continue;
        }

        // checking if the memory is full (start)
        int Memory = 0;
        if (checkIfKernel == true)
        {
            if (check == true)
            {
                Memory = 0;
                cout << endl
                     << "1. Free memory\n";
                cout << "2. ShutDown";
                cout << endl
                     << "Choice : ";
                cin >> Memory;
                cout << endl;
                if (Memory == 1)
                {
                    system("clear");
                    cout << "		Freeing up memory from the task manager ....\n\n";
                    sleep(3);
                    freeMemory(sum, size, var);
                    cout << "Memory freed successfully \n";
                    cout << "Press 1 to continue to main page\n";
                    cin >> Memory;
                    if (Memory == 1)
                    {
                        check = false;
                        continue;
                    }
                    else
                    {
                        check = false;
                        continue;
                    }
                }
                else
                {
                    check = false;
                    cout << "\e[1;32m\n";
                    system("clear");
                    cout << "\n\n\n\t    --- Shutting Down --- \n";
                    sleep(3);
                    system("xdotool getactivewindow windowkill");
                    break;
                }
            }
        }
        else
        {
            if (check == true)
            {
                cout << "Not enough rights to free up memory \n";
                sleep(3);
                int key = 0;
                cout << "\e[1;32m\n";
                cout << "Press any key to shutdown \n\n";
                cin >> key;
                system("clear");
                cout << "\n\n\n\t   	 --- Shutting Down --- \n";
                sleep(3);
                system("xdotool getactivewindow windowkill");
                break;
            }
        }
        // (end)
        cout << endl << endl;
        cout << "		0 to Close  || 1 to Minimize || 2 to multitask\n";
        int choice1;
        cout << "Choice : ";
        cin >> choice1;
        if (choice1 == 0)
        {
            int check = -1;
            cout << "        -- You have Closed -- \n\n";
            if (choice == 0)
            {
                continue;
            }
            else
            {
                for (int i = 0; i < counter; i++)
                {
                    if (tasks[i] == var)
                    {
                        check = i;
                    }
                }
                memory[check] = 0;
                tasks[check] = " ";
                system("pause");
            }
        }
        else if (choice1 == 1)
        {
            cout << "        -- You have Minimized -- \n\n";
            system("pause");
        }
        else if (choice1 == 2)
        {
            continue;
        }
        else
        {
            cout << "Enter a Valid Choice\n";
        }
    }
}

int main()
{

    startup();
    cout << "\e[1;32m\n";
    menu();
    resources();
    Main_Menu();
    return 0;
}
