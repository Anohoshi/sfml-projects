#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

class Ball {
private:
  sf::CircleShape shape_;
  sf::Vector2f velocity_;

public:
  Ball(const sf::Vector2f start, const sf::Vector2f velocity, sf::Color color = sf::Color::White, const float radius = 6.f);
  const sf::CircleShape& getShape() const;
  sf::FloatRect getBounds() const;
  void reset(const sf::Vector2f start);
  void reflectX();
  void reflectY();
  sf::Vector2f getPosition() const;
  void update(sf::Time dt);
};
