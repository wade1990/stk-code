//  $Id$
//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2006 SuperTuxKart-Team
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

#ifndef HEADER_CONFIGDISPLAY_H
#define HEADER_CONFIGDISPLAY_H

#include <vector>

#include "base_gui.hpp"
#include "translation.hpp"
#include "display_res_confirm.hpp"

class ConfigDisplay: public BaseGUI
{
public:
    ConfigDisplay();
    ~ConfigDisplay();

    void select();

private:
    std::vector<std::pair<int,int> > m_sizes;
    int m_sizes_index;
    int m_sizes_size;
    char m_resolution[MAX_MESSAGE_LENGTH];
    int m_curr_width;
    int m_curr_height;
    int m_blacklist_res_size;
        
    // changeResolution reverse param is set true when changing to a previous resolution  
    void changeResolution(int width, int height, bool reverse=false);
    void getScreenModes();
    void changeApplyButton();
    // onBlacklist returns the index of the resolution in the blacklist 
    // or -1 if not in the blacklist
    int onBlacklist(); 
    int onBlacklist(int width, int height);  
    void showBlacklistButtons();
};

#endif
