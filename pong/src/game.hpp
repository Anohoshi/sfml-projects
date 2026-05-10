#pragma once
#include "ball.hpp"
#include "bat.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>

class Game {
private:
  // Constants
  const float DESIGN_WIDTH = 1920.0f;
  const float DESIGN_HEIGHT = 1080.0f;

  // Window and view
  sf::RenderWindow window_;
  sf::View gameView_;

  // Game objects
  Ball ball_;
  Bat leftBat_, rightBat_;

  // Game state
  bool paused_ = false;

  // Functions
  void processInput();
  void checkCollisions();
  void update(sf::Time dt);
  void render();

public:
  Game();
  void run();
};
