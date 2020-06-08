#include <iostream>
#include <cstring>

#include "command.hpp"
#include "Utilities.hpp"
#include "User.hpp"
#include "Travels.hpp"
#include "Date.hpp"

using std::cout;
using std::cin;
using std::endl;

void Commands::reg() {
  char* nname = extractCommand();
  char* npass = extractCommand();
  char* nemail = extractCommand();
  if(validateName(nname)) {
    if(validateEmail(nemail)) {
      if(userdb.isEmailAvailable(nemail)) {
        User temp(nname, npass, nemail);
        userdb.push(temp.copy());
        cout << "User successfully registered!\n";
        userdb.save();

      }
      else {
        cout << "Email already taken!\n";
      }
    }
    else {
      cout << "Please enter a valid email!\n";
    }
  }
  else {
    cout << "Please enter a valid name!\n";
  }
  delete[] nname;
  delete[] npass;
  delete[] nemail;
}
void Commands::show() {
  cout << userdb;
}
void Commands::login() {
  char* temail = extractCommand();
  char* tpass = extractCommand();
  for(unsigned i=0, sze = userdb.size(); i<sze; ++i) {
    if(!strcmp(temail, userdb[i]->getEmail())) {
      if(!strcmp(tpass, userdb[i]->getPass())) {
        cout << "Welcome, " << userdb[i]->getName() << "!\n";
        delete[] temail;
        delete[] tpass;
        while(true) {
          cout << "\n> ";
          cin.getline(buffer, bufferSize);
          char* lcommand = extractCommand();
          if(!strcmp(lcommand, "logout")) {
            cout << "Logging out of user " << userdb[i]->getName() << "!\n";
            delete[] temail;
            delete[] tpass;
            return;
          }
          else if(!strcmp(lcommand, "add_travel")) {
            Travels temp;
            cout << "\nDestination: \n> ";
            cin.getline(buffer, bufferSize);
            char* ndest = extractCommand();

            temp.setDestination(ndest);
            delete[] ndest;


            cout << "\nFrom date: \n> ";
            cin.getline(buffer, bufferSize);
            char* ncfdate = extractCommand();
            Date ndfdate;
            ndfdate.charToDate(ncfdate);
            while(!ndfdate.validate()) {
              cout << "\nDate is not valid, please try again. (Use format ISO 8601) \n> ";
              cin.getline(buffer, bufferSize);
              ncfdate = extractCommand();
              ndfdate.charToDate(ncfdate);
            }
            cout << "\nTill date: \n> ";
            cin.getline(buffer, bufferSize);
            char* nctdate = extractCommand();
            Date ndtdate;
            ndtdate.charToDate(nctdate);
            while( (!ndtdate.validate()) || (!(ndtdate > ndfdate)) ) {
              cout << "\nDate is not valid, please try again. \n> ";
              cin.getline(buffer, bufferSize);
              nctdate = extractCommand();
              ndtdate.charToDate(nctdate);
            }
            temp.setTimePeriod(ndfdate, ndtdate);
            delete[] ncfdate;
            delete[] nctdate;

            cout << "\nGrade: \n> ";
            cin.getline(buffer, bufferSize);
            char* ncgrade = extractCommand();
            int nigrade = strToInt(ncgrade);
            while(nigrade > 5 || nigrade < 1) {
              cout << "\nInvalid grade - it can only be 1-5, try again. \n> ";
              cin.getline(buffer, bufferSize);
              char* ncgrade = extractCommand();
              nigrade = strToInt(ncgrade);
            }
            temp.setGrade(nigrade);
            delete[] ncgrade;

            cout << "\nComment: \n> ";
            cin.getline(buffer, bufferSize);
            char* ncomment = new char[strlen(buffer) + 1];
            strcpy(ncomment, buffer);

              temp.setComment(ncomment);
              delete[] ncomment;

            cout << "\nPhotos: \n> ";
            cin.getline(buffer, bufferSize);
            char* nphotos = new char[strlen(buffer) + 1];
            strcpy(nphotos, buffer);

              temp.setPhotos(nphotos);
              delete[] nphotos;

            userdb[i]->addTravel(temp.copy());
            cout << "\nSuccessfully added new travel!\n";

          }
          else if(!strcmp(lcommand, "show_travels")) {
            userdb[i]->printUserTravels();
          }
          else {
            cout << "Unknown command!\n";
          }
        }
      }
      else {
        cout << "Incorrect password!\n";
        delete[] temail;
        delete[] tpass;
        return;
      }
    }
  }
  cout << "Cannot find user!\n";
  delete[] temail;
  delete[] tpass;
}
void Commands::load() {
  userdb.load();
}

char* Commands::extractCommand() {
  unsigned i=0;
  if(buffer[i] == '\0') {
    return nullptr;
  }
  while(!isEscapeSeq(buffer[i])) {
    ++i;
  }
  char* command;
  command = new char[i+1];
  for(unsigned j=0; j<=i; ++j) {
    command[j] = buffer[j];
  }
  command[i] = '\0';
  buffer += i;
  if(buffer[1] != '\0') {
    ++buffer;
  }
  return command;
}
bool Commands::callCommand(const char* command) {
  if(!strcmp(command, "exit")) {
    cout << "Program ended!\n";
    return false;
  }
  else if(!strcmp(command, "show")) {
    show();
    return true;
  }
  else if(!strcmp(command, "reg")) {
    reg();
    return true;
  }
  else if(!strcmp(command, "login")) {
    login();
    return true;
  }
  else if(!strcmp(command, "load")) {
    load();
    return true;
  }
  else {
    cout << "Unknown command!" << endl;
    return true;
  }
}


Commands::Commands() {
  buffer = nullptr;
}
Commands::Commands(Commands const &temp) {
  delete[] buffer;
  buffer = new char[strlen(temp.buffer)+1];
  strcpy(buffer, temp.buffer);
}
Commands::~Commands() {
  delete[] buffer;
}

void Commands::run() {
  char* command = nullptr;
  do {
    cout << "\n> ";
    buffer = new char[bufferSize];
    cin.getline(buffer, bufferSize);
    if(strcmp(buffer, "")) {
      buffer[strlen(buffer)]= '\0';
      command = extractCommand();
    }
  } while(callCommand(command));
}
