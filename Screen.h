#include <GLFW/glfw3.h>

class Screen {
	public:
		static Screen* Instance();
		bool Initialize();
		void ClearScreen();
		void Render();
		void Shutdown();
		GLFWwindow* window;	
		static void ErrorCallback(int, const char* err_str);

	private:
		Screen();
		Screen(const Screen&);
		Screen& operator=(Screen&);
};
