#include "constants.hpp"
#include <SFML/Window.hpp>
#include <GL/glew.h>

void get_polygon_verts(GLfloat* vertices, int vert_num, float radius)
{
    float angle_step = 2.0f * 3.14159f / vert_num;  // The angle between every next vert

    for (int i = 0; i < vert_num; i++)
    {
        float angle = i * angle_step;   // Angle of the current vert

        // Vertice coordinates
        vertices[i * DATA_PER_VERT] = radius * cos(angle);  // X
        vertices[i * DATA_PER_VERT + 1] = radius * sin(angle);  // Y

        // Colors
        vertices[i * DATA_PER_VERT + 3] = (float)rand() / RAND_MAX; // R
        vertices[i * DATA_PER_VERT + 4] = (float)rand() / RAND_MAX; // G
        vertices[i * DATA_PER_VERT + 5] = (float)rand() / RAND_MAX; // B
    }
}

void main_loop(sf::Window& window, GLuint shader_program, GLuint vao, GLuint vbo)
{
    bool running = true;

    while (running)
    {
        sf::Event window_event;
        while (window.pollEvent(window_event))
        {
            switch (window_event.type)
            {
            case sf::Event::Closed:
                running = false;
                break;

            case sf::Event::KeyPressed:
                if (window_event.key.code == sf::Keyboard::Escape)
                {
                    running = false;
                }
                break;
            }
        }

        // Clear the screen to black
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw your shape here
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap the front and back buffers
        window.display();
    }
}