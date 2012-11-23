#include "Triangle.h"
#include "CappedDeltaTime.h"

/*
 * The Sandbox creates a Triangle object for displaying purposes and a
 * CappedDeltaTime for not being dependent on the speed of the computer
 */
class SDLSandbox
{
    public:
        SDLSandbox();
        ~SDLSandbox();
        void Init(int * argc, char ** argv);
        void Run();

    private:
        void Update();

    private:
        Triangle m_triangle;
        CappedDeltaTime m_timeCounter;
};

