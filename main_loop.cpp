#include <SFML/Window.hpp>
#include <GL/glew.h>

void main_loop(sf::Window& window, GLuint shaderProgram, GLuint vao, GLuint vbo)
{
    bool running = true;

    while (running)
    {
        sf::Event windowEvent;
        while (window.pollEvent(windowEvent))
        {
            switch (windowEvent.type)
            {
            case sf::Event::Closed:
                running = false;
                break;

            case sf::Event::KeyPressed:
                if (windowEvent.key.code == sf::Keyboard::Escape)
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