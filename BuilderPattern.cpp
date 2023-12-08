/* Builder pattern will be used to construct the comoplex object, which needs multi spteps to construct an object.
Example : Build a home - which involve add foundation, build wall, add window, add door, build flooring , paint etc as a basic steps.
Some home has garden, some home has swiming pool .. these are all the special requirwements from the basic steps 
To satisfy all type of request, we can use the builder pattern to statisy all the request*/

#include <iostream>

class IBuilder
{
    public :
    virtual void buildFoundation() = 0;
    virtual void buildWall() = 0;
    virtual void buildWindow(int count) = 0;
    virtual void buildDoor(int count) = 0;
    virtual void buildFlooring() = 0;

    void buildSwimmingPool() {};
    void buildGarden() {};

    virtual ~IBuilder() = default;
};
class Builder : public IBuilder
{
    public:
    void buildFoundation() override
    {
        std::cout << "buildFoundation "<< std::endl;
    }
    void buildWall() override
    {
        std::cout << "buildWall "<< std::endl;
    }
    void buildWindow(int count) override
    {
        std::cout << "buildWindow "<< std::endl;
    }
    void buildDoor(int count) override{
        std::cout << "buildDoor "<< std::endl;
    }
    void buildFlooring() override
    {
        std::cout << "buildFlooring "<< std::endl;
    }

    void buildSwimmingPool()
    {
        std::cout << "buildSwimmingPool "<< std::endl;
    }
        void buildGarden()
    {
        std::cout << "buildGarden "<< std::endl;
    }
};

class Director
{
    public:
    IBuilder *m_builder;
    Director() = default;
    Director(IBuilder *builder)
    {
        m_builder = builder;
    }

    void buildBasicHome()
    {
        m_builder->buildFoundation();
        m_builder->buildWall();
        m_builder->buildWindow(2);
        m_builder->buildDoor(3);
        m_builder->buildFlooring();
        
    }

    void buildPoolHome()
    {
        m_builder->buildSwimmingPool();
    }

    void buildGardenHome()
    {
        m_builder->buildSwimmingPool();
    }
    
};

int main()
{
    Builder *builder = new Builder();
    Director *director = new Director(builder);

    director->buildBasicHome();

    delete builder;
    delete director;

    return 0;

}