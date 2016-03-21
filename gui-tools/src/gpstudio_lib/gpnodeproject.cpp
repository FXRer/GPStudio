/****************************************************************************
** Copyright (C) 2014 Dream IP
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

#include "gpnodeproject.h"

GPNodeProject::GPNodeProject()
{
    //if(QFile::exists("../../../std_project/node_generated.xml")) openNodeGeneratedFile("../../../std_project/node_generated.xml");
    _lib = new Lib("../");
}

GPNodeProject::~GPNodeProject()
{
    delete _lib;
}

Lib *GPNodeProject::lib() const
{
    return _lib;
}

QString GPNodeProject::name() const
{
    return _name;
}

void GPNodeProject::setName(const QString &name)
{
    _name = name;
}
