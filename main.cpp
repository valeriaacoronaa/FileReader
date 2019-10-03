#include <iostream>
#include <fstream> //for File I/O
#include <string>

using namespace std;

int main()
{
        string fileName; //to get the name of the file to open
        string line; //to store a single line of a text file
        fstream fileStream; //to open a file for reading
        int lines=0;
        int characters=0;
        char answer= ' ';

        cout<<"What file do you want to open? ";
        getline(cin, fileName);

        //STEP 1: open the fileStream for input, using the fileName specified
        fileStream.open(fileName.c_str(), ios::in);
        if( /*STEP 2: check to see if the fileStream successfully opened*/fileStream.is_open())
        {
                cout<<fileName<<" opened.\nFILE CONTENTS:\n";

                //STEP 3: repeat the following until the end-of-file (eof) has been reached...
                // 3A: read a line from fileStream into the variable line
                // 3B: display the line, followed by an endline
                while(!fileStream.eof())
                {
                        getline(fileStream, line);
                        if(!line.empty())
                        {
                                cout << line << endl;
                                lines+=1; 
                                characters= line.length()+characters;
                        }
                }   

                //STEP 4: close the fileStream

        }
        else
        {
                cout<<fileName<<" could not be opened.\n";
        }
        cout << "METADATA\n" << "File: " << fileName << "\n" <<"Lines: " << lines << "\n" << "Characters: " << characters << "\n";
        cout << "Analyze another file (y/n)? ";
        cin  >> answer;
        while(answer!='n' ||answer!='N')
        {
                string fileName;
                string line;
                fstream fileStream;
                int lines=0;
                int characters=0;
                char answer=' ';

                cout<<"What file do you want to open? ";
                cin>> fileName;
                //STEP 1: open the fileStream for input, using the fileName specified
                fileStream.open(fileName.c_str(), ios::in);
                if( /*STEP 2: check to see if the fileStream successfully opened*/fileStream.is_open())
                {
                        cout<<fileName<<" opened.\nFILE CONTENTS:\n";

                        //STEP 3: repeat the following until the end-of-file (eof) has been reached...
                        // 3A: read a line from fileStream into the variable line
                        // 3B: display the line, followed by an endline
                        while(!fileStream.eof())
                        {
                                getline(fileStream, line);
                                if(!line.empty())
                                {
                                        cout << line << endl;
                                        lines+=1;
                                        characters= line.length()+characters;
                                }
                        }

                        //STEP 4: close the fileStream

                }
                else
                {
                        cout<<fileName<<" could not be opened.\n";
                }
                cout << "METADATA\n" << "File: " << fileName << "\n" <<"Lines: " << lines << "\n" << "Characters: " << characters << "\n";
                cout << "Analyze another file (y/n)? ";
                cin  >> answer;
        if(answer=='n'||answer=='N')
        {
                return 0;
        }
        }
        fileStream.close();
        return 0;
}
