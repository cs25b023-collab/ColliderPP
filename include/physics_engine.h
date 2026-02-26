#pragma once

#include <memory>
#include <vector>
#include "physics_object.h"

class PhysicsEngine {
private:
  std::vector<std::unique_ptr<PhysicsObject>> objects;
  
public:
  void addObject(std::unique_ptr<PhysicsObject> obj);
  void update(float dt);
  void draw(sf::RenderWindow& window);
};


