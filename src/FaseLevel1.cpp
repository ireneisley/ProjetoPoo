#include "FaseLevel1.hpp"
#include "Enemy.hpp"
#include <iostream>

void FaseLevel1::init()
{	
	//Objetos de jogo
	princesa = new ObjetoDeJogo("Princess",SpriteAnimado("rsc/principe.anm",2,COR::AZUL),8,190);
	objs.push_back(princesa);
	
	bruxa = new ObjetoDeJogo("Bruxa", SpriteAnimado("rsc/bruxa.anm",1, COR::ROSA), 0, 0);
	bruxa->desativarObj();
	objs.push_back(bruxa);
	
	guardas[0] = new Enemy(ObjetoDeJogo("Enemy1",SpriteAnimado("rsc/inimigo1.anm",2,COR::VERDE),35,32), ESTADO::CIMA);
	objs.push_back(guardas[0]);
	
	guardas[1] = new Enemy(ObjetoDeJogo("Enemy2",SpriteAnimado("rsc/inimigo2.anm",2,COR::VERDE),9,137), ESTADO::BAIXO);
	objs.push_back(guardas[1]);
		
	chave = new ObjetoDeJogo("Chave",Sprite("rsc/key.img",COR::AMARELA),47,145);
	objs.push_back(chave);
	
	miniChave = new ObjetoDeJogo("MiniChave",TextSprite("O=;",COR::AMARELA),6,108);
	objs.push_back(miniChave);
	miniChave->desativarObj();
	
	porta = new Door(ObjetoDeJogo("Door",SpriteAnimado("rsc/door.anm",1,COR::MARROM),24,191));
	objs.push_back(porta);
	
	tapetePorta = new ObjetoDeJogo("Tapete",SpriteBuffer(17,1),32,190);
	objs.push_back(tapetePorta);
	
	hero = new Hero(ObjetoDeJogo("Hero",SpriteAnimado("rsc/hero.anm",2,COR::ROSA),35,94));
	objs.push_back(hero);
	
	portao = new ObjetoDeJogo("frontDoor",Sprite("rsc/frontDoor.img",COR::MARROM),49,96);
	objs.push_back(portao);
	
													 //std::string(20,'#')
	objs.push_back(new ObjetoDeJogo("Life",TextSprite("##############", COR::VERMELHA),6,77));
	SpriteBase *tmp = const_cast<SpriteBase*> (objs.back()->getSprite());
	life = dynamic_cast<TextSprite*> (tmp);
	
	//blocos
	objs.push_back(new ObjetoDeJogo("B1",Sprite("rsc/castleBlock1.img",COR::BRANCA),6,187));
	colisoes.push_back(objs.back());
	
	objs.push_back(new ObjetoDeJogo("B2",Sprite("rsc/castleBlock2.img",COR::BRANCA),6,59));
	colisoes.push_back(objs.back());
	
	objs.push_back(new ObjetoDeJogo("B3",Sprite("rsc/castleBlock3.img",COR::BRANCA),16,29));
	colisoes.push_back(objs.back());
	
	objs.push_back(new ObjetoDeJogo("B4",Sprite("rsc/castleBlock4.img",COR::BRANCA),19,92));
	colisoes.push_back(objs.back());
	
	objs.push_back(new ObjetoDeJogo("B6",Sprite("rsc/castleBlock6.img",COR::BRANCA),6,132));
	colisoes.push_back(objs.back());
	
	objs.push_back(new ObjetoDeJogo("B7",Sprite("rsc/castleBlock7.img",COR::BRANCA),41,32));
	colisoes.push_back(objs.back());
	
	objs.push_back(new ObjetoDeJogo("B8",Sprite("rsc/castleBlock8.img",COR::BRANCA),6,165));
	colisoes.push_back(objs.back());
	
}

unsigned FaseLevel1::run(SpriteBuffer &screen)
{
	std::string ent;
	bool gameover = false;
	
	//padrão
	screen.clear();
	draw(screen);
	system("clear");
	show(screen);
	
	while (true)
	{
		//lendo entrada
		getline(std::cin,ent);
		
		//processando entradas
		int posL = hero->getPosL(), posC = hero->getPosC();
		
		if (ent == "w" && hero->getPosL() > 10)
			hero->moveUp(3);
		else if (ent == "s" && hero->getPosL() < screen.getAltura() - 15)
			hero->moveDown(3);
		else if (ent == "a" && hero->getPosC() > 12)
			hero->moveLeft(3);
		else if (ent == "d" && hero->getPosC() < screen.getLarguraMaxFit() - hero->getSprite()->getLarguraMaxFit() - 13)
		//else if (ent == "d" && hero->getPosC() < 250)
			hero->moveRight(3);
		else if (ent == "x") {
			for (int g = 0 ; g < 2 ; g++)
				if (hero->colideComBordas(*guardas[g])) {
					guardas[g]->sofrerAtaque(hero->atacar());
					if (!guardas[g]->isAlive())
						guardas[g]->desativarObj();
				}
		}
		else if (ent == "q")
			return Fase::END_GAME;
			
		int posLGuarda1 = guardas[1]->getPosL();
		
		switch (posLGuarda1) {
			case 7:
				guardas[1]->setEstado(ESTADO::BAIXO);
			break;
			
			case 48:
				guardas[1]->setEstado(ESTADO::CIMA);
			break;
		}
		
		int posLGuarda0 = guardas[0]->getPosL(), posCGuarda0 = guardas[0]->getPosC();
		
		if(posLGuarda0 == 9 && posCGuarda0 == 32){
			guardas[0]->setEstado(ESTADO::ESQUERDA);
		}
		
		if(posLGuarda0 == 9 && posCGuarda0 == 2){
			guardas[0]->setEstado(ESTADO::BAIXO);
		}
		
		if(posLGuarda0 == 47 && posCGuarda0 == 2){
			guardas[0]->setEstado(ESTADO::DIREITA);
		}
		
		if(posLGuarda0 == 47 && posCGuarda0 == 62){
			guardas[0]->setEstado(ESTADO::CIMA);
		}
		
		if(posLGuarda0 == 9 && posCGuarda0 == 62){
			guardas[0]->setEstado(ESTADO::DIREITA);
		}
		
		if(posLGuarda0 == 9 && posCGuarda0 == 95){
			guardas[0]->setEstado(ESTADO::BAIXO);
		}
		
		if(posLGuarda0 == 42 && posCGuarda0 == 95){
			guardas[0]->setEstado(ESTADO::DIREITA);
		}
		
		if(posLGuarda0 == 42 && posCGuarda0 == 187){
			guardas[0]->setEstado(ESTADO::CIMA);
		}
		
		if(posLGuarda0 == 29 && posCGuarda0 == 187){
			guardas[0]->setEstado(ESTADO::PARADO);
		}

		if (colideComBloco())
			hero->moveTo(posL,posC);
		
		//processando eventos
		for (int g = 0 ; g < 2 ; g++)
				if (hero->colideComBordas(*guardas[g])) {
					hero->sofrerAtaque(guardas[g]->atacar());
					
					if (!hero->isAlive()) {
						bruxa->moveTo(posL, posC-10);
						hero->desativarObj();
						bruxa->ativarObj();
						gameover = true;
						//return Fase::GAME_OVER;					
					}
					
					life->setText(std::string(hero->getLife()/5,'#'));
				}
		
		if (hero->colideComBordas(*chave))
		{
			chave->desativarObj();
			miniChave->ativarObj();
			hero->pegarChave();
		}
		else if (hero->colideComBordas(*tapetePorta) && hero->possuiChave())
		{
			porta->openTheDoor();
		}
		else if (hero->colideComBordas(*princesa))
		{
			princesa->desativarObj();
			hero->salvarPrincesa();
		}
		else if (hero->colideComBordas(*portao) && hero->salvouPrincesa())
		{
			return Fase::LEVEL_COMPLETE;
		}
		
		
		//padrão
		update();
		screen.clear();
		draw(screen);
		system("clear");
		show(screen);
		
		if (gameover) return Fase::GAME_OVER;
	}
	
	return Fase::END_GAME; // não necessário
}

bool FaseLevel1::colideComBloco() const
{
	for (auto it = colisoes.begin() ; it != colisoes.end() ; ++it)
		if (hero->colideCom(**it)) {
			return true;
		}
	
	if (hero->colideCom(*porta) && !porta->isOpen() )
		return true;
	
	return false;
}