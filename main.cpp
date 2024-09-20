#include "SFML/OpenGL.hpp"
#include "SFML/Window.hpp"

int main(int argc, const char* argv[]) {
	sf::Window window(sf::VideoMode(800, 600), "Hello, OpenGL!", sf::Style::Default);

	window.setVerticalSyncEnabled(true);
	window.setActive(true);

	bool close_window = false;
	while(!close_window) {
		sf::Event event;
		while(window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed: {
					close_window = true;
				}
			}
		}

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		window.display();
	}

	return 0;
}
