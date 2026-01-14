#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <iostream>

int main() {
  auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}),
                                 "CMake SFML Project", sf::Style::Resize);
  window.setFramerateLimit(60);
  // load font
  sf::Font font;
  if (!font.openFromFile("assets/fonts/CodeNewRoman/"
                         "CodeNewRomanNerdFontMono-Regular.otf")) {
    // Fixme: should consider using spdlog
    std::cout << "Cannot load font file" << std::endl;
    return 1;
  }
  sf::Text text(font, "Hello SFML, I'm Ready!", 26);
  text.setFillColor(sf::Color::White);
  // -----------------------
  // window loop
  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear();
    window.draw(text);
    window.display();
  }
}
