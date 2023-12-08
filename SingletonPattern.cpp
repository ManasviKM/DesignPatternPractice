#include <iostream>

class Singleton
{
    public:
    //reason for reference is -> we made copy constructor as default which is shallow copy
    // and constructor and destructor is made as private function which cyou cannot use outside the scope of class.
    static Singleton& getInstance()
    {
        if(!singleton)
        {
            singleton = new Singleton();
        }
        return *singleton;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    private:
    static Singleton *singleton;

    Singleton()
    {
        std::cout << " Singleton constructor called " << std::endl;
    }
    ~Singleton()
    {
        std::cout << " Singleton destructor called " << std::endl;
    }

};

Singleton* Singleton::singleton = nullptr;

int main()
{
    Singleton& single = Singleton::getInstance();
    Singleton& single2 = Singleton::getInstance();

    return 0;
}