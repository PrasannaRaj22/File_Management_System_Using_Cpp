#include <iostream>
#include <string>
#include <cstdlib> // For system()
#include <unistd.h> // For chdir() (Unix-specific)

int main() {
    int choice = 0;
    std::string a, b, c, command; // Using std::string instead of char arrays
    bool running = true; // Replaces d==1 with a more idiomatic flag

    std::cout << "=========================================================================\n";
    std::cout << "-----------------------File Management Project---------------------------\n";
    std::cout << "=========================================================================\n";
    std::cout << "Welcome, The Main Menu is given below:\n";
    std::cout << "1- List all Files and Directories\n";
    std::cout << "2- Create New Files\n";
    std::cout << "3- Delete Existing Files\n";
    std::cout << "4- Rename Files\n";
    std::cout << "5- Edit File Content\n";
    std::cout << "6- Search Files\n";
    std::cout << "7- Details of Particular File\n";
    std::cout << "8- View Content of File\n";
    std::cout << "9- Sort File Content\n";
    std::cout << "10- List only Directories(Folders)\n";
    std::cout << "11- List Files of Particular Extension\n";
    std::cout << "12- Compress File OR Directory\n";
    std::cout << "13- UN-Compress File OR Directory\n";
    std::cout << "14- Sort Files in a Directory\n";
    std::cout << "15- Restart Computer\n";
    std::cout << "16- Shutdown Computer\n";
    std::cout << "17- Change Directory\n";
    std::cout << "18- Execute a C file\n";
    std::cout << "19- Execute a SH file\n";
    std::cout << "20- Show Current working Directory\n";
    std::cout << "21- Create New Directory\n";
    std::cout << "22- Remove Directory\n";
    std::cout << "23- Zip File OR Directory\n";
    std::cout << "24- UN-Zip File OR Directory\n";
    std::cout << "0- Exit\n";

    while (running) {
        std::cout << "\nWhat action do you want to perform?\nEnter 1-24 OR 0 for --Exit\n";
        std::cin >> choice;

        if (choice == 0) {
            running = false; // Exit
        }
        else if (choice == 1) {
            std::cout << "Listing Files and Directories\n";
            system("ls"); // On Linux; use "dir" for Windows
        }
        else if (choice == 2) { // Create New Files
            std::cout << "Create New Files here..\nWhich type of file do you want to create?\n";
            std::cout << "1- .c\n2- .sh\n3- .txt\nEnter your choice from 1-3\n";
            std::cin >> choice;
            std::cout << "Enter File Name: ";
            std::cin >> a;

            if (choice == 1) {
                command = "touch " + a + ".c";
            }
            else if (choice == 2) {
                command = "touch " + a + ".sh";
            }
            else if (choice == 3) {
                command = "touch " + a + ".txt";
            }
            system(command.c_str()); // Convert std::string to const char* for system()
        }
        else if (choice == 3) { // Delete File
            system("ls");
            std::cout << "Choose file to delete: ";
            std::cin >> a;
            command = "rm " + a;
            std::cout << command << "\n";
            system(command.c_str());
        }
        else if (choice == 4) { // Rename File
            system("ls");
            std::cout << "Enter file name which you want to rename: ";
            std::cin >> a;
            std::cout << "Enter the new name: ";
            std::cin >> c;
            command = "mv " + a + " " + c;
            std::cout << command << "\n";
            system(command.c_str());
        }
        else if (choice == 5) { // Edit File Content
            system("ls");
            std::cout << "Enter file name in which you want to add content (.c and .txt only): ";
            std::cin >> a;
            std::cout << "Enter content to add: ";
            std::cin.ignore(); // Clear buffer
            std::getline(std::cin, b); // Allow spaces in content
            command = "echo \"" + b + "\" >> " + a;
            system(command.c_str());
        }
        else if (choice == 6) { // Search Files
            std::cout << "Enter File Name: ";
            std::cin >> a;
            command = "find / -name \"" + a + "\" 2>/dev/null";
            system(command.c_str());
        }
        else if (choice == 7) { // Details of Particular File
            std::cout << "1-Display details of all files\n2-Display details of specific files\n";
            std::cout << "3-File Type of specific files\n4-File Size of specific files\n";
            std::cin >> choice;

            if (choice == 1) {
                system("ls -l");
            }
            else if (choice == 2) {
                system("ls");
                std::cout << "Enter file: ";
                std::cin >> a;
                command = "stat " + a;
                system(command.c_str());
            }
            else if (choice == 3) {
                system("ls");
                std::cout << "Enter file name and extension: ";
                std::cin >> a;
                command = "file " + a;
                system(command.c_str());
            }
            else if (choice == 4) {
                system("ls");
                std::cout << "Enter file name and extension: ";
                std::cin >> a;
                command = "ls -lh " + a;
                system(command.c_str());
            }
            else {
                std::cout << "Wrong entry\n";
            }
        }
        else if (choice == 8) { // View Content of File
            system("ls");
            std::cout << "Choose file to show content: ";
            std::cin >> a;
            command = "cat " + a;
            system(command.c_str());
        }
        else if (choice == 9) { // Sort File Content
            system("ls");
            std::cout << "Choose file to sort content (Ascending by Alphabets): ";
            std::cin >> a;
            command = "sort " + a;
            system(command.c_str());
        }
        else if (choice == 10) { // List only Directories
            system("ls -dF */");
        }
        else if (choice == 11) { // List Files of Particular Extension
            std::cout << "Enter extension to find files (dont add . --> !.c only c): ";
            std::cin >> a;
            command = "ls -F *." + a;
            system(command.c_str());
        }
        else if (choice == 12) { // Compress Files
            system("ls");
            std::cout << "Enter Files names with extension (For multiple files add space between them): ";
            std::cin.ignore();
            std::getline(std::cin, b);
            std::cout << "Enter Name for Tar file: ";
            std::cin >> a;
            command = "tar -cvf " + a + ".tar " + b;
            system(command.c_str());
        }
        else if (choice == 13) { // UnCompress Files
            system("ls");
            std::cout << "Enter Name for Tar file (without Extension): ";
            std::cin >> a;
            command = "tar -xvf " + a + ".tar";
            system(command.c_str());
        }
        else if (choice == 14) { // Sort Files in a Directory
            std::cout << "1-Sort by modification time+details (oldest first)\n2-Sort by modification time (newest first)\n";
            std::cout << "3-Sort by file size (smallest first)\n4-Sort by file size (largest first)\n";
            std::cin >> choice;
            if (choice == 1) system("ls -lt");
            else if (choice == 2) system("ls -lrt");
            else if (choice == 3) system("ls -lS");
            else if (choice == 4) system("ls -lrS");
            else std::cout << "Invalid Entry\n";
        }
        else if (choice == 15) { // Shutdown Computer
            system("shutdown -h now");
        }
        else if (choice == 16) { // Restart Computer
            system("shutdown -r now");
        }
        else if (choice == 17) { // Change Directory
            bool innerLoop = true;
            system("ls");
            while (innerLoop) {
                std::cout << "1..Go back\n2..open\n0..Dont Want to Change Directory\n";
                std::cin >> choice;
                if (choice == 0) {
                    innerLoop = false;
                }
                else if (choice == 1) {
                    chdir(".."); // Go back one directory
                    system("ls");
                }
                else if (choice == 2) {
                    std::cout << "Enter Directory name: ";
                    std::cin >> a;
                    if (chdir(a.c_str()) == 0) {
                        system("ls");
                    } else {
                        std::cout << "Directory not found\n";
                    }
                }
                else {
                    std::cout << "Function not implemented yet or invalid entry\n";
                }
            }
        }
        else if (choice == 18) { // Execute a C file
            system("ls");
            std::cout << "Choose C file to execute (Only name without C extension): ";
            std::cin >> a;
            command = "gcc -o pro " + a + ".c && ./pro";
            system(command.c_str());
        }
        else if (choice == 19) { // Execute a Shell file
            system("ls");
            std::cout << "Choose Shell file to execute (Only name without sh extension): ";
            std::cin >> a;
            command = "./" + a + ".sh";
            system(command.c_str());
        }
        else if (choice == 20) { // Print Current Directory
            system("pwd");
        }
        else if (choice == 21) { // Create new Directory
            std::cout << "Enter Directory name to create: ";
            std::cin >> a;
            command = "mkdir " + a;
            system(command.c_str());
        }
        else if (choice == 22) { // Remove Directory
            std::cout << "Enter Directory name to remove: ";
            std::cin >> a;
            command = "rmdir " + a;
            system(command.c_str());
        }
        else if (choice == 23) { // Zip Files
            system("ls");
            std::cout << "Enter Files names with extension (For multiple files add space between them): ";
            std::cin.ignore();
            std::getline(std::cin, b);
            std::cout << "Enter Name for Zip file: ";
            std::cin >> a;
            command = "zip " + a + ".zip " + b;
            system(command.c_str());
        }
        else if (choice == 24) { // UnZip Files
            system("ls");
            std::cout << "Enter Name for Zip file (without Extension): ";
            std::cin >> a;
            command = "unzip " + a + ".zip";
            system(command.c_str());
        }
        else {
            std::cout << "Invalid choice, please select 0-24\n";
        }
    }
    return 0;
}
