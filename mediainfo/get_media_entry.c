/* * 
 *  $Id: get_media_entry.c 2 2004-06-08 15:08:53Z mancho $
 *  
 *  This file is part of Fenice
 *
 *  Fenice -- Open Media Server
 *
 *  Copyright (C) 2004 by
 *  	
 *	- Giampaolo Mancini	<giampaolo.mancini@polito.it>
 *	- Francesco Varano	<francesco.varano@polito.it>
 *	- Marco Penno		<marco.penno@polito.it>
 *	- Federico Ridolfo	<federico.ridolfo@polito.it>
 *	- Eugenio Menegatti 	<m.eu@libero.it>
 *	- Stefano Cau
 *	- Giuliano Emma
 *	- Stefano Oldrini
 * 
 *  Fenice is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  Fenice is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Fenice; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *  
 * */

#include <stdlib.h>
#include <string.h>
#include <fenice/utils.h>
#include <fenice/mediainfo.h>


int get_media_entry(media_entry *req,media_entry *list,media_entry **result)
// return a media with the requested characteristics
{
    if (media_is_empty(req)) {
	    *result=default_selection_criterion(list);
	    if (*result==NULL) {
	    	return ERR_NOT_FOUND;
	    }
	}
	else {
	    *result=search_media(req,list);
	    if (*result==NULL) {
	    	return ERR_NOT_FOUND;
	    }
	}
	return ERR_NOERROR;
}

