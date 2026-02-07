#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	m_snake.setRadius(20);
	m_snake.setPosition({ 50, 50 });
	m_snake.setFillColor(sf::Color::Green);

	m_sheepTexture.loadFromFile("gfx/sheep_sheet.png");
	m_sheep.setTexture(&m_sheepTexture, true);
	m_sheep.setSize({ 100,100 });
	m_sheep.setTextureRect(sf::IntRect({ 0,0 }, { 64,64 }));
	m_sheep.setInput(&m_input);

}

// handle user input
void Level::handleInput(float dt)
{
	m_sheep.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	// check wall collision
	sf::Vector2f pos = m_sheep.getPosition();
	sf::Vector2f size = m_sheep.getSize(); // getSize() is a function, not a member variable
	float halfWidth = size.x / 2.f;
	float halfHeight = size.y / 2.f;

	if (pos.x < 0 || pos.x + size.x > m_window.getSize().x || pos.y < 0 || pos.y + size.y > m_window.getSize().y)
	{
		std::cout << "Game over";
	}

	m_sheep.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_snake);
	m_window.draw(m_sheep);
	endDraw();
}

