/*
    Bridge Pattern is basically a structural design pattern in software engineering or in C++ programming that is used to separate an object’s abstraction from its implementation
    Use Cases of the Bridge Pattern in C++ Design Patterns
    Remote Controls: Consider a remote control application that needs to support multiple devices (e.g., TVs, DVD players, stereos) and various remote control protocols (e.g., infrared, Bluetooth).
    Platform-Independent Graphics Libraries: The Bridge pattern is often used in graphics libraries to provide platform-independent abstractions for drawing shapes, lines, and text while allowing different implementations for various operating systems (e.g., Windows, Linux, macOS).
    Database Abstraction: When we are working with databases, the Bridge pattern can help separate the database-specific code from the application’s business logic. This allows us to switch between different database management systems (e.g., MySQL, PostgreSQL, SQLite) without affecting the core application.
    GUI Frameworks: GUI frameworks often use the Bridge pattern to separate the GUI components (e.g., buttons, text fields) from the underlying platform-specific implementation (e.g., Windows API, GTK, Qt).
    File System Abstraction: When developing file management software, we can use the Bridge pattern to abstract the file system operations, separating them from the underlying file system implementations (e.g., NTFS, ext4, HFS+).
    Printer Driver Software: Printer driver software can benefit from the Bridge pattern to separate the printer’s generic features (e.g., page formatting, print job management).

    Let's taken an example of Draw and rendering the shapes
*/

#include <iostream>

class shape{
    public:
    virtual void draw() = 0;
    virtual ~shape() = default;
};

class rendering 
{
    public:
    virtual void render() = 0 ;
    virtual ~rendering() = default;
};

class Circle : public shape{

   rendering *m_render;
    
    public:
    Circle(rendering *render) : m_render{render}{ }

    void draw() override
    {
        if(m_render)
        {
            m_render->render();
        }
    }
};

class square : public shape{
    rendering *m_render;
    
    public:
    square(rendering *render) : m_render{render}{ }
    void draw() override
    {
        if(m_render)
        {
            m_render->render();
        }
    }
};

class vectorRendering : public rendering
{
    public:
    void render() override
    {
        std::cout << "vector rendering called " << std::endl;
    }
};

class rasterRendering : public rendering
{
    public:
    void render() override
    {
        std::cout << "raster rendering called " << std::endl;
    }
};

int main()
{

/* why do we need to pass rendering object from here ?
Ans : circle/square shape can render with vecotrendering/rasterrendering . This gives the flexiblity to select rendering type while calling.
*/

    rendering *render  = new vectorRendering();
    Circle circle(render);
    circle.draw();

    rendering *r_render  = new rasterRendering();
    square square(r_render);
    square.draw();

    delete render;
    delete r_render;
}

/*we can also take an example of DB functionality with main logic*/