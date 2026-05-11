#include "ball.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

Ball::Ball(const sf::Vector2f start, const sf::Vector2f velocity, sf::Color color, const float radius) : velocity_(velocity) {
  shape_.setRadius(radius);
  shape_.setFillColor(color);
  shape_.setPosition(start);
}

sf::CircleShape Ball::getShape() const {
  return shape_;
}
sf::FloatRect Ball::getBounds() const {
  return shape_.getGlobalBounds();
}

void Ball::reflectX() {
  velocity_.x = -velocity_.x;
}

void Ball::reflectY() {
  velocity_.y = -velocity_.y;
}

sf::Vector2f Ball::getPosition() const {
  return shape_.getPosition();
}

void Ball::update(sf::Time dt) {
  shape_.setPosition({shape_.getPosition().x + velocity_.x * dt.asSeconds(), shape_.getPosition().y + velocity_.y * dt.asSeconds()});
}
