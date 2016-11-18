/****************************************************************************
** Copyright (C) 2016 Dream IP
**
** This file is part of GPStudio.
**
** GPStudio is a free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**
****************************************************************************/

#ifndef FEATURE_H
#define FEATURE_H

#include "gpstudio_gui_common.h"

class GPSTUDIO_GUI_EXPORT Feature
{
public:
    enum Type {
        Points,
        PointsValue,
        Rects,
        RectsValue
    };

    Feature();

    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);

    int w() const;
    void setW(int w);

    int h() const;
    void setH(int h);

    int val() const;
    void setVal(int val);

protected:
    int _x;
    int _y;
    int _w;
    int _h;
    int _val;
};

#endif // FEATURE_H