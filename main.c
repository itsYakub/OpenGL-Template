#include "SDL2/SDL.h"
#include "glad/glad.h"

int main(int argc, const char* argv[]) {
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		return 1;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	SDL_Window* window = SDL_CreateWindow(
		"Hello, OpenGL!",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		800,
		600,
		SDL_WINDOW_OPENGL
	);

	SDL_GLContext context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, context);
	SDL_GL_SetSwapInterval(1);

	gladLoadGL();

	int exit = 0;
	while(!exit) {
		SDL_Event event = { 0 };
		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT: {
					exit = 1;
				} break;
			}
		}

		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
