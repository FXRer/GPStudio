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

#include "flowviewerinterface.h"

#include <QDebug>

FlowViewerInterface::FlowViewerInterface(FlowConnection *flowConnection)
{
    addFlowConnection(flowConnection);
}

FlowViewerInterface::FlowViewerInterface(const QList<FlowConnection *> &flowConnections)
{
    foreach (FlowConnection *flowConnection, flowConnections)
    {
        addFlowConnection(flowConnection);
    }
}

FlowViewerInterface::~FlowViewerInterface()
{
}

const QList<FlowConnection *> &FlowViewerInterface::flowConnections() const
{
    return _flowConnections;
}

void FlowViewerInterface::addFlowConnection(FlowConnection *flowConnection)
{
    _flowConnections.append(flowConnection);

    // flow connect to reception
    connect(flowConnection, SIGNAL(flowReceived(FlowPackage)), this, SLOT(processData(FlowPackage)));

    // connect to flow properties
    Property *dataTypeProperty = flowConnection->flow()->assocProperty()->path("datatype");
    if(dataTypeProperty)
        connect(dataTypeProperty, SIGNAL(valueChanged(QVariant)), this, SLOT(changeDataType()));

    foreach (Property *property, flowConnection->flow()->assocProperty()->subProperties())
    {
        //qDebug()<<property->name();
    }
    changeDataType();
}

void FlowViewerInterface::removeFlowConnection(FlowConnection *flowConnection)
{
    _flowConnections.removeOne(flowConnection);

    // disconnect all from the connection
    disconnect(flowConnection, 0, this, 0);
}

void FlowViewerInterface::moveFlowConnection(FlowConnection *flowConnection, int index)
{
    int find;
    if((find=_flowConnections.indexOf(flowConnection))>=0)
    {
        if(index>=_flowConnections.count())
            return;
        _flowConnections.move(find, index);
    }
}

void FlowViewerInterface::changeDataType()
{
    if(_flowConnections.empty())
        return;

    Property *dataTypeProperty = _flowConnections[0]->flow()->assocProperty()->path("datatype");
    if(!dataTypeProperty)
        return;

    _dataType = dataTypeProperty->value().toString();
    emit dataTypeChanged();

    qDebug()<<Q_FUNC_INFO<<dataTypeProperty->value();
}

void FlowViewerInterface::processData(FlowPackage data)
{
    FlowConnection *connection = FlowViewerInterface::objectToFlowConnection(QObject::sender());
    if(!connection)
        return;

    int index = _flowConnections.indexOf(connection);
    if(index==-1)
        return;

    emit dataReceived(index);

    qDebug()<<Q_FUNC_INFO<<data.data().size()<<connection->flow()->name();
}

FlowConnection *FlowViewerInterface::objectToFlowConnection(QObject *object)
{
    return qobject_cast<FlowConnection *>(object);
}

QString FlowViewerInterface::dataType() const
{
    return _dataType;
}
