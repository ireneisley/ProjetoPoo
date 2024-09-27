#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "../ASCII_Engine/ObjetoDeJogo.hpp"
#include "Estado.hpp"

class Enemy : public ObjetoDeJogo
{
public:
	Enemy(const ObjetoDeJogo &obj, ESTADO e = ESTADO::PARADO, int life=30, int velAtaque=3) :
			ObjetoDeJogo(obj), life(life), velAtaque(velAtaque), contAtaque(velAtaque), estado(e) {}
	
	virtual ~Enemy(){}
	
	virtual void update () override {
		switch (this->estado) {
			case ESTADO::CIMA:
				this->moveUp(1);
			break;
			
			case ESTADO::BAIXO:
				this->moveDown(1);
			break;
			case ESTADO::DIREITA:
				this->moveRight(1);
			break;
			case ESTADO::ESQUERDA:
				this->moveLeft(1);
			break;
			case ESTADO::PARADO:
				this->moveTo(this->getPosL(), this->getPosC());
			break;
		}
	}
	
	bool isAlive() const { return life != 0; }
	
	void sofrerAtaque(int ataque) {
		life = (life - ataque >= 0)?(life - ataque):0;
	}
	
	int atacar() { 
		if (--contAtaque == 0) {
			contAtaque = velAtaque;
			return 10;
		}
		return 0;
	}
	
	void setEstado(ESTADO e) {
		this->estado = e;
	}

private:
	int life;
	int velAtaque, contAtaque;
	ESTADO estado; 
};

#endif // ENEMY_HPP