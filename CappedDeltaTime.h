#include "Time.h"

/*
 * The goal of CappedDeltaTime is a track time passing by and keeping the
 * delta between to calls in bounds.
 *
 * If the delta is too small, it's not necessary to update anything.
 * If the delta is too high, there might be problems updating (in the Sandbox
 * context, the rotation angle of the Triangle might become way too high)
 */
class CappedDeltaTime
{
    public:
        CappedDeltaTime();

        void Update();
        void Reset();

        float GetDeltaTime() const;
        bool IsOk() const;

    private:
        const float m_deltaMin;
        const float m_deltaMax;

        Time m_time;
        float m_currentDelta;
};


