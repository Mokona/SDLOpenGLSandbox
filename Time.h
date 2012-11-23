/*
 * Time is here to track time in an unbound context.
 * It's used by CappedDeltaTime for getting the system delta time between
 * two calls to Update()
 */
class Time
{
    public:
        Time();
        void Update();

        float GetDeltaTime() const;

    private:
        int m_lastUpdateElpasedTime;
        int m_delta;
};

