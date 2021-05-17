#include <BasicStack.h>
#include <stdexcept>

using namespace std;


/** RETURN the size of the stack
 
*/
int BasicStack::size() const{
    if(this->elements.size() < 0){
        throw invalid_argument("Negative size!!");
    }
    return this->elements.size();
}

/** Return a string like 
        Stack: elements='ab'
*/
string BasicStack::as_string() const{
    if(this->elements.size() < 0){
        throw invalid_argument("Negative size!!");
    }
    return "Stack: elements=' "+this->elements + "'";
}

/** RETURN True if the stack empty, False otherwise
 */
bool BasicStack::is_empty() const{
    return this->elements.size() == 0;
}


/** Adds item to the top of the stack
*/
void BasicStack::push(const char c){
    this->elements.push_back(c);
}

/** RETURN the top element in the stack (without removing it!)
         
        - if stack is empty, throw std::runtime_error

*/
char BasicStack::peek() const {
    if(is_empty()){
        throw runtime_error("Stack empty!!");
    }
    return this->elements.back();
}

/** Removes the top element in the stack and RETURN it.
 
        - if stack is empty, throw std::runtime_error
*/
char BasicStack::pop(){
    if(is_empty()){
        throw runtime_error("Stack empty!!");
    }
    char toPop = this->elements.back();
    this->elements.pop_back();
    return toPop;
};


string BasicStack::peekn(const int n) const{
    if(this->elements.size() < 0){
        throw invalid_argument("Negative size!!");
    }
    if(this->elements.size() >= n){
        string ret;
        int i = this->elements.size() - n;
        ret = this->elements.substr(i);
        return ret;
    }   
    throw std::invalid_argument(string("Requested to peek ") 
                        + to_string(n) 
                        + string(" elements, but  there are only ")
                        + to_string(this->size())
                        + string(" in the stack! "));
}


string BasicStack::popn(const int n){
    string ret = peekn(n);
    int i = this->elements.size() - n;;
    this->elements = this->elements.substr(0,i-1);

    return ret;
}
