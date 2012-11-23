/*
 * Triangle is the displayable object that's here to prove initialization
 * of OpenGL was correctly done and something can be displayed and updated.
 *
 * Update() rotates the triangle.
 * Render() renders it on the surface.
 */
class Triangle
{
    public:
        Triangle();
        void Update(float deltaTime);
        void Render();

    private:
        float m_angle;
        const float m_speed;
};


