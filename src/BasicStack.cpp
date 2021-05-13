#include <BasicStack.h>
#include <stdexcept>

using namespace std;


/** RETURN the size of the stack
 
*/
int BasickStack::size() const{
    if(this->elements.size() < 0){
        throw invalid_argument("Negative size!!");
    }
    return this->elements.size();
}

/** Return a string like 
        Stack: elements='ab'
*/
string BasickStack::as_string() const{
    if(this->elements.size() < 0){
        throw invalid_argument("Negative size!!");
    }
    return "Stack: elements=' "+this->elements + "'";
}

/** RETURN True if the stack empty, False otherwise
 */
bool BasickStack::is_empty() const{
    return this->elements.size() == 0;
}


/** Adds item to the top of the stack
*/
void BasickStack::push(const char c){
    for(int i=this->elements.size()+1;i>0;i--){
        this->elements[i]=this->elements[i-1];
    }
    this->elements[0]=c;
}

/** RETURN the top element in the stack (without removing it!)
         
        - if stack is empty, throw std::runtime_error

*/
char BasickStack::peek() const {
    if(is_empty()){
        throw runtime_error("Stack empty!!");
    }
    return this->elements[0];
}

/** Removes the top element in the stack and RETURN it.
 
        - if stack is empty, throw std::runtime_error
*/
char BasickStack::pop(){
    if(is_empty()){
        throw runtime_error("Stack empty!!");
    }
    char toPop = this->elements[0];
    int i;
    for(i=0;i<this->elements.size()-1;i++){
        this->elements[i] = this->elements[i+1];
    }
    this->elements[i] = NULL;
    return toPop;
};

/**
     RETURN a string with the n top elements, in the order in which they
    were pushed. For example, if the stack is the following:
    
        e
        d
        c
        b
        a
        
    peekn(3) will return the string 'cde'

    - If there aren't enough element to peek, throw std::invalid_argument
    - If n is negative, throw std::invalid_argument
*/
virtual string peekn(const int n) const = 0;

/**
     Pops the top n elements, and RETURN them as a string, in the order in
    which they where pushed. For example, with the following stack:
    
        e
        d
        c
        b
        a
    
    popn(3)
    
    will give back 'cde', and stack will become:
    
        b
        a
    
    - If there aren't enough element to pop, throw std::invalid_argument
    - If n is negative, throw std::invalid_argument
*/
virtual string popn(const int n) = 0;
