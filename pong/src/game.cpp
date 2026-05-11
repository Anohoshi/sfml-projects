#include "game.hpp"
#include "ball.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowEnums.hpp>

Game::Game() : vm_(sf::VideoMode::getDesktopMode()), window_(vm_, "Pong", sf::State::Fullscreen), leftBat_({50, windowHeight / 2.f}, 200, sf::Color::White), rightBat_({windowWidth - 50, windowHeight / 2.f}, 200, sf::Color::White), ball_({windowWidth / 2.f, windowHeight / 2.f}, {200.f, 200.f}) {
  view_.setSize({windowWidth, windowHeight});
  view_.setCenter({windowWidth / 2.f, windowHeight / 2.f});
  window_.setView(view_);
}

void Game::processInput() {
  while (const std::optional event = window_.pollEvent()) {
    if (event->is<sf::Event::Closed>()) {
      window_.close();
    } else if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
      if (key->scancode == sf::Keyboard::Scancode::Escape)
        window_.close();
    }
  }
}
void Game::update(sf::Time dt) {
  if (paused)
    return;

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
