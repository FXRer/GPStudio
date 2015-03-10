#ifndef SCRIPTENGINE_H
#define SCRIPTENGINE_H

#include <QObject>

#include <QScriptEngine>

#include "propertyclass.h"

class ScriptEngine : public QObject
{
    Q_OBJECT
public:
    explicit ScriptEngine(QObject *parent = 0);
    ~ScriptEngine();

    QScriptEngine *engine();

    void addProperty(Property *property);

    uint evalPropertyMap(const QString &propertyMap, const QString &blockContext);

signals:

public slots:

private:
    QScriptEngine _engine;

    QList<Property *> _properties;
};

#endif // SCRIPTENGINE_H
