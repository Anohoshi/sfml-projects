#include "bat.hpp"
#include <SFML/Graphics/RectangleShape.hpp>

Bat::Bat(sf::Vector2f start, float speed, sf::Color color) : speed_(speed) {
  shape_.setPosition(start);
  shape_.setSize(size);
}

const sf::RectangleShape& Bat::getShape() const {
  return shape_;
}

sf::FloatRect Bat::getBounds() const { return shape_.getGlobalBounds(); }

void Bat::update(sf::Time dt, int direction) {
  shape_.setPosition(
      {shape_.getPosition().x,
          shape_.getPosition().y + speed_ * direction * dt.asSeconds()});
}
