# File_Management_System_Using_Cpp

Overview
The File Management Project is a command-line application written in C++ that provides a menu-driven interface for managing files and directories on a Unix-like operating system (e.g., Linux). It allows users to perform various file system operations such as creating, deleting, renaming, and compressing files, as well as managing directories and executing scripts. The program leverages system commands executed via the system() function and uses chdir() for directory navigation.

This project is designed as a simple tool for file system interaction and serves as an educational example of C++ programming with system-level integration.

Features
File Operations:
List all files and directories
Create new files (.c, .sh, .txt)
Delete existing files
Rename files
Edit file content (append text)
View file content
Sort file content alphabetically
Search for files across the system
Display file details (permissions, size, type)
Directory Operations:
List only directories
Create new directories
Remove directories
Change current working directory
Show current working directory
File Filtering and Sorting:
List files by specific extension
Sort files in a directory by modification time or size
Compression:
Compress files/directories into .tar or .zip
Decompress .tar or .zip files
System Commands:
Execute C files (compile and run)
Execute shell (.sh) files
Restart or shutdown the computer
Prerequisites
Operating System: Unix-like system (e.g., Linux - Ubuntu, Kali). Note: Not compatible with Windows without modifications.
Compiler: A C++ compiler (e.g., g++).
Dependencies: Standard C++ libraries (iostream, string, cstdlib, unistd.h) and common Unix utilities (ls, touch, rm, tar, zip, etc.).
Installation
Clone or Download:
Clone this repository or download the source code file (file_management.cpp).
Compile the Code:
Open a terminal in the project directory.
Compile the C++ code using:
bash

Collapse

Wrap

Copy
g++ file_management.cpp -o filemgmt
Run the Program:
Execute the compiled binary:
bash

Collapse

Wrap

Copy
./filemgmt
Usage
Launch the program by running ./filemgmt.
The main menu will display 24 options (0 to exit):
text

Collapse

Wrap

Copy
=========================================================================
-----------------------File Management Project---------------------------
=========================================================================
Welcome, The Main Menu is given below:
1- List all Files and Directories
2- Create New Files
...
24- UN-Zip File OR Directory
0- Exit
Enter a number (0-24) to select an action.
Follow the prompts to provide inputs (e.g., filenames, extensions) as required.
Example: To create a new .txt file:
Select 2, then 3 (for .txt), enter a filename (e.g., note), and the file note.txt will be created.
Example Commands
List Files: Select 1 → Runs ls.
Create File: Select 2 → Choose file type → Enter name (e.g., test) → Creates test.txt.
Delete File: Select 3 → Enter filename (e.g., test.txt) → Deletes it.
Compress Files: Select 12 → Enter filenames (e.g., file1.txt file2.txt) → Enter tar name (e.g., archive) → Creates archive.tar.
Limitations
Platform-Specific: Designed for Unix-like systems; commands like ls, tar, and shutdown won’t work on Windows without modification.
Security: Uses system() with user inputs, potentially vulnerable to command injection if inputs aren’t sanitized (no sanitization implemented).
Error Handling: Minimal; assumes commands execute successfully.
Input Constraints: Some operations (e.g., editing content) don’t handle multi-word inputs perfectly due to cin behavior.
Future Improvements
Cross-Platform Support: Use C++’s <filesystem> library (C++17) for portable file operations instead of system() calls.
Input Sanitization: Add validation to prevent command injection and handle edge cases.
Advanced Error Handling: Check system() return values and provide feedback on failures.
Windows Compatibility: Replace Unix commands with Windows equivalents (e.g., dir for ls, del for rm).
GUI Option: Extend to a graphical interface using libraries like Qt.
Contributing
Feel free to fork this repository, submit pull requests, or report issues. Contributions to enhance functionality, security, or portability are welcome!

License
This project is open-source and available under the MIT License.
