/*Here’s how the Prototype Design Pattern works:

Prototype Interface: It defines a common interface or abstract class that all concrete prototype classes should implement. This interface typically includes a method for cloning the object.
Concrete Prototypes: These are the actual objects that implement the prototype interface. Each concrete prototype class provides an implementation of the cloning method, which creates a copy of the object.
Client: The client code is responsible for creating new objects by cloning existing prototypes. Instead of creating objects directly using the new keyword, the client requests a prototype to clone itself.

Why Do We Use the Prototype Desing Pattern?
Well, it’s all about saving time and resources. Instead of creating new objects from scratch, the Prototype Pattern lets us create new ones by copying an existing prototype. This is especially handy when those objects share a lot of similarities.*/
#include <iostream>

//Prototype interface
class Shape
{
    public:
    virtual Shape* clone() = 0;
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape{
    private:
    int m_size;

    public :
    Circle(int size):m_size(size) {}

    Shape* clone() override
    {
        return new Circle(*this);
    }

    void draw() override
    {
        std::cout << "circle draw called " << m_size << std::endl;
    }
};

class Square : public Shape{

    private:
    int m_size;

    public: 
    Square(int size)
    {
        m_size = size;
    }
    Square* clone() override
    {
        return new Square(*this);
    }

    void draw() override
    {
        std::cout << " Square draw called " << m_size << std::endl;
    }
};

int main()
{
    Shape *s1 = new Circle(10);
    Shape *s2 = s1->clone();
    s1->draw();
    s2->draw();

    Shape *s3 = new Square(20);
    auto s4 = s3->clone();
    s4->draw();

    delete s1;
    delete s2;
    delete s3;
    delete s4;

    return 0;
}