# O Caminho da Coragem 🏰

### Projeto Final de Programação Orientada a Objetos
### IFPB - Campus Campina Grande

---

## 🎮 Descrição

**O Caminho da Coragem** é um jogo de labirinto onde a heroína, uma princesa destemida, deve resgatar o príncipe. A jornada é cheia de desafios, onde a princesa precisa coletar uma chave, evitar ou enfrentar sapos, e salvar o príncipe preso no castelo.

- Se a princesa encontrar um sapo sem vidas suficientes, ela se transforma em uma bruxa, resultando em **game over** 🧙‍♀️.
- O jogo possui **3 fases** emocionantes, onde cada uma traz novos desafios e aventuras!

---

## 🚀 Funcionalidades

- **Fase 1:** A princesa caminha até o castelo.
- **Fase 2:** A princesa coleta uma chave essencial para salvar o príncipe.
- **Fase 3:** A princesa finalmente se reúne com o príncipe 👑❤️.
  
### Controles:
- **Movimento:** "w", "s", "a", "d" 🎮
- **Ataque:** "x" ⚔️

---

## Tecnologias Utilizadas🛠️

- **Linguagem:** C++
- **Engine:** Criada pelo professor Victor Oliveira
- **Compilação:** ASCII Engine e código fonte em C++

---

## Como Rodar o Projeto🏗️ 

Siga os passos abaixo para compilar e rodar o jogo no seu terminal:

1. Certifique-se de que possui o **g++** instalado.
2. Navegue até o diretório do projeto.
3. Execute o seguinte comando no terminal para compilar e rodar o jogo:

```bash
g++ -std=c++17 -o game `find ASCII_Engine -iname "*.cpp" -print` src/*.cpp && ./game
