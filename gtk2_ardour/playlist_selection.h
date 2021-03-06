/*
    Copyright (C) 2000-2007 Paul Davis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#ifndef __ardour_gtk_playlist_selection_h__
#define __ardour_gtk_playlist_selection_h__

#include <list>
#include <boost/shared_ptr.hpp>

namespace ARDOUR {
	class Playlist;
}

struct PlaylistSelection : std::list<boost::shared_ptr<ARDOUR::Playlist> > {
public:
	const_iterator
	get_nth(ARDOUR::DataType type, size_t nth) const {
		size_t count = 0;
		for (const_iterator l = begin(); l != end(); ++l) {
			if ((*l)->data_type() == type) {
				if (count++ == nth) {
					return l;
				}
			}
		}
		return end();
	}
};

#endif /* __ardour_gtk_playlist_selection_h__ */
