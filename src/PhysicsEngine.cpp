#include "physics_engine.h"

void PhysicsEngine::addObject(std::unique_ptr<PhysicsObject> obj) {
  object.push_back(std::move(obj));
}

void PhysicsEngine::update(float dt) {
  for (auto& obj : objects)
    obj->update(dt); // update() func for objects to be declared
  
  for (int i = 0; i < objects.size(); i++) {
    for (int j = i + 1; j < objects.size(); j++) {
    // require a func to access x, y coordinates
    }
  }
}

void PhysicsEngine::draw(sf::RenderWindow& window) {
  for (auto& obj : objects) 
    obj->draw(window); // draw() func to open window and display collision
}
      
  
