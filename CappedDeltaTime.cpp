#include "CappedDeltaTime.h"
#include <iostream>

CappedDeltaTime::CappedDeltaTime() :
    m_deltaMin(0.01f),
    m_deltaMax(0.5f),
    m_currentDelta(0.f)
{
}

void CappedDeltaTime::Update()
{
    m_time.Update();

    float delta = m_time.GetDeltaTime();
    m_currentDelta += delta;

    m_currentDelta = std::min(m_currentDelta, m_deltaMax);
}

float CappedDeltaTime::GetDeltaTime() const
{
    return m_currentDelta;
}

bool CappedDeltaTime::IsOk() const
{
    return m_currentDelta > m_deltaMin;
}

void CappedDeltaTime::Reset()
{
    m_currentDelta = 0.f;
}

