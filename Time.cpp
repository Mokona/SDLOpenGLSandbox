#include "Time.h"
#include <SDL/SDL.h>

Time::Time()
{
}

void Time::Update()
{
    int timeSinceInit = SDL_GetTicks();
    m_delta = timeSinceInit - m_lastUpdateElpasedTime;
    m_lastUpdateElpasedTime = timeSinceInit;
}

float Time::GetDeltaTime() const
{
    return m_delta / 1000.f;
}

