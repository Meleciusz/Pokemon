//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <windows.h>
//
//using namespace std;
//using namespace sf;
//
//class Menu {
//	int layer;
//public:
//	Menu() {
//		layer = 0;
//	}
//	void show_Menu() {
//		RenderWindow window(VideoMode(1920, 1080, 32), "Dopiero sie ucze, ok?");//, Style::Fullscreen);
//		Vector2i mousePositionwindow = Mouse::getPosition(window);
//
//		sf::Texture texture;
//		if (!texture.loadFromFile("Interfejspocz¹tkowyGierka.png")) {
//		if (!texture.loadFromFile("texture.jpg")) {
//			cout << "Nope" << endl;
//		}
//		texture.setSmooth(true);
//		sf::Sprite sprite;
//		sprite.setTexture(texture);
//		sprite.setScale((float)window.getSize().x / (float)texture.getSize().x, (float)window.getSize().y / (float)texture.getSize().y);
//		
//		int layer = 0;
//		Event event;
//
//		Font MyFont;
//		if (!MyFont.loadFromFile("arial.ttf"))
//		{
//			return 0;
//		}
//		Text text;
//		text.setFont(MyFont);
//		text.setString("Exit");
//		text.setCharacterSize(100);
//		text.setFillColor(Color::Blue);
//		text.setPosition(Vector2f(830, 837));
//
//		while (window.isOpen())
//		{
//			while (window.pollEvent(event))
//			{
//				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
//					window.close();
//
//				else if (event.type == Event::MouseButtonPressed) {
//					if (event.mouseButton.button == Mouse::Left)
//					{
//						layer++;
//						cout << "X:" << event.mouseButton.x << endl;
//						cout << "Y:" << event.mouseButton.y << endl;
//						if ((event.mouseButton.x >= 820 && event.mouseButton.x <= 1000) &&
//							(event.mouseButton.y >= 860 && event.mouseButton.y <= 920))
//						{
//							window.close();
//						}
//					}
//				}
//			}
//			window.clear(Color::Black);
//			int health = 400;
//			int low_health = 50;
//			if (layer == 0) {
//				sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
//				rectangle.setSize(Vector2f(health, low_health));
//				rectangle.setFillColor(Color::Green);
//				window.draw(sprite);
//				window.draw(text);
//				window.draw(rectangle);
//				window.display();
//			}
//			else
//			{
//				sf::CircleShape circle(200.f);
//				circle.setTexture(&texture);
//				circle.setTextureRect(sf::IntRect(10, 10, 100, 100));
//				window.draw(circle);
//				window.display();
//			}
//		}
//
//	}
//};
//
//int main()
//{
//	Menu show;
//	show.show_Menu();
//}
