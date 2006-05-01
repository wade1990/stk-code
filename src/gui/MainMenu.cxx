//  $Id: MainMenu.cxx,v 1.3 2005/05/31 00:49:50 joh Exp $
//
//  TuxKart - a fun racing game with go-kart
//  Copyright (C) 2004 Steve Baker <sjbaker1@airmail.net>
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#include "MainMenu.h"
#include "WidgetSet.h"
#include "RaceManager.h"

MainMenu::MainMenu()
{
	menu_id = widgetSet -> varray(0);
	widgetSet -> start(menu_id, "Single Player",  GUI_MED, MENU_SINGLE, 0);
	widgetSet -> state(menu_id, "Multiplayer",  GUI_MED, MENU_MULTI, 0);
	widgetSet -> state(menu_id, "Options",  GUI_MED, MENU_OPTIONS, 0);
	//widgetSet -> state(menu_id, "Credits",  GUI_MED, MENU_REPLAY, 0);
	widgetSet -> state(menu_id, "Quit",  GUI_MED, MENU_QUIT, 0);
        widgetSet -> space(menu_id);

	widgetSet -> layout(menu_id, 0, 0);
}

MainMenu::~MainMenu()
{
	widgetSet -> delete_widget(menu_id) ;
}
	
void MainMenu::update(float dt)
{	
	widgetSet -> timer(menu_id, dt) ;
	widgetSet -> paint(menu_id) ;
}

void MainMenu::select()
{
	switch ( widgetSet -> token (widgetSet -> click()) )
	{
	case MENU_SINGLE:	       
                race_manager->setNumPlayers(1);
                guiStack.push_back(GUIS_GAMEMODE);     
                break;
	case MENU_MULTI:
 		guiStack.push_back(GUIS_NUMPLAYERS);
                break;
                
	case MENU_REPLAY:
                break;

	case MENU_OPTIONS:     
                guiStack.push_back(GUIS_OPTIONS);	
                break;

	case MENU_QUIT:
                guiStack.clear();
                break;
	}
}

void MainMenu::keybd(int key)
{
	switch ( key )
	{
	case 27:   //ESC
	        guiStack.clear();
		break;

	default:
	        BaseGUI::keybd(key);
		break;
	}
}

/* EOF */
