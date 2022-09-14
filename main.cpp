/****************************************************************************
 ** NAME: Travis Sharp                                                     **
 ** CLASS: CSC354                                                          **
 ** ASSIGNMENT: 1                                                          **
 ** DUE DATE: 9/14/22                                                      **
 ** INSTRUCTOR: GAMRADT                                                    **
 **************************************************************************** 
 ** DESCRIPTION:  This is a symbol table that is implemented using a binary**
 **               search tree                                              **
 ****************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cctype>
#include "SymbolTable.h"

using namespace std;


bool CheckSymbol(string symbol);
bool CheckRFlag(string rflag);
bool CheckVal(string value);
int main()
{ 
    bool rflag_table;  
    SymbolTable table;
    fstream inTable;
    string searchfile;
    inTable.open("SYMBOL.DAT", std::ios::in);
    if(!inTable)
    {
        cout << "Error opening SYMBOL.Dat\n";
        exit(103);
    }
      std::string line , line2;
      string sym, rflag, value, sym2;

    do{
        std::getline(inTable,line);
     
        istringstream symbol_dat(line);
        
      
        symbol_dat >> sym >> rflag >> value;
        sym.resize(sym.length()-1);
  
        if(CheckSymbol(sym) == false)
        {
            if(CheckRFlag(rflag) == false)
            {
                if (CheckVal(value) == false)
                {
                        if (rflag == "1" || rflag == "true")
                        {
                            rflag_table = true;
                        }else if (rflag == "0" || rflag == "false")
                        {
                            rflag_table = false;
                        }
                    
                    int values = stoi(value);
                    if(sym.length() > 6)
                        sym.resize(6); 
                    if (!table.findintable(sym))
                        table.insertNode(sym, values, rflag_table, true ,false);  
                }   
            } 
        }

    }while(!inTable.eof());
    inTable.close();
    cout << setw(10) << left << "Symbol" << setw(10) << "Value" << setw(10) << "RFlag" << setw(8) << "IFlag" << setw(10) << "MFlage" << endl;
    table.displayInOrder();
    
    fstream inSearch;
    cout << "Enter a searchfile to be search" << endl;
    cin >> searchfile;
    inSearch.open(searchfile, std::ios::in);
    if(!inSearch)
    {
        cout << "Error opening file\n";
        exit(103);
    }
    do{
        std::getline(inSearch,line2);
     
        istringstream search_file(line2);
      
        search_file >> sym2;
        
        if(CheckSymbol(sym2) == false)
        {
            if(sym2.length() > 6)
            {
                sym2.resize(6);
            }
            else if(table.searchNode(sym2) == false)
            {
                cout << "This symbol doesn't exists: " << sym2 << endl;
            }
        }    
       

    }while(!inSearch.eof());
    inSearch.close();

    return 0;
}



bool CheckSymbol(string symbol)
{
    bool fault = false;
    if(symbol.size() > 12)
    {
        fault = true;
        cout << "Error. This symbol is too big : " << symbol << endl;
    }
    else if(isalpha(symbol[0]) == false)
    {
        fault = true;
        cout << "Error. The symbol needs to start with a letter : " << symbol << endl;
    }else
    {
        for(int i = 1; i < symbol.length(); i++)
            if(!isalpha(symbol[i]) && fault == false)
                if(!isdigit(symbol[i]))
                {
                    fault = true;
                    cout << "Incorrect character. The symbol must consist of characters (A..Z, a..z) and digits (0..9) only : " << symbol << endl; 
                }
    }
    return fault;

}

bool CheckRFlag(string rflag)
{
    bool fault = false;
    if(rflag == "1" || rflag == "0" || rflag == "true" || rflag == "false")
    {
        return fault;
    }
        cout << "Invalid rflag : " << rflag << endl;
        fault = true;
        return fault;

}

bool CheckVal(string value)
{
    bool fault = false;
    size_t found = value.find(".");
    if(found != std::string::npos)
    {
        fault = true;
        cout << "Invalid value :" << value << endl;
    }
        return fault;
}
