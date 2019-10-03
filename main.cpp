#include <iostream>
#include <fstream> //for File I/O
#include <string>

using namespace std;

int main()
{
  string fileName; //to get the name of the file to open
  string line; //to store a single line of a text file
  fstream fileStream; //to open a file for reading
  fstream filestream;
  int numberOflines=0;
  int numberOfcharacters=0;
  char answer=' ';
  int lines=0;
  int characters=0;

  cout<<"What file do you want to open? ";
  getline(cin, fileName);
  
  fileStream.open(fileName.c_str(), ios::in);
  if(fileStream.is_open())
  {
    cout<<fileName<<" opened.\nFILE CONTENTS:\n";
    
    
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
  
  }
  else
  {
    cout<<fileName<<" could not be opened.\n";
  }

   cout << "METADATA\n" << "File: " << fileName << "\n" <<"Lines: " << numberOflines << "\n" << "Characters: " << numberOfcharacters << "\n";

   cout << "Analyze another file (y/n)? ";
   cin  >> answer;  

  while(answer != 'n' || answer != 'N')
  {
    cout << "What file do you want to open? ";
    cin >> fileName;

  filestream.open(fileName.c_str(), ios::in);
    if( filestream.is_open())
     {
         cout<<fileName<<" opened.\nFILE CONTENTS:\n";


          while(!filestream.eof())
          {
             getline(filestream, line);
             if(!line.empty())
             {
                 cout << line << endl;
                 lines+=1;
                 characters= line.length()+characters;
              }
            }
       } else
         {
             cout<<fileName<<" could not be opened.\n";
         }
         
   cout << "METADATA\n" << "File: " << fileName << "\n" <<"Lines: " << lines << "\n" << "Characters: " << characters << "\n";

   cout << "Analyze another file (y/n)?\n";
   cin  >> answer;
   if(answer != 'y' || answer != 'Y')
   {
        return 0;
   }

  }
   fileStream.close();
   filestream.close();

  return 0;
}

