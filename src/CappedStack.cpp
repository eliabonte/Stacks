#include <CappedStack.h>
#include <stdexcept>

using namespace std;

CappedStack::CappedStack(const int cap){
    if(cap<0){
        throw invalid_argument("Cap is negative!!");
    }
    this->cap = cap;
    this->elements = string();
}
 
 string CappedStack::as_string() const{
    return "CappedStack: cap=" + to_string(this->cap) + "  elements="+this->elements;
 }

/** Adds item to the top of the stack, if current size is within cap.
         
        - If stack size is already at cap value, new item is silently discarded
    
*/
void CappedStack::push(const char c){
    
}


/** RETURN the cap of the stack
 */
virtual int get_cap() const;

/**
MODIFIES the cap setting its value to the provided cap.
    
        If the cap is less then the stack size, all the elements above
        the cap are removed from the stack.
        
        If cap < 1, throws an std::invalid_argument exception
        Does *not* return anything!
    
        For example, with the following stack, and cap at position 7:
        
        cap ->  7
                6
                5  e
                4  d
                3  c
                2  b
                1  a
                
        
        calling method set_cap(3) will change the stack to this:
        
        cap ->  3  c
                2  b
                1  a                               
        
*/
virtual void set_cap(const int cap);
