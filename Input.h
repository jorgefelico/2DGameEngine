#include <GLFW/glfw3.h>

class Input {
	public:
		static Input* Instance();
		void Update();
		
		bool IsXClicked();
		bool IsKeyPressed();
		
		int GetKey();
		
		bool IsLeftButtonClicked();
		bool IsRightButtonClicked();

		double GetMousePositionX();
		double GetMousePositionY();

		int GetMouseMotionX();
		int GetMouseMotionY();

	private:
		Input();
		Input(const Input&);
		Input& operator=(Input&);

		int m_key;

		bool m_isXClicked;
		bool m_isKeyPressed;

		bool m_isLeftButtonClicked;
		bool m_isRightButtonClicked;

		double m_mousePositionX;
		double m_mousePositionY;

		int m_mouseMotionX;
		int m_mouseMotionY;

		static void KeyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void MousePositionCallback(GLFWwindow* window, double xpos, double ypos);
		static void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

};
