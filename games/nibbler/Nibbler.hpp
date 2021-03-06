//
// Created by rectoria on 30/03/18.
//

#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <list>
#include "IGameLib.hpp"

namespace Arcade {
	class Nibbler : public IGameLib {
	public:
		Nibbler() = default;
		~Nibbler() final = default;

		/* Get the name of the game */
		const std::string getName() const final;

		/* Resources handling */
		// Initializes the library
		bool init() final;

		// Unloads the library
		bool stop() final;

		// Processes the key obtained by the IGraphicLib from the user to update the game state
		bool applyEvent(Keys key) final;

		// Updates the game state. (Move the player forward and/or move the NPCs)
		bool update() final;

		// Renders the game state to the screen. This should call IGraphicLib::refresh() to display content to the user.
		void refresh(IGraphicLib &graphicLib) final;

		// To call at the end of the execution of the game (after the player loose or win) for getting his score
		size_t getScore() final;

	private:
		bool moveUp();
		bool moveDown();
		bool moveLeft();
		bool moveRight();
		void printMap(IGraphicLib &, Vect<size_t> const &);
		void printSnake(Arcade::IGraphicLib &, Arcade::Vect<size_t> const &);
		void printBonus(Arcade::IGraphicLib &, Arcade::Vect<size_t> const &);
		void checkBonus();
		bool lost() const;
		bool checkBonusOnSnake() const;

		const std::string _name = "Nibbler";
		std::time_t _timer = 0;
		std::list<Arcade::Vect<size_t>> _snake;
		Arcade::Vect<size_t> _bonus;
		Arcade::PixelBox _pB;
		size_t _direction = 2;
		int _score = 0;
		const std::vector<std::string> _map = {
			"                                         ",
			" *****                             ***** ",
			" ***                                 *** ",
			"     **  ***********************  **     ",
			"     *                             *     ",
			"                                         ",
			"    *              ****             *    ",
			"    *              ****             *    ",
			"    *              ****             *    ",
			"    *      ********************     *    ",
			"    *      ********************     *    ",
			"    *              ****             *    ",
			"    *              ****             *    ",
			"                   ****                  ",
			"     *                             *     ",
			"     **  ***********************  **     ",
			" ***                                 *** ",
			" *****                             ***** ",
			"                                         "};
	};
};


#endif
