#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

class Bat {
private:
  static constexpr sf::Vector2f size{20.f, 100.f};
  sf::RectangleShape shape_;
  float speed_;

public:
  Bat(sf::Vector2f start, float speed, sf::Color color);
  sf::RectangleShape getShape() const;
  sf::FloatRect getBounds() const;
  void update(sf::Time dt, int direction);
};
