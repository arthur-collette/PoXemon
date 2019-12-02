#include "Player.h"

void Player::draw(sf::RenderTarget& target) {//const ?
	target.draw(sprite);
	health.draw(target);
	bullets.draw(target);
	bullets.bulletbar.draw(target);
}

void Player::update(float& deltaTime, sf::RenderWindow& window, sf::Clock& clock, sf::Time& elapsed, float& groundY) {   // Movement is dependant on time not on frame rate
									// This means that we can have smooth movement over multiple frames, instead of static movement per each frame

		velocityX = 0.0f;
		//Left and right movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			velocityX -= speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			velocityX += speed;
		}
		//Jumps
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && canJump) {
			canJump = false;       //While jumping you can't jump
			velocityY = -sqrt(2.0f * 981.0f * jumpHeight);
		}
		//Testing health - will change when we have collision recognition
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			health.setHealth(health.getHealth() - 1);
		}
		//Bullets: shooting
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			bullets.new_shot(x,y,sprite.getGlobalBounds(), window, sf::Mouse::getPosition(window));
		}
		if (! sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			bullets.was_released = true;
		}


		int i = bullets.update(deltaTime, clock, elapsed, (*enemy).sprite, groundY);
		if (i!=0) (*enemy).health.decrease(i);
		

		health.update();

		velocityY += 981.0f * deltaTime;
		move(deltaTime);
	}

void Player::move(float& deltaTime) {
		x += velocityX * deltaTime;
		y += velocityY * deltaTime;
		float groundY = 300.0f; //Cannot go below this height
		if (y >= groundY) {
			y = groundY;
			velocityY = 0.0f;
			canJump = true;
		}

		sprite.setPosition(x, y);
	}


void Player::collision_opponent() {
	if (Collision::PixelPerfectTest(sprite, (*enemy).sprite)) {
		//make it impossible for the pokemons to 'cross' each other
		//maybe use some mechanics equations ?
	}
}
