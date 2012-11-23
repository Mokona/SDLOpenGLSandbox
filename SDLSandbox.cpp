#include "SDLSandbox.h"
#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>

namespace
{
    // The geometry of the display surface is specified with
    // the next three constants
    const uint32_t SCREEN_WIDTH = 320;
    const uint32_t SCREEN_HEIGHT = 320;
    const uint32_t SCREEN_DEPTH = 32;
}

SDLSandbox::SDLSandbox()
{
}

SDLSandbox::~SDLSandbox()
{
}

void SDLSandbox::Init(int * argc, char ** argv)
{
    // This is the standard way to initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "Error video\n";
        return;
    }
    atexit(SDL_Quit);

    // This is a classical way to start OpenGL in a SDL context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_Surface * screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_DEPTH, SDL_OPENGL);

    if (!screen)
    {
        std::cerr << "Error creating screen\n";
        return;
    }

    glEnable(GL_DEPTH_TEST);
}

void SDLSandbox::Run()
{
    // The infinite loop only processes the SDL_QUIT event
    // and continuously call the Update() method.
    while (true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    return;
            }
        }

        Update();
    }
}

void SDLSandbox::Update()
{
    // m_timeCounter is only "ok" when enough time was spend for the update to
    // be relevant.
    m_timeCounter.Update();

    if (m_timeCounter.IsOk())
    {
        // The update + display process, to show that initialization was ok and
        // something can be displayed.
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_triangle.Update(m_timeCounter.GetDeltaTime());
        m_triangle.Render();

        SDL_GL_SwapBuffers();

        m_timeCounter.Reset();
    }
}

