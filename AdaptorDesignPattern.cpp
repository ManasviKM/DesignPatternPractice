/*
adapter Pattern is a structural design pattern used to make two incompatible interfaces work together. It acts as a bridge between two incompatible interfaces, allowing them to collaborate without modifying their source code. This pattern is particularly useful when integrating legacy code or third-party libraries into your application.

Key components of the Adapter pattern in C++ Design Patterns
Target Interface: This is the interface that your client code expects. It defines the operations or methods that the client code should use.
Adaptee: This is the existing class or component with an interface that’s incompatible with the target interface. The Adaptee is the class you want to adapt to make it compatible with the client’s expectations.
Adapter: The Adapter class is responsible for adapting the Adaptee’s interface to the Target interface. It acts as a wrapper around the Adaptee, forwarding calls to the Adaptee’s methods but in a way that is compatible with the client’s expectations.

Uses of the Adapter Method in C++ Design Patterns:
Legacy Code Integration: When you need to integrate new code with existing legacy code that has an incompatible interface.
Library Compatibility: When you want to use a third-party library with a different interface in your project.
Interface Standardization: To ensure that multiple classes with different interfaces conform to a common interface, making it easier to work with them.
Testing: In unit testing, you can create adapter classes to mock or stub external dependencies with different interfaces, making testing easier.

Advantages of the Adapter Pattern in C++ Design Patterns
Compatibility: Allows integration of new and old systems or components with different interfaces.
Reusability: Existing classes can be reused without modification, reducing the risk of introducing bugs.
Flexibility: New adapters can be easily added to adapt various classes to a common interface.
Maintainability: Isolates changes to the adapter, making it easier to maintain and update systems.

Disadvantages of the Adapter Pattern in C++ Design Patterns
Complexity: Introducing adapters can add complexity to the codebase, especially when multiple adapters are used.
Performance Overhead: Adapters may introduce some performance overhead due to the additional method calls and indirection.
Potential for Design Confusion: Overuse of the Adapter Pattern can make the codebase less intuitive and harder to understand.
Not Always Suitable: Some classes may be too different to adapt easily, making the Adapter Pattern impractical in certain situations.
*/

#include <iostream>
#include <string>

class legacyPrinter
{
    public :
    void printUppercaseCommands(std::string str)
    {
        std::cout << "Print upper commands " << str << std::endl;
    }
};

class Adaptor{
    legacyPrinter l_printer;
    public:
    void printCommands(std::string str)
    {
        auto newstr = str;
        std::string upperstr = "";
        for(char& c: newstr)
        {
            upperstr += std::toupper(c);
        }
        l_printer.printUppercaseCommands(upperstr);
    }
};

class modernComputer
{
    Adaptor adoptor;

    public:
    void printLowerCommands(std::string str)
    {
        adoptor.printCommands(str);
    }
};



int main()
{
    modernComputer m_computer;
    m_computer.printLowerCommands("manasvi");

    return 0;
}