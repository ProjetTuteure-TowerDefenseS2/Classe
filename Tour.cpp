#include "Tour.h"



	Tour::Tour()
	{
		float posX;
		float posY;

		m_afficher = false;
	}

	void Tour::creerTour(string nomTexture, string nomTexture_2, string nomTexture_3, string nomTexture_4, string nomTexture_5)
	{
	    m_Tir.creerTir(nomTexture, nomTexture_2, nomTexture_3, nomTexture_4, nomTexture_5);
		tour1.setSize(Vector2f(20, 20));
		tour1.setFillColor(sf::Color(0, 0, 0));
		tour1.setPosition(50,50);
	}

	void Tour::setPosition(float x, float y)
	{
		posX=x;
		posY=y;

		tour1.setPosition(posX,posY);
	}

	void Tour::draw(RenderWindow & window)
	{
		window.draw(tour1);
	}

	void Tour::setFillColor()
	{
		tour1.setFillColor(sf::Color(250, 250, 250));
	}

	void Tour::setFillColorBlack()
	{
		tour1.setFillColor(sf::Color(0, 0, 0));
	}

	float Tour::getGlobalBoundsW()
	{
		return tour1.getGlobalBounds().width+posX;
	}

	float Tour::getGlobalBoundsH()
	{
		return tour1.getGlobalBounds().height+posY;
	}
