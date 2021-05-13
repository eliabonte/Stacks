#include <Stack.h>
#include <string>

using namespace std;

class BasickStack: public Stack{
    private:
        string elements;
    
    public:
 
       /** RETURN the size of the stack
 
       */
       virtual int size() const;
 
       /** Return a string like 
          
               Stack: cap=4 elements='ab'
       */
       virtual string as_string() const;
 
       /** RETURN True if the stack empty, False otherwise
       */
       virtual bool is_empty() const;
 
 
       /** Adds item to the top of the stack
       */
       virtual void push(const char c);
 
       /** RETURN the top element in the stack (without removing it!)
              
               - if stack is empty, throw std::runtime_error
 
       */
       virtual char peek() const;
 
       /** Removes the top element in the stack and RETURN it.
 
               - if stack is empty, throw std::runtime_error
       */
       virtual char pop();
 
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
       virtual string peekn(const int n) const;
 
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
       virtual string popn(const int n);
 
};