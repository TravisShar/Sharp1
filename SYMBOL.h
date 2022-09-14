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

//#pragma once
#ifndef INTBINSRYTREE_H
#define INTBINARYTREE_H
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

class SymbolTable
{
private:
    struct TNode
    {
        TNode *left;
        TNode *right;
        std::string symbol;
        bool RFlag, IFlag, MFlag;
        int value;
    };

    TNode *root;

/****************************************************************************
 ** FUNCTION: add(TNode *&, TNode *&)                                      **
 ****************************************************************************
 ** DESCRIPTION: adds a symbol to an empty spot in the table               **
 ** INPUT ARGS:  TNode *&, TNode *&                                        **
 ** OUTPUT ARGS: None                                                      **
 ** IN/OUT ARGS: None                                                      ** 
 ****************************************************************************/  

    void add(TNode *&, TNode *&);

/****************************************************************************
 ** FUNCTION: remove(TNode *)                                              **
 ****************************************************************************
 ** DESCRIPTION: removes an item from the tree                             **
 ** INPUT ARGS: TNode *                                                    **
 ** OUTPUT ARGS: None                                                      **
 ** IN/OUT ARGS: None                                                      ** 
 ****************************************************************************/

    void remove(TNode *);

/****************************************************************************
 ** FUNCTION: deleteNode(int, TNode *&)                                    **
 ****************************************************************************
 ** DESCRIPTION: removes an node from the tree                             **
 ** INPUT ARGS: int, TNode *&                                              **
 ** OUTPUT ARGS: None                                                      **
 ** IN/OUT ARGS: None                                                      ** 
 ****************************************************************************/

    void deleteNode(int, TNode *&);

/****************************************************************************
 ** FUNCTION: makeDelete(TNode *&)                                         **
 ****************************************************************************
 ** DESCRIPTION: removes an item from the table near the top                **
 ** INPUT ARGS: TNode *&                                                   **
 ** OUTPUT ARGS: None                                                      **
 ** IN/OUT ARGS: None                                                      ** 
 ****************************************************************************/   

    void makeDelete(TNode *&);

/****************************************************************************
 ** FUNCTION: displayInOrder(TNode *&)                                     **
 ****************************************************************************
 ** DESCRIPTION: displays the table in order                               **
 ** INPUT ARGS: TNode *&                                                   **
 ** OUTPUT ARGS: None                                                      **
 ** IN/OUT ARGS: None                                                      ** 
 ****************************************************************************/ 

    void displayInOrder(TNode *) const;

public:
/****************************************************************************
 ** FUNCTION: SymbolTable()                                                **
 ****************************************************************************
 ** DESCRIPTION: Constructor for the Symbol Table Creates an               **
 ** instance of the BSTtree with empty root node and default values.       **
 ** INPUT ARGS: None                                                       **
 ** OUTPUT ARGS: None                                                      **
 ** IN/OUT ARGS: None                                                      ** 
 ****************************************************************************/

    SymbolTable()
    {root = nullptr;}

/****************************************************************************
 ** FUNCTION: ~SymbolTable()                                               **
 ****************************************************************************
 ** DESCRIPTION: Destructor for the SymbolTable.                           **
 ** INPUT ARGS: None                                                       **
 ** OUTPUT ARGS: None                                                      **
 ** IN/OUT ARGS: None                                                      ** 
 ****************************************************************************/

    ~SymbolTable()
    {remove(root);}

/****************************************************************************
 ** FUNCTION: insertNode(string, int, bool, bool, bool)                    **
 ****************************************************************************
 ** DESCRIPTION: Inserts a node with its values into the symbol table      **
 ** INPUT ARGS: String, int, bool, bool, bool                              **
 ** OUTPUT ARGS: None                                                      **
 ** IN/OUT ARGS: None                                                      ** 
 ****************************************************************************/

    void insertNode(string,int,bool,bool,bool);

/****************************************************************************
 ** FUNCTION: searchNode(string)                                           **
 ****************************************************************************
 ** DESCRIPTION: Searches the BST for a symbol with the right tag          **
 ** INPUT ARGS: string                                                     **
 ** OUTPUT ARGS: None                                                      **
 ** IN/OUT ARGS: None                                                      ** 
 ****************************************************************************/ 

    bool searchNode(string);

/****************************************************************************
 ** FUNCTION: findintable(string)                                          **
 ****************************************************************************
 ** DESCRIPTION: Searches the table for a value and returns true if the    **
 **              value is there                                            **
 ** INPUT ARGS: string                                                     **
 ** OUTPUT ARGS: bool                                                      **
 ** IN/OUT ARGS: None                                                      ** 
 ****************************************************************************/   

    bool findintable(string);

/****************************************************************************
 ** FUNCTION: remove(int)                                                  **
 ****************************************************************************
 ** DESCRIPTION: removes an item from the table                            **
 ** INPUT ARGS: int                                                        **
 ** OUTPUT ARGS: None                                                      **
 ** IN/OUT ARGS: None                                                      ** 
 ****************************************************************************/      

    void remove(int);

/****************************************************************************
 ** FUNCTION: displayInOrder()                                             **
 ****************************************************************************
 ** DESCRIPTION: displays the table in order                               **
 ** INPUT ARGS: NONE                                                       **
 ** OUTPUT ARGS: None                                                      **
 ** IN/OUT ARGS: None                                                      ** 
 ****************************************************************************/   

    void displayInOrder() const
    {displayInOrder(root);}

};
#endif