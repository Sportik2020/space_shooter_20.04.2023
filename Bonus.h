#pragma once
#include "settings.h"
#include "Player.h"

class Bonus {
public:
	enum BonusType { MEDKIT, SPEED_BOOST, KABOOM, MAX_BONUS_TYPE };
	Bonus(sf::Vector2f meteorPos, size_t bonusType);
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
	void update();
	void setDel();
	bool isToDel();
	void draw(sf::RenderWindow& window);
	void act(Player& player);
private:
	sf::Sprite sprite;
	sf::Texture texture;
	BonusType type;
	sf::Clock timer;
	bool del = false;
};
Bonus::Bonus(sf::Vector2f meteorPos, size_t bonusType) {
	if (type == MEDKIT) {
		texture.loadFromFile(Medkit_File_Name);
	};
	if (type == SPEED_BOOST) {
		texture.loadFromFile(Speedbonus_File_Name);
	};
	if (type == KABOOM) {
		texture.loadFromFile(Kaboom_File_Name);
	};
	sprite.setTexture(texture);
	sprite.setPosition(meteorPos);
}

void Bonus::update() {
	int now = timer.getElapsedTime().asMilliseconds(); if (now > 5000) {
		del = true;
	}
}
void Bonus::draw(sf::RenderWindow& window) { window.draw(sprite); }

sf::FloatRect Bonus::getHitBox() { return sprite.getGlobalBounds(); }

sf::Vector2f Bonus::getPosition() { return sprite.getPosition(); }

bool Bonus::isToDel() { return del; }

void Bonus::setDel() { del = true; }

void Bonus::act(Player& player) {
	switch (type) {
	case  KABOOM:
		break;
	case MEDKIT:
		player.HP_UP(50);
		break;
	case SPEED_BOOST:
		player.Speed_Boost();
		break;
	}
}