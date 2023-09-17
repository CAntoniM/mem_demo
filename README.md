# Pointers example

this is a sample example of a vector (dynamic array) and a linked list to show
how you can use pointers to show how you can use heap memeory in your application.

## Stack vs heap

when you are running your code their are two diffrent types of memeory stack and
heap memory. The difference between these are that stack memeory is a constant
size that is known at run time. This has issues when you want to work with data
that we dont know the size of ahead of time. This can be something as simple as
a todo list where the list of elements can go on forever or as complex as the
number entitties in a game level at a time.

### Stack 

This is memory created for you by the compiler when ever a function is called.
it is a fixed size list of elements containing each of the paramenters and 
variables used in your code. YES ALL VARIABLES ARE STACK MEMEORY. So the address
of the current stack is known at all times (this is generally kept in a register)
and we access varibles in a code by going to variables that are at X elements 
down from the top of the stack. sort of fixed known addresses this is the 
quickest way to access a variable in memeory as it only takes 3.

* create a copy of the address of the top of the stack.
* add the offset.
* read the value.

### Heap memory

This memory is created by the call the malloc function. This is intern used by 
all data structures who's size is not known at build time. To use heap memory we
use a pointer (a memeory address) stored on the stack. This means using heap 
memory is more expensive than using stack memory as we first need to read from 
the stack by an additonal read memory located at the address stored in the 
stack. This means that the heap reading is 4 instructions rather than 3. for
this slow time we get the ability to allocate as much or as little memory as we 
want (given the computer has memeory to spare).
