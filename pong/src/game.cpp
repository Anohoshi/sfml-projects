#include "game.hpp"
#include "ball.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowEnums.hpp>

Game::Game() : vm_(sf::VideoMode::getDesktopMode()), window_(vm_, "Pong", sf::State::Fullscreen), leftBat_({50, vm_.size.y / 2.f}, 200, sf::Color::White), rightBat_({vm_.size.x - 50.f, vm_.size.y / 2.f}, 200, sf::Color::White), ball_({vm_.size.x / 2.f, vm_.size.y / 2.f}, {200.f, 200.f}) {
  view_.setSize({static_cast<float>(vm_.size.x), static_cast<float>(vm_.size.y)});
  view_.setCenter({static_cast<float>(vm_.size.x) / 2.f, static_cast<float>(vm_.size.y) / 2.f});
  window_.setView(view_);
}

void Game::processInput() {
  while (const std::optional event = window_.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      window_.close();
    } else if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
      if (key->scancode == sf::Keyboard::Scancode::Escape)
        window_.close();
      if (key->scancode == sf::Keyboard::Scancode::Space)
        paused = !paused;
    }
  }
}

void Game::checkCollisions() {
  if (ball_.getPosition().y <= 0 || ball_.getPosition().y >= vm_.size.y)
    ball_.reflectY();
  if (ball_.getPosition().x <= 0 || ball_.getPosition().x >= vm_.size.x)
    ball_.reflectX();
  if (ball_.getBounds().findIntersection(leftBat_.getBounds()) || ball_.getBounds().findIntersection(rightBat_.getBounds()))
    ball_.reflectX();
}

void Game::update(sf::Time dt) {
  if (paused)
    return;

  // Left bat
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W)) {
    if (leftBat_.getBounds().position.y > 0) // не уехала за верх
      leftBat_.update(dt, -1);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)) {
    if (leftBat_.getBounds().position.y + leftBat_.getBounds().size.y < vm_.size.y) // не уехала за низ
      leftBat_.update(dt, 1);
  }

  // Right bat
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up)) {
    if (rightBat_.getBounds().position.y > 0)
      rightBat_.update(dt, -1);

  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down)) {
    if (rightBat_.getBounds().position.y + rightBat_.getBounds().size.y < vm_.size.y) // не уехала за низ
      rightBat_.update(dt, 1);
  }

  // Ball
  checkCollisions();

  ball_.update(dt);
}

void Game::render() {
  window_.clear();
  window_.draw(leftBat_.getShape());
  window_.draw(rightBat_.getShape());
  window_.draw(ball_.getShape());

  window_.display();
}

void Game::run() {
  sf::Clock clock;
  while (window_.isOpen()) {
    processInput();
    sf::Time dt = clock.restart();
    update(dt);
    render();
  }
}
