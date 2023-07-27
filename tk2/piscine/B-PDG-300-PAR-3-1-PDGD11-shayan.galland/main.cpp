#include "UniquePointer.hpp"
#include <iostream>
#include "IObject.hpp"
/*
int main(void)
{
DirectoryLister dl("./test/", true);
for (std:: string file = dl.get(); !file.empty(); file = dl.get())
std::cout << file << std::endl;
dl.open("invalid path", true);


std::cout << "\n\n";
dl.open("./test/", false);
for (std:: string file = dl.get(); !file.empty(); file = dl.get())
std::cout << file << std::endl;
return 0;
}*/
/*
void myLs(const std::string &directory)
{
    try
    {
        SafeDirectoryLister dl(directory, false);
        std::cout << directory << ":" << std::endl;
        for (std::string file = dl.get(); true; file = dl.get())
            std::cout << file << std::endl;
    }
    catch (const IDirectoryLister ::NoMoreFileException &e)
    {
        return;
    }
    throw std::runtime_error("should not happen");
}

int main(void)
{
    try
    {
        myLs("./test/");
        myLs("./ not_exist/");
        myLs("./test/");
    }
    catch (const IDirectoryLister ::OpenFailureException &e)
    {
        std::cerr << "failure: " << e.what() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "unexpected error: " << e.what() << std::endl;
    }

    return 0;
}*/
class TestObject: public IObject
{
    public:
        TestObject(const char* name) : _name(name) 
        { 
            std::cout << _name << " is alive" << std::endl;
        }
        ~TestObject()
        {
            std::cout << _name << " is dead" << std::endl;
        }
        void touch() 
        { 
            std::cout << _name << " is touched" << std::endl; 
        }
    private:
        const char* _name;
};

void touch ( IObject * object )
{
    if ( object != nullptr )
        object->touch();
}


int main(void)
{
UniquePointer ptr1;
UniquePointer ptr2(new TestObject("Eccleston"));
// UniquePointer ptr3(ptr2); <- Does not compile!
ptr1 = new TestObject("Tennant");
ptr2 = new TestObject("Smith");
ptr1 ->touch();
(*ptr2).touch();
{
UniquePointer ptr4(new TestObject("Whittaker"));
}
ptr1.reset(new TestObject("Capaldi"));
ptr1.swap(ptr2);
//ptr1 = ptr2; <- Does not compile!
ptr2.reset ();
return 0;
}