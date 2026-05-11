#pragma once

#include "ball.hpp"
#include "bat.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/VideoMode.hpp>

class Game {
private:
  // View
  sf::VideoMode vm_;
  sf::RenderWindow window_;
  sf::View view_;

  // Game objects
  Bat leftBat_, rightBat_;
  Ball ball_;

  // HUD
  sf::Font font_;
  sf::Text scoreText_;

  int leftScore_ = 0;
  int rightScore_ = 0;

  // Game state
  bool paused = true;

  // Functions
  void processInput();
  void checkCollisions();
  void update(sf::Time dt);
  void render();

public:
  Game();
  void run();
};
