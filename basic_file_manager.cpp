#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {
    int choice;
    string fileName, new_dir_name;

    while (true) {
        cout << "\n----- Simple File Manager ------" << endl;
        cout << "1. List Files In Current Directory " << endl;
        cout << "2. View File " << endl;
        cout << "3. Create a New Directory " << endl;
        cout << "4. Copy a File " << endl;
        cout << "5. Exit " << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        if (choice == 5) { 
            break;
        }

        switch (choice) {
        	
            case 1:
            	
			 // List files
                system("dir"); // On Windows. Use `ls` for Linux/macOS
                break;

  			case 2: 
			  {
    			 cout << "Enter the file name to view with extension: ";
   				 cin >> fileName;

    			ifstream file(fileName.c_str()); // Convert string to const char*
    			
   					 if (!file) {
        				cout << "ERROR! Could NOT Open The File: " << fileName << " ..:/" << endl;
    					
						} else {
							cout << "Displaying contents of file: " << fileName << endl;
							
       					 string line; // Read and display file contents line by line
       					 while (getline(file, line)) {
       					 	
            				cout << line << endl; // Print each line to the console
            				
        						}
       							 file.close();
   								 }
   					 break;
			}

            case 3: {
            	
                cout << "Enter the name of the directory to create: ";
                cin >> new_dir_name;

                string command = "mkdir " + new_dir_name;
                system(command.c_str()); 
                
                cout << "Directory '" << new_dir_name << "' created!" << endl;
                break;
            }

            case 4: // Copy a file (Not implemented yet)
                cout << "Feature to copy a file is not implemented yet." << endl;
                break;

            default:
                cout << "Invalid Choice! Please Try Again..." << endl;
        }
    }

    return 0;
}
