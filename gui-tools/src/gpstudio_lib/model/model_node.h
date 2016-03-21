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

#ifndef MODEL_NODE_H
#define MODEL_NODE_H

#include "gpstudio_lib_common.h"

#include <QString>
#include <QDomElement>
#include <QList>

#include "model_block.h"

class ModelFIBlock;
class ModelCIBlock;
class ModelPIBlock;
class ModelIOCom;

class GPSTUDIO_LIB_EXPORT ModelNode
{
public:
    ModelNode();
    ~ModelNode();

    QString name() const;
    void setName(const QString &name);

    bool isValid() const;

    QList<ModelBlock *> &blocks();
    const QList<ModelBlock *> &blocks() const;
    void addBlock(ModelBlock *block);

    ModelFIBlock *getFIBlock() const;
    ModelCIBlock *getCIBlock() const;
    ModelPIBlock *getPIBlock() const;
    ModelIOCom *getIOCom() const;

public:
    static ModelNode *readFromFile(const QString &fileName);
    static ModelNode *fromNodeGenerated(const QDomElement &domElement);

protected:
    QString _name;
    bool _valid;

    QList<ModelBlock *> _blocks;
};

#endif // MODEL_NODE_H