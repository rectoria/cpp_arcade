/*
** EPITECH PROJECT, 2021
** cpp_arcade
** File description:
** Created by rectoria
*/
#include "lib_nCurses.hpp"

void lib_nCurses::putPixel()
{
}

const std::string &lib_nCurses::getName() const
{
	return _name;
}

extern "C" IGraphicalLib *entryPoint(void){
	return new lib_nCurses();
}