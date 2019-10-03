#include <iostream>
#include <fstream> //for File I/O
#include <string>

using namespace std;

int main()
{
  string fileName; //to get the name of the file to open
  string line; //to store a single line of a text file
  fstream fileStream; //to open a file for reading
  int numberOflines=0;
  int numberOfcharacters=0;
  char answer=' ';
  cout<<"What file do you want to open? ";
  getline(cin, fileName);
  
  //STEP 1: open the fileStream for input, using the fileName specified
  fileStream.open(fileName.c_str(), ios::in);
  if( /*STEP 2: check to see if the fileStream successfully opened*/fileStream.is_open())
  {
    cout<<fileName<<" opened.\nFILE CONTENTS:\n";
    
    //STEP 3: repeat the following until the end-of-file (eof) has been reached...
    
    while(!fileStream.eof())
    {
        getline(fileStream, line);
        if(!line.empty())
        {
        cout << line << endl;
        numberOflines+=1; 
        numberOfcharacters= line.length()+numberOfcharacters;
        }
    }
    // 3A: read a line from fileStream into the variable line
    // 3B: display the line, followed by an endline
  
    //STEP 4: close the fileStream
  }
  else
  {
    cout<<fileName<<" could not be opened.\n";
  }

   cout << "METADATA\n" << "File: " << fileName << "\n" <<"Lines: " << numberOflines << "\n" << "Characters: " << numberOfcharacters << "\n";

   cout << "Analyze another file(y/n)?";
   cin  >> answer;
   
  while(answer == 'y' || answer == 'Y')
  {
  cout<< " What file do you want to open? ";
  cin >> fileName;

  fileStream.open(fileName.c_str(), ios::in);
  if( /*STEP 2: check to see if the fileStream successfully opened*/fileStream.is_open())
  {
   // cout<<fileName<<" opened.\nFILE CONTENTS:\n";
    cout<<"FILE CONTENTS:\n";
    //STEP 3: repeat the following until the end-of-file (eof) has been reached...

    while(!fileStream.eof())
    {
        getline(fileStream, line);
        if(!line.empty())
        {
        cout << line << endl;
        numberOflines+=1;
        numberOfcharacters= line.length()+numberOfcharacters;
        }
    }
    // 3A: read a line from fileStream into the variable line
    // 3B: display the line, followed by an endline

    //STEP 4: close the fileStream
  }  
  else
  {
    cout<<fileName<<" could not be opened.\n";
  }

   cout << "METADATA\n" << "File: " << fileName << "\n" <<"Lines: " << numberOflines << "\n" << "Characters: " << numberOfcharacters << "\n";

   cout << "Analyze another file(y/n)? ";
   cin  >> answer;

   }

   fileStream.close();

  return 0;
}

